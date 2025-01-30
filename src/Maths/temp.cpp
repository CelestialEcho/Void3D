#include "Maths.h"
int main() 
{        
    float angles = 180.f;
    float radians = mathfunc::convert2rad(angles);

    std::cout << angles << std::endl;
    std::cout << radians << std::endl;
}

