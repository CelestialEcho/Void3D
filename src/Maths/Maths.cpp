#include "Maths.h"

//--------------------------------------------------------------------------------------------
//VoidVec2D

mathclass::VoidVec2d mathclass::VoidVec2d::operator+(const VoidVec2d& other) const
{
    return VoidVec2d(this->x + other.x, this->y + other.y);
}

mathclass::VoidVec2d mathclass::VoidVec2d::operator-(const VoidVec2d& other) const
{
    return VoidVec2d(this->x - other.x, this->y - other.y);
}

mathclass::VoidVec2d mathclass::VoidVec2d::operator*(float scalar) const
{
    return VoidVec2d(this->x * scalar, this->y * scalar);
}

std::ostream& mathclass::operator<<(std::ostream& os, const mathclass::VoidVec2d& vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}



//---------------------------------------------------------------------------------------------
//VoidVec3D

mathclass::VoidVec3d mathclass::VoidVec3d::operator+(const VoidVec3d& other) const
{
    return VoidVec3d(this->x + other.x, this->y + other.y, this->z + other.z);
}

mathclass::VoidVec3d mathclass::VoidVec3d::operator-(const VoidVec3d& other) const
{
    return VoidVec3d(this->x - other.x, this->y - other.y, this->z - other.z);
}

mathclass::VoidVec3d mathclass::VoidVec3d::operator*(float scalar) const
{
    return VoidVec3d(this->x * scalar, this->y * scalar, this->z * scalar);
}

mathclass::VoidVec3d mathclass::VoidVec3d::operator*(const mathclass::VoidVec3d& other) const
{
    return mathclass::VoidVec3d(x * other.x, y * other.y, z * other.z);
}

std::ostream& mathclass::operator<<(std::ostream& os, const mathclass::VoidVec3d& vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}


//--------------------------------------------------------------------------------------------
//Matrix

mathclass::Matrix mathclass::Matrix::operator+(const Matrix& other) const
{
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Matrix dimensions do not match for addition!" << std::endl;
        return *this;  // Return the current matrix, or could throw an exception
    }
    std::vector<std::vector<float>> result(this->rows, std::vector<float>(this->cols));
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    return Matrix(result);
}

mathclass::Matrix mathclass::Matrix::operator-(const Matrix& other) const
{
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Matrix dimensions do not match for subtraction!" << std::endl;
        return *this;  // Return the current matrix, or could throw an exception
    }
    std::vector<std::vector<float>> result(this->rows, std::vector<float>(this->cols));
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result[i][j] = this->matrix[i][j] - other.matrix[i][j];
        }
    }
    return Matrix(result);
}

mathclass::Matrix mathclass::Matrix::operator*(const Matrix& other) const
{
    if (this->cols != other.rows) {
        std::cerr << "Matrix dimensions do not match for multiplication!" << std::endl;
        return *this;  // Return the current matrix, or could throw an exception
    }
    std::vector<std::vector<float>> result(this->rows, std::vector<float>(other.cols, 0));
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < this->cols; ++k) {
                result[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return Matrix(result);
}

mathclass::Matrix mathclass::Matrix::operator*(float scalar) const
{
    std::vector<std::vector<float>> result(this->rows, std::vector<float>(this->cols));
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result[i][j] = this->matrix[i][j] * scalar;
        }
    }
    return Matrix(result);
}

std::ostream& mathclass::operator<<(std::ostream& os, const mathclass::Matrix& matrix)
{
    for (const auto& row : matrix.matrix) {
        for (const auto& elem : row) {
            os << elem << " ";
        }
        os << std::endl;
    }
    return os;
}
//--------------------------------------------------------------------------------------------
//mathfunc namespace defenition
//

float mathfunc::convert2rad(float theta)
{
    return theta * M_PI / 180.f; 
}


//--------------------------------------------------------------------------------------------
//mathconst namespace defenition

mathclass::Matrix mathconst::offset(float x, float y, float z)
{
    return mathclass::Matrix({{1, 0, 0, x},
                              {0, 1, 0, y},
                              {0, 0, 1, z},
                              {0, 0, 0, 1}});
}

mathclass::Matrix mathconst::rotate(float x, float y, float z)
{
    // X-axis
    mathclass::Matrix Rx({
        {1, 0, 0, 0},
        {0, cos(x), -sin(x), 0},
        {0, sin(x), cos(x), 0},
        {0, 0, 0, 1}
    });

    // Y-axis
    mathclass::Matrix Ry({
        {cos(y), 0, sin(y), 0},
        {0, 1, 0, 0},
        {-sin(y), 0, cos(y), 0},
        {0, 0, 0, 1}
    });

    // Z-axis
    mathclass::Matrix Rz({
        {cos(z), -sin(z), 0, 0},
        {sin(z), cos(z), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });

    return Rz * Ry * Rx; // !!! do not change the queue, cuz only this one is correct, in matricies r * v != v * r
}

