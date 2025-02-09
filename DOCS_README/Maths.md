# Math directory
Here is provided the short documentation for maths in **Void3D**. The full one will be created as soon as the projects *brains* will be created.

## provided classes

 - Matrix struct (Matrix class) (`Maths.h`)
 - VoidVector2D struct (2x1 Vector | VoidVec2d) (`Maths.h`)
 - VoidVectord3D struct (3x1 Vector | VoidVec3d) (`Maths.h`)

### Matricies
Matrix could be defined as "*nested list*" in stupid language or "*a table of numbers, symbols, or expressions, with elements or entries arranged in rows and columns, which is used to represent a mathematical object or property of such an object*" using wikipedia's defenition.

**Some Useful information**
 - If you're going to act with matrixes your self, you should first research how to do it.
    - For example: imagine what we have a matricies R and V -> R * V != V * R 
 - I'm using **Rows-Major** matrix writing system:
    For example: 
    ```
    Matrix 
    / 1 2 3 \   will be written as 
    | 4 5 6 |    --------------->  (1, 2, 3, 4, 5, 6, 7, 8, 9)
    \ 7 8 9 /

    ```
    In Columns-Major system it will be written as:
    ```
    Matrix 
    / 1 2 3 \   will be written as 
    | 4 5 6 |    --------------->  (1, 4, 7, 2, 5, 8, 3, 6, 9)
    \ 7 8 9 /

    ```
 - To create a matrix object using my class you check out **this example**:
    ```C++
    #include "Maths.h"
    #include <iostream>


    mathclass::Matrix my_matrix({{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9});


    std::cout << my_matrix << std::endl;
    /*
    output:

    1 2 3
    4 5 6
    7 8 9

    */
    ```

 - To rotate a matrix you have to multiply your vector (cuz it's also matrix) or matrix using `mathconst::rotate(float x, float y, float z)`, where x y z is a **radians**.
    - To convert angles to radians you could use `mathfunc::convert2rad(float theta)` where theta is you angles.
    - Here is the example:
        ```C++
        #include "Maths.h"
        #include <iostream>

        float angles = 180.f;
        float radians = mathfunc::convert2rad(angles);

        std::cout << angles << std::endl;
        std::cout << radians << std::endl;

        /*
        output:

        180.0
        3.14159
        */
        
        ```

- 




    
