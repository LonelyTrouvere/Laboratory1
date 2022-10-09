#include <iostream>
#include "Geometry.h"
int main() {

Figure f;

    f.push_back({0,0});
    f.push_back({0,7});
    f.push_back({7,0});

   std::cout<<f.isIsosceles();

}
