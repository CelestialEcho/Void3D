#include "JIT_Render.h"

BOOL JIT_Render::SetCurPos(mathclass::VoidVec2d vec)
{
    coords.X = static_cast<SHORT>(vec.x);
    coords.Y = static_cast<SHORT>(vec.y);
    return SetConsoleCursorPosition(hConsole, coords) ? true : false; 
}

BOOL JIT_Render::addLine(mathclass::VoidVec2d pos1, mathclass::VoidVec2d pos2, char filler = '*')
{
    int dx = abs(pos1.x - pos2.x);
    int dy = abs(pos1.y - pos2.y);

    int sx = (pos1.x < pos2.x) ? 1 : -1;
    int sy = (pos1.y < pos2.y) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        this->SetCurPos(mathclass::VoidVec2d(pos1.x, pos1.y));
        std::cout << filler;         // Печатаем символ

        if (pos1.x == pos2.x && pos1.y == pos2.y)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            pos1.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            pos1.y += sy;
        }
    }
    return true;
}


