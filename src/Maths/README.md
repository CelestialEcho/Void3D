# Math directory
Here is provided the short documentation for maths in **Void3D**. The full one will be created as soon as the projects *brains* will be created.

## provided classes

 - Matrix class (Matrix class) (`Math.h`)
 - VoidVec2d class (2x1 Vector's class) (`Math.h`)
 - VoidVec3d class (3x1 Vector's class) (`Math.h`)

### Matrixes
Matrix could be defined as "*nested list*" in stupid language or "*a table of numbers, symbols, or expressions, with elements or entries arranged in rows and columns, which is used to represent a mathematical object or property of such an object*" using wikipedia's defenition.

**Some Useful information**
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
    #include "Math.h"

    int main() {
        Matrix matrix_list = Matrix(3, 3, {{1.f, 2.f, 3.f},
                                           {4.f, 5.f, 6.f},
                                           {7.f, 8.f, 9.f}});
        return 0;
    } 
    ```

    
