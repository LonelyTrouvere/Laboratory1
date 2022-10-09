#include "cmath"
#include "ArrayList.h"

class Triangle
{
    friend class Figure;
private:
    static bool isosceles(ArrayList<std::pair<double, double>> f);
    static int angleInfo (ArrayList<std::pair<double, double>> f);
};

class Figure {

private:
    ArrayList<std::pair<double, double>> figure;

    static double angle (std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c);

public:
    static double distance (std::pair<double, double> a, std::pair<double, double> b);
    std::pair<double, double>& operator[](int i);
    void push_back(std::pair<double, double> data);
    double perimeter();
    double area();
    bool isRegular();
    bool isIsosceles();
    int size();

};

