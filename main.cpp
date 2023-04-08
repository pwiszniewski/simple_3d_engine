/*
simple 2d engine in console
*/

#include <iostream>
#include <conio.h>
#include <Windows.h>

struct Point2D
{
public:
    short xPos;
    short yPos;
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
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {p.xPos, p.yPos});
        std::cout << "X";        
    }

    void DrawLine(Line2D l)
    {
        // using Bresenham's line algorithm
        short x0 = l.p1.xPos;
        short y0 = l.p1.yPos;
        short x1 = l.p2.xPos;
        short y1 = l.p2.yPos;

        short dx = abs(x1 - x0);
        short dy = abs(y1 - y0);
        short sx = x0 < x1 ? 1 : -1;
        short sy = y0 < y1 ? 1 : -1;
        short err = dx - dy;

        while (true)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x0, y0});
            std::cout << "o";
            if (x0 == x1 && y0 == y1) break;
            short e2 = 2 * err;
            if (e2 > -dy) { err -= dy; x0 += sx; }

        }
    }
};

int main (int argc, char *argv[])
{

    // check C++ version
    // std::cout << "C++ version: " << __cplusplus << std::endl;


    Point2D p1;
    p1.xPos = 10;
    p1.yPos = 10;


    Line2D l1;
    l1.p1.xPos = 1;
    l1.p1.yPos = 1;
    l1.p2.xPos = 20;
    l1.p2.yPos = 20;


    Renderer r;

    short xPos = 0;
    short yPos = 0;

    r.DrawLine(l1);

    while (true)
    {
        /* code */
    }
    

    while(true)
    {
        // r.DrawPoint(p1);
        r.DrawLine(l1);

        // char ch = getchar(); this one has to be used with enter
        char ch = getch();
        if (ch == 'w')
        {
            l1.p1.yPos--;
            l1.p2.yPos--;
        }
        else if (ch == 's')
        {
            l1.p1.yPos++;
            l1.p2.yPos++;
        }
        else if (ch == 'a')
        {
            l1.p1.xPos--;
            l1.p2.xPos--;
        }
        else if (ch == 'd')
        {
            l1.p1.xPos++;
            l1.p2.xPos++;
        }
        else if (ch == 'q')
        {
            break;
        }

        system("cls");

    }
    // r.DrawPoint(p1);
    // r.DrawPoint(p2);
    // r.DrawLine(l1);
    
    return 0;
}
