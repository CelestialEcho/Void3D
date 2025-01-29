#include "../headers/VoidVector3D.h"

// Operators
VoidVec3d VoidVec3d::operator+(const VoidVec3d& vec) const {
    return VoidVec3d(x + vec.x, y + vec.y, z + vec.z);
}

VoidVec3d VoidVec3d::operator-(const VoidVec3d& vec) const {
    return VoidVec3d(x - vec.x, y - vec.y, z - vec.z);
}

VoidVec3d VoidVec3d::operator*(float scalar) const {
    return VoidVec3d(x * scalar, y * scalar, z * scalar);
}

bool VoidVec3d::operator==(const VoidVec3d& vec) const {
    return (x == vec.x && y == vec.y && z == vec.z);
}

bool VoidVec3d::operator!=(const VoidVec3d& vec) const {
    return !(*this == vec);
}

VoidVec3d VoidVec3d::operator*(const Matrix& mat) const {
    if (mat.cols != 3) {
        throw std::invalid_argument("Matrix must have 3 columns for multiplication with a vector.");
    }

    VoidVec3d result(0, 0, 0);
    for (int i = 0; i < mat.rows; ++i) {
        result.x += mat.data[i][0] * x;
        result.y += mat.data[i][1] * y;
        result.z += mat.data[i][2] * z;
    }

    return result;
}

// Output methods
VoidVec2d VoidVec3d::to2d() const {
    return VoidVec2d(x, y);
}

void VoidVec3d::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
