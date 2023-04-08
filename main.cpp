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

    // void DrawLine(Line2D l)
    // {
    //     // draw line
    //     std::cout << "Line: " << l.p1.x << ", " << l.p1.y << " to " << l.p2.x << ", " << l.p2.y << std::endl;
    // }
};

int main (int argc, char *argv[])
{

    // check C++ version
    // std::cout << "C++ version: " << __cplusplus << std::endl;


    Point2D p1;
    p1.xPos = 10;
    p1.yPos = 10;


    Renderer r;

    while(true)
    {
        r.DrawPoint(p1);

        // char ch = getchar(); this one has to be used with enter
        char ch = getch();
        if (ch == 'w')
        {
            p1.yPos--;
        }
        else if (ch == 's')
        {
            p1.yPos++;
        }
        else if (ch == 'a')
        {
            p1.xPos--;
        }
        else if (ch == 'd')
        {
            p1.xPos++;
        }
        else if (ch == 'q')
        {
            break;
        }

        system("cls");

    }
    r.DrawPoint(p1);
    // r.DrawPoint(p2);
    // r.DrawLine(l1);
    
    return 0;
}