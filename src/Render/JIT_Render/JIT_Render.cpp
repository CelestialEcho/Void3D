#include "JIT_Render.h"

BOOL JIT_Render::SetCurPos(mathclass::VoidVec2d vec)
{
    coords.X = static_cast<SHORT>(vec.x);
    coords.Y = static_cast<SHORT>(vec.y);
    return SetConsoleCursorPosition(hConsole, coords) ? true : false; 
}

BOOL JIT_Render::addLine(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler)
{
    int dx = abs(pos1.x - pos2.x);
    int dy = abs(pos1.y - pos2.y);

    int sx = (pos1.x < pos2.x) ? 1 : -1;
    int sy = (pos1.y < pos2.y) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        this->SetCurPos(mathclass::VoidVec2d(pos1.x, pos1.y));
        std::cout << filler;
        if (pos1.x == pos2.x && pos1.y == pos2.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy;  pos1.x += sx; }
        if (e2 < dx) { err += dx; pos1.y += sy; }
    }
    return true;
}

BOOL JIT_Render::addRect(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler)
{
    bool side1 = addLine(pos1, mathclass::VoidVec2d(pos2.x, pos1.y), filler);
    bool side2 = addLine(mathclass::VoidVec2d(pos2.x, pos1.y), pos2, filler);
    bool side3 = addLine(pos2, mathclass::VoidVec2d(pos1.x, pos2.y), filler);
    bool side4 = addLine(mathclass::VoidVec2d(pos1.x, pos2.y), pos1, filler);

    return (side1 && side2 && side3 && side4);
}

mathclass::VoidVec2d winSize() // will return (-1, -1) if there is an error
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return mathclass::VoidVec2d(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    }
//                                x     y
    return mathclass::VoidVec2d(-1.f, -1.f);
}

BOOL JIT_Render::addEllipse(mathclass::VoidVec2d pos, mathclass::VoidVec2d size, float radius_minor, float radius_major)
{
    
}



