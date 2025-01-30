#include "Maths.h"
#include <iostream>

int main()
{
    
    mathclass::Matrix my_matrix({{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}});


    std::cout << my_matrix << std::endl;

    return 0;
}

