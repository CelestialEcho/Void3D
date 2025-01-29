#pragma once
#include <iostream>
#include "Matrix.h"
#include "VoidVector2D.h"

class VoidVec3d {
public:
    float x, y, z;

    VoidVec3d() : x(0.0f), y(0.0f), z(0.0f) {}
    VoidVec3d(float x, float y, float z) : x(x), y(y), z(z) {}

    // Operators
    VoidVec3d operator+(const VoidVec3d& vec) const;
    VoidVec3d operator-(const VoidVec3d& vec) const;
    VoidVec3d operator*(float scalar) const;
    VoidVec3d operator*(const Matrix& mat) const;
    bool operator==(const VoidVec3d& vec) const;
    bool operator!=(const VoidVec3d& vec) const;

    // Output methods
    VoidVec2d to2d() const;
    void print() const;
};
