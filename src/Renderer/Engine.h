#pragma once

#include "../Math/Math.h"

class Engine
{
public:
    Engine() {}
    void addLine(VoidVec2d pos1, VoidVec2d pos2, char border_filler);
    void addRect(VoidVec2d pos1, VoidVec2d pos2, char border_filler); // TODO: char filler = ???
    void addTriangle(VoidVec2d pos1, VoidVec2d pos2, VoidVec3d pos3, char border_filler);
    void addCircle(VoidVec2d pos1, float radius, char border_filler);
    
    void addQuad(VoidVec3d pos1, VoidVec3d pos2, VoidVec3d pos3, VoidVec3d pos4, char border_filler);
    void addPoly(VoidVec3d pos1, VoidVec3d pos2, VoidVec3d pos3, char border_filler);
    void addSphere(VoidVec3d pos1, float radius, char border_filler);  

    void addText(const char* label, VoidVec2d center_pos);
public:
    Matrix projection_matrix;
};
