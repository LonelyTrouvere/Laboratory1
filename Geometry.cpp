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
    return Triangle::isosceles(*this);
}

bool Figure::isRect() {
    return Triangle::rectangl(*this);
}

bool Figure::isAcute() {
    return Triangle::acuteangl(*this);
}

bool Figure::isObtuse() {
    return Triangle::obtuseangl(*this);
}

std::pair<double, double> Figure::getOrthocenter() {
    return Triangle::orthocenter(*this);
}

std::pair<double, double> Figure::getMasscenter() {
    return Triangle::masscenter(*this);
}

std::pair<double, double> Figure::getIncenter() {
    return Triangle::incenter(*this);
}

std::pair<double, double> Figure::getCircumsus() {
    return Triangle::circumscribedcenter(*this);
}

/// TRIANGLE CLASS
bool Triangle::isosceles(Figure f) {
    if (f.size() != 3) return false;
    double a = Figure::distance(f[0], f[1]),
    b = Figure::distance(f[1], f[2]),
    c = Figure::distance(f[0], f[2]);

    if (a == b || b == c || a == c)
        return true;
    else
        return false;
}

bool Triangle::rectangl(Figure f) {

    if (f.size() != 3) return false;

    double phi1 = Figure::angle(f[0], f[1], f[2]),
    phi2 = Figure::angle(f[1], f[2], f[0]),
    phi3 = Figure::angle(f[2], f[0], f[1]);

    const double HALF_PI = M_PI/2;

    if (phi1 == HALF_PI || phi2 == HALF_PI || phi3 == HALF_PI)
        return true;

    return false;
}

bool Triangle::obtuseangl(Figure f) {
    if (f.size() != 3) return false;

    double phi1 = Figure::angle(f[0], f[1], f[2]),
            phi2 = Figure::angle(f[1], f[2], f[0]),
            phi3 = Figure::angle(f[2], f[0], f[1]);

    const double HALF_PI = M_PI/2;

    if (phi1 > HALF_PI || phi2 > HALF_PI || phi3 > HALF_PI)
        return true;

    return false;
}

bool Triangle::acuteangl(Figure f) {
    if (f.size() != 3) return false;

    double phi1 = Figure::angle(f[0], f[1], f[2]),
            phi2 = Figure::angle(f[1], f[2], f[0]),
            phi3 = Figure::angle(f[2], f[0], f[1]);

    const double HALF_PI = M_PI/2;

    if (phi1 < HALF_PI && phi2 < HALF_PI && phi3 < HALF_PI)
        return true;

    return false;
}

std::pair<double, double> Triangle::orthocenter(Figure f) {
    if (Figure::angle(f[0], f[1], f[2]) == M_PI/2) return f[1];
    if (Figure::angle(f[1], f[2], f[0]) == M_PI/2) return f[2];
    if (Figure::angle(f[2], f[0], f[1]) == M_PI/2) return f[0];

    double m3 = -((f[1].first - f[0].first)/(f[1].second - f[0].second)),
    m1 = -((f[1].first - f[2].first)/(f[1].second - f[2].second));

    double x = (m3*f[2].first - f[2].second - m1*f[0].first + f[0].second)/(m3-m1);
    double y = m3*x -m3*f[2].first + f[2].second;

    return {x,y};
}

std::pair<double, double> Triangle::masscenter(Figure f) {

    double c1 = (f[2].second + f[1].second)/2;
    if (c1 - f[0].second == 0)
        return {f[0].first + (2*f[0].first)/3, f[0].second};

    double c2 = (f[0].second + f[1].second)/2;
    if (c2 - f[2].second == 0)
        return {f[2].first + (2*f[0].first)/3, f[2].second};

    double l1 = (f[2].first + f[1].first)/2 - f[0].first,
    m1 = (f[2].second + f[1].second)/2 - f[0].second,
    l2 = (f[0].first + f[1].first)/2 - f[2].first,
    m2 = (f[0].second + f[1].second)/2 - f[2].second;

    double x = (f[0].first*(m1/l1) - f[0].second - f[2].first*(m2/l2) + f[2].second)/(m1/l1 - m2/l2);
    double y = x*(m1/l1) - f[0].first*(m1/l1) + f[0].second;

    return {x,y};
}

std::pair<double, double> Triangle::incenter(Figure f) {
    double a = Figure::distance(f[2], f[1]),
    b = Figure::distance(f[0], f[2]),
    c = Figure::distance(f[1], f[0]),
    p = a+b+c;

    double x = (f[0].first*a + f[1].first*b + f[2].first*c)/p,
    y = (f[0].second*a + f[1].second*b + f[2].second*c)/p;

    return {x,y};
}

std::pair<double, double> Triangle::circumscribedcenter(Figure f) {

    double k = (2*(f[2].second*f[2].second - f[1].second*f[1].second)*(f[1].first-f[0].first) - 2*(f[1].second*f[1].second - f[0].second*f[0].second)*(f[2].first - f[1].first))
            /(4*((f[2].second -f[1].second)*(f[1].first - f[0].first) - (f[1].second - f[0].second)*(f[2].first - f[1].first))),
            h = (f[1].second*f[1].second - f[0].second*f[0].second - k*2*(f[1].second - f[0].second))/(2*(f[1].first - f[0].first));

    return {h,k};
}