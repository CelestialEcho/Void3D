#pragma once
#include <iostream>
#include <vector>

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<float>> data;

    // Constructor to initialize matrix directly
    Matrix(int rows, int cols, const std::vector<std::vector<float>>& values);

    // Methods
    void print() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;
};
