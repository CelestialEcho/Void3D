#include "../headers/VoidVector3D.h"
#include "../headers/Matrix.h"

int main() {
    // Define the matrix with data
    Matrix seamless_matrix(3, 3, {{1, 2, 3}, 
                                   {4, 5, 6}, 
                                   {7, 8, 9}});
    
    // Define a 3D vector
    VoidVec3d vec3d(1.f, 2.f, 3.f);

    // Multiply vector with matrix
    VoidVec3d result = vec3d * seamless_matrix;

    // Print result
    result.print();

    return 0;
}
