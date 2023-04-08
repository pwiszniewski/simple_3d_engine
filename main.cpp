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
    
        // float a = float(l.p2.yPos - l.p1.yPos) / (l.p2.xPos - l.p1.xPos);
        // float b = l.p1.yPos - a * l.p1.xPos;

        // auto func = [=](float x, float y) -> float {return x - a * y - b;};

        // for (short x = l.p1.xPos - 1; x <= l.p2.xPos - 1; x++)
        // {
        //     short y = a * x + b;
        //         if (func(x+1, y - 0.5) > 0)
        //         {
        //             SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x+1, y-1});
        //             std::cout << "o";
        //         }
        //         else 
        //         {
        //             SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x+1, y});
        //             std::cout << "o";
        //         // }
        //     }
        // }
        

        // float a = float(l.p2.yPos - l.p1.yPos) / (l.p2.xPos - l.p1.xPos);
        // float b = l.p1.yPos - a * l.p1.xPos;

        // auto func = [=](float x, float y) -> float {return x - a * y - b;};
        // short x = l.p1.xPos;
        // short y = l.p1.yPos;

        // while (x <= l.p2.xPos)
        // {
        //     if (func(x+1, y - 0.5) > 0)
        //     {
        //         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x+1, y-1});
        //         std::cout << "o";
        //     }
        //     else 
        //     {
        //         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x+1, y});
        //         std::cout << "o";
        //     }
        //     x++;
        //     y = a * x + b;
        // }


        // using DDA algorithm
        float dx = l.p2.xPos - l.p1.xPos;
        float dy = l.p2.yPos - l.p1.yPos;

        float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        float xInc = dx / steps;
        float yInc = dy / steps;

        float x = l.p1.xPos;
        float y = l.p1.yPos;

        for (int i = 0; i < steps; i++)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {short(x), short(y)});
            std::cout << "o";
            x += xInc;
            y += yInc;
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
    l1.p1.xPos = 0;
    l1.p1.yPos = 0;
    l1.p2.xPos = 20;
    l1.p2.yPos = 10;


    Renderer r;

    short xPos = 0;
    short yPos = 0;

    r.DrawLine(l1);

    // while (true)
    // {
    //     /* code */
    // }
    

    while(true)
    {
        // r.DrawPoint(p1);
        r.DrawLine(l1);

        // char ch = getchar(); this one has to be used with enter
        char ch = getch();
        if (ch == 'w')
        {
            // l1.p1.yPos--;
            l1.p2.yPos--;
        }
        else if (ch == 's')
        {
            // l1.p1.yPos++;
            l1.p2.yPos++;
        }
        else if (ch == 'a')
        {
            // l1.p1.xPos--;
            l1.p2.xPos--;
        }
        else if (ch == 'd')
        {
            // l1.p1.xPos++;
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
