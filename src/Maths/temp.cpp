#include "Math.h"

int main() {
    Matrix matrix_list = Matrix(3, 3, {{1.f, 2.f, 3.f},
                                   {4.f, 5.f, 6.f},
                                   {7.f, 8.f, 9.f}}); 

    VoidVec3d vec3d(1.f, 2.f, 3.f); 
    
    VoidVec3d new_vec3d = vec3d * matrix_list;
  
    new_vec3d.print(); 
    return 0;
}
