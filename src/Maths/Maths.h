#pragma once 

#include <vector>
#include <cmath>
#include <iostream>

namespace mathclass 
{
    struct Matrix
    {
        int rows, cols;
        std::vector<std::vector<float>> matrix;

        Matrix(std::vector<std::vector<float>> matrix) : matrix(matrix), rows(matrix.size()), cols(matrix[0].size()) {}
    
        Matrix operator-(const Matrix& other) const;
        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(float scalar) const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); 
    };


    struct VoidVec2d : Matrix
    {
        float x, y;

        VoidVec2d(float x, float y) : Matrix({{x}, {y}}), x(x), y(y) {}

        VoidVec2d operator+(const VoidVec2d& other) const;
        VoidVec2d operator-(const VoidVec2d& other) const;
        VoidVec2d operator*(float scalar) const;
        

        friend std::ostream& operator<<(std::ostream& os, const VoidVec2d& vec);
    };


    struct VoidVec3d : Matrix
    {
        float x, y, z;

        VoidVec3d(float x, float y, float z) : Matrix({{x}, {y}, {z}}), x(x), y(y), z(z) {}

        VoidVec3d operator+(const VoidVec3d& other) const;
        VoidVec3d operator-(const VoidVec3d& other) const;
        VoidVec3d operator*(float scalar) const;
        VoidVec3d operator*(const VoidVec3d& other) const;

        friend std::ostream& operator<<(std::ostream& os, const VoidVec3d& vec);
    };
 
};


namespace mathfunc
{
    float convert2rad(float theta);
};

namespace mathconst 
{
    mathclass::Matrix offset(float x, float y, float z);
    mathclass::Matrix rotate(float x, float y, float z);
};






