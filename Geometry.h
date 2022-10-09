#include <math.h>
#include "ArrayList.h"

class Figure {

private:
    ArrayList<std::pair<double, double>> figure;
protected:
    static double angle (std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c);
    static double distance (std::pair<double, double> a, std::pair<double, double> b);
public:
    std::pair<double, double>& operator[](int i);
    void push_back(std::pair<double, double> data);
    double perimeter();
    double area();
    bool isRegular();
    bool isIsosceles();
    bool isRect();
    bool isAcute();
    bool isObtuse();
    std::pair<double, double> getOrthocenter();
    std::pair<double, double> getMasscenter();
    std::pair<double, double>getIncenter();
    std::pair<double, double>getCircumsus();
    int size();

};

class Triangle: protected Figure
{
    friend class Figure;
private:
    static bool isosceles(Figure f);
    static bool rectangl(Figure f);
    static bool obtuseangl(Figure f);
    static bool acuteangl(Figure f);
    static std::pair<double, double> orthocenter(Figure f);
    static std::pair<double, double> masscenter(Figure f);
    static std::pair<double, double> incenter(Figure f);
    static std::pair<double, double> circumscribedcenter(Figure f);
};

