#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>


class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<float>> data;

    // Конструкторы
    Matrix() : rows(0), cols(0) {}
    Matrix(int rows, int cols, const std::vector<std::vector<float>>& values);
    
    // Методы
    void print() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;
};

class VoidVec2d {
public:
    float x, y;
    
    VoidVec2d() : x(0.0f), y(0.0f) {}
    VoidVec2d(float x, float y) : x(x), y(y) {}
    
    // Операторы
    VoidVec2d operator+(const VoidVec2d& other) const;
    VoidVec2d operator-(const VoidVec2d& other) const;
    VoidVec2d operator*(float scalar) const;
    bool operator==(const VoidVec2d& other) const;
    bool operator!=(const VoidVec2d& other) const;
    void print() const;
};

class VoidVec3d {
public:
    float x, y, z;
    
    VoidVec3d() : x(0.0f), y(0.0f), z(0.0f) {}
    VoidVec3d(float x, float y, float z) : x(x), y(y), z(z) {}
    
    // Операторы
    VoidVec3d operator+(const VoidVec3d& vec) const;
    VoidVec3d operator-(const VoidVec3d& vec) const;
    VoidVec3d operator*(float scalar) const;
    VoidVec3d operator*(const Matrix& mat) const;
    VoidVec3d rotate_x(float theta) const;
    VoidVec3d rotate_y(float theta) const;
    VoidVec3d rotate_z(float theta) const;
    bool operator==(const VoidVec3d& vec) const;
    bool operator!=(const VoidVec3d& vec) const;
    void print() const;
};
