#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>


using namespace std;

struct circle
{
    double radius = {};
    pair<double, double> center;
};

void circlePrint(circle krug)
{
    double circleP = krug.radius * 2 * 3.1415;
    double circleA = krug.radius * 3.1415 * 3.1415;
    cout << "Krug radius: " << krug.radius << endl;
    cout << "Krug center: " << krug.center.first << " " << krug.center.second << endl;
    cout << "Krug perimetr: " << circleP << endl;
    cout << "Krug area: " << circleA << endl;
}

void triangleLenght(double &a, double &b, double &c, vector< pair<double, double> > triangle)
{
    a = sqrt(pow((triangle[1].first - triangle[0].first), 2) + pow((triangle[1].second - triangle[0].second), 2));
    b = sqrt(pow((triangle[2].first - triangle[1].first), 2) + pow((triangle[2].second - triangle[1].second), 2));
    c = sqrt(pow((triangle[0].first - triangle[2].first), 2) + pow((triangle[0].second - triangle[2].second), 2));
}

void trianglePrint(double a, double b, double c)
{
    double triangleP = a + b + c;
    double trianglepol = triangleP / 2;
    double triangleA;
    triangleA = sqrt(trianglepol * (trianglepol - a) * (trianglepol - b) * (trianglepol - c));
    cout << "perimeter: " << triangleP << endl;
    cout << "area: " << triangleA << endl;
}

int main()
{
    string str;
    getline(cin, str);
    string temp = str;
    double a, b, c;

    string fgname = "";

    if (temp.find("((") != temp.npos)
    {
        fgname = temp.substr(0, temp.find("(("));
        temp.erase(0, temp.find("((") + 2);
    }
    if (temp.find("(") != temp.npos)
    {
        fgname = temp.substr(0, temp.find("("));
        temp.erase(0, temp.find("(") + 1);
    }
    if (temp.find("))") != temp.npos)
    {
        temp.erase(temp.find("))"), temp.size());
    }
    if (temp.find(")") != temp.npos)
    {
        temp.erase(temp.find(")"), temp.size());
    }
    int i = 0;
    vector<double> coord;
    stringstream el;

    while (i < temp.size())
    {
        while (i < temp.size() && temp[i] != ',')
        {
            while (i < temp.size() && temp[i] != ' ')
            {
                el << temp[i];
                i++;
            }
            coord.push_back(stod(el.str()));
            el.str().resize(0);
            el.str().clear();
            el.str("");
            i++;
        }
        i++;
    }

    circle krug;

    vector< pair<double, double> > triangle(4);
    if (fgname == "circle")
    {
        krug.radius = coord[2];
        krug.center.first = coord[0];
        krug.center.second = coord[1];
        circlePrint(krug);
    }
    else if (fgname == "triangle")
    {
        triangle[0] = make_pair(coord[0], coord[1]);
        triangle[1] = make_pair(coord[2], coord[3]);
        triangle[2] = make_pair(coord[4], coord[5]);
        triangle[3] = make_pair(coord[6], coord[7]);
        triangleLenght(a, b, c, triangle);
        trianglePrint(a, b, c);
    }

}


