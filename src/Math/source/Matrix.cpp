#include "../headers/Matrix.h"

// Constructor to initialize matrix directly
Matrix::Matrix(int rows, int cols, const std::vector<std::vector<float>>& values) : rows(rows), cols(cols) {
    if (values.size() != rows || values[0].size() != cols) {
        throw std::invalid_argument("Matrix dimensions do not match the input values.");
    }
    data = values;
}

// Methods
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }
    Matrix result(rows, cols, data); // Temporary matrix for result
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions must match for multiplication.");
    }
    Matrix result(rows, other.cols, std::vector<std::vector<float>>(rows, std::vector<float>(other.cols, 0.0f)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows, std::vector<std::vector<float>>(cols, std::vector<float>(rows, 0.0f)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}
