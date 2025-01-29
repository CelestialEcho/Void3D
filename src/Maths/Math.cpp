#include "Math.h"

// Конструктор для Matrix
Matrix::Matrix(int rows, int cols, const std::vector<std::vector<float>>& values) : rows(rows), cols(cols), data(values) {
    if (values.size() != rows || (rows > 0 && values[0].size() != cols)) {
        throw std::invalid_argument("Некорректные размеры матрицы.");
    }
}

// Печать матрицы
void Matrix::print() const {
    for (const auto& row : data) {
        for (float value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц должны совпадать для сложения.");
    }
    Matrix result(rows, cols, data);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] += other.data[i][j];
    return result;
}

// Оператор умножения матриц
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Некорректные размеры матриц для умножения.");
    }
    Matrix result(rows, other.cols, std::vector<std::vector<float>>(rows, std::vector<float>(other.cols, 0.0f)));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

// Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(cols, rows, std::vector<std::vector<float>>(cols, std::vector<float>(rows, 0.0f)));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];
    return result;
}

// Операторы для VoidVec2d
VoidVec2d VoidVec2d::operator+(const VoidVec2d& other) const {
    return VoidVec2d(x + other.x, y + other.y);
}

VoidVec2d VoidVec2d::operator-(const VoidVec2d& other) const {
    return VoidVec2d(x - other.x, y - other.y);
}

VoidVec2d VoidVec2d::operator*(float scalar) const {
    return VoidVec2d(x * scalar, y * scalar);
}

bool VoidVec2d::operator==(const VoidVec2d& other) const {
    return x == other.x && y == other.y;
}

bool VoidVec2d::operator!=(const VoidVec2d& other) const {
    return !(*this == other);
}

void VoidVec2d::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

// Операторы для VoidVec3d
VoidVec3d VoidVec3d::operator+(const VoidVec3d& vec) const {
    return VoidVec3d(x + vec.x, y + vec.y, z + vec.z);
}

VoidVec3d VoidVec3d::operator-(const VoidVec3d& vec) const {
    return VoidVec3d(x - vec.x, y - vec.y, z - vec.z);
}

VoidVec3d VoidVec3d::operator*(float scalar) const {
    return VoidVec3d(x * scalar, y * scalar, z * scalar);
}

VoidVec3d VoidVec3d::operator*(const Matrix& mat) const {
    if (mat.cols != 3) {
        throw std::invalid_argument("Матрица должна иметь 3 столбца для умножения на 3D вектор.");
    }

    return VoidVec3d(
        x * mat.data[0][0] + y * mat.data[0][1] + z * mat.data[0][2],  // Строка 0, все столбцы
        x * mat.data[1][0] + y * mat.data[1][1] + z * mat.data[1][2],  // Строка 1, все столбцы
        x * mat.data[2][0] + y * mat.data[2][1] + z * mat.data[2][2]   // Строка 2, все столбцы
    );
}

bool VoidVec3d::operator==(const VoidVec3d& vec) const {
    return x == vec.x && y == vec.y && z == vec.z;
}

bool VoidVec3d::operator!=(const VoidVec3d& vec) const {
    return !(*this == vec);
}

void VoidVec3d::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
