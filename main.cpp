#include <iostream>
#include "Geometry.h"
int main() {

Figure f;

    f.push_back({2,3});
    f.push_back({6,8});
    f.push_back({3,4});

   std::pair<double, double> o = f.getCircumsus();
   std::cout<<o.first<<' '<<o.second;

}
