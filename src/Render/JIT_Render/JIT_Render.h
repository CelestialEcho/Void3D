#pragma once

#include <vector>
#include <iostream>
#include <Windows.h>


#include "../../Maths/Maths.h"


class JIT_Render
{
public:
    BOOL addLine(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler = '*');

private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords;

    BOOL SetCurPos(mathclass::VoidVec2d vec);
};
