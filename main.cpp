/*
simple 2d engine in console
*/

#include <iostream>
#include <Windows.h>

struct Point2D
{
public:
    short x;
    short y;
};

struct Line2D
{
public:
    Point2D p1;
    Point2D p2;
};

class Renderer
{
    // 2d renderer
public:
    void DrawPoint(Point2D p)
    {
        // draw point using Windows API
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {p.x, p.y});
        std::cout << "X";        
    }

    void DrawLine(Line2D l)
    {
        // draw line
        std::cout << "Line: " << l.p1.x << ", " << l.p1.y << " to " << l.p2.x << ", " << l.p2.y << std::endl;
    }
};

int main (int argc, char *argv[])
{

    // check C++ version
    std::cout << "C++ version: " << __cplusplus << std::endl;


    // Point2D p1;
    // p1.x = 10;
    // p1.y = 10;

    // Point2D p2;
    // p2.x = 20;
    // p2.y = 20;


    // Line2D l1;
    // l1.p1 = p1;
    // l1.p2 = p2;

    // Renderer r;
    // r.DrawPoint(p1);
    // r.DrawLine(l1);

    // system("pause");
    
    return 0;
}