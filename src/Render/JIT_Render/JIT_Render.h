#pragma once

#include <vector>
#include <iostream>
#include <Windows.h>


#include "../../Maths/Maths.h"


class JIT_Render
{
public:
    JIT_Render() {}
    mathclass::VoidVec2d size();
    BOOL addLine(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler);
    BOOL addRect(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler);
    BOOL addEllipse(mathclass::VoidVec2d pos, mathclass::VoidVec2d size, float radius_minor, float radius_major);


private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords;
    BOOL SetCurPos(mathclass::VoidVec2d vec);
    
};
