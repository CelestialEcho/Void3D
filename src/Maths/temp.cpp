#include "Math.h"




int main() {
    
    VoidVec3d vector3d(1.f, 2.f, 3.f);
    vector3d.print();
    vector3d.rotate_x(45);
    vector3d.print(); 

    return 0;
}
