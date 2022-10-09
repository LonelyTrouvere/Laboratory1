#include "Geometry.h"

std::pair<double, double> &Figure::operator[](int i) {
    return figure[i];
}

void Figure::push_back(std::pair<double, double> data) {

    for (int i=0; i<figure.size(); i++)
        if (data == figure[i])
            return;
    figure.push_back(data);
}

double Figure::distance(std::pair<double, double> a, std::pair<double, double> b) {
    double ans = sqrt((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
    return ans;
}

double Figure::angle(std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c) {
    double x1 = b.first - a.first;
    double y1 = b.second - a.second;
    double x2 = b.first - c.first;
    double y2 = b.second - c.second;

    double  scalar = x1*x2 + y1*y2;
    double d1 = distance(a,b);
    double d2 = distance(b,c);

    double ans = acos(scalar/(d1*d2));

    return ans;
}

double Figure::perimeter() {
    double ans = 0;
    for (int i = 0; i<figure.size()-1; i++) {
        ans += distance(figure[i], figure[i + 1]);
    }
    ans+= distance(figure[0], figure[figure.size()-1]);
    return ans;
}

double Figure::area() {
    double ans = 0;

    for (int i=0; i<figure.size()-1; i++)
    {
        ans += figure[i].first*figure[i+1].second - figure[i].second*figure[i+1].first;
    }

    ans += figure[figure.size()-1].first*figure[0].second - figure[figure.size()-1].second*figure[0].first;

    return fabs(ans)/2;

}

int Figure::size() {
    return figure.size();
}

bool Figure::isRegular() {

    double side = distance(figure[0], figure[figure.size()-1]);

    for (int i=0; i<figure.size()-1; i++)
    {
        double x = distance(figure[i], figure[i+1]);
        if (x!=side)
            return false;
    }

    double inangle = angle(figure[figure.size()-1], figure[0], figure[1]);

    for (int i=1; i<figure.size()-1; i++)
    {
        double x = angle(figure[i-1], figure[i], figure[i+1]);
        if (x!=inangle)
            return false;
    }

    return true;
}

bool Figure::isIsosceles() {
    return Triangle::isosceles(figure);
}

/// TRIANGLE CLASS
bool Triangle::isosceles(ArrayList<std::pair<double, double>> f) {
    if (f.size() != 3) return false;
    double a = Figure::distance(f[0], f[1]),
    b = Figure::distance(f[1], f[2]),
    c = Figure::distance(f[0], f[2]);

    if (a == b || b == c || a == c)
        return true;
    else
        return false;
}

int Triangle::angleInfo(ArrayList<std::pair<double, double>> f) {

}