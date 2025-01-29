#include "../headers/VoidVector2D.h"

// Operators
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

VoidVec3d VoidVec2d::to3d() const {
    return VoidVec3d(x, y, 0.0f);
}

VoidVec3d VoidVec2d::operator*(const Matrix& matrix) const {
    VoidVec3d temp_vector = VoidVec3d(x, y, 0.0f);
    return temp_vector * matrix;
}

// Output method
void VoidVec2d::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
