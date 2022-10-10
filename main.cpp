#include <iostream>
#include "Geometry.h"
int main() {

Figure f;

    f.push_back({0,0});
    f.push_back({1,5});
    f.push_back({6,9});
    f.push_back({5,-3});

   std::pair<double, double> a = f.diagonalIntersectionPoint();
   std::cout<<a.first<<' '<<a.second;

}
