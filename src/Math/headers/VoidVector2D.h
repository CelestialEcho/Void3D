#pragma once
#include <iostream>
#include "VoidVector3D.h"
#include "Matrix.h"

class VoidVec2d {
public:
    float x, y;

    VoidVec2d() : x(0.0f), y(0.0f) {}
    VoidVec2d(float x, float y) : x(x), y(y) {}

    // Operators
    VoidVec2d operator+(const VoidVec2d& other) const;
    VoidVec2d operator-(const VoidVec2d& other) const;
    VoidVec2d operator*(float scalar) const;
    VoidVec3d operator*(const Matrix& matrix) const;
    bool operator==(const VoidVec2d& other) const;
    bool operator!=(const VoidVec2d& other) const;
    VoidVec3d to3d() const;

    // Output method
    void print() const;
};
