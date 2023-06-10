#include "Wgui.h"

// Funciones

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void color(int x)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);
}

void color2(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x | y);
}

void color3(int x, int y, int z)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x | y | z);
}

void color4(int x, int y, int z, int w)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x | y | z | w);
}

void cuadro(int x, int y, int ancho, int alto)
{
    gotoxy(x, y);
    cout << char(201);
    for (int i = 0; i < ancho; i++)
    {
        cout << char(205);
    }
    cout << char(187);
    for (int i = 0; i < alto; i++)
    {
        gotoxy(x, y + i + 1);
        cout << char(186);
        gotoxy(x + ancho + 1, y + i + 1);
        cout << char(186);
    }
    gotoxy(x, y + alto + 1);
    cout << char(200);
    for (int i = 0; i < ancho; i++)
    {
        cout << char(205);
    }
    cout << char(188);
}

void cuadroC(int x, int y, int ancho, int alto, int color)
{
    color2(color, 0);
    cuadro(x, y, ancho, alto);
    color2(15, 0);
}

void linea(int x, int y, int x2, int y2)
{
    int dx, dy, p, incE, incNE, stepx, stepy;
    dx = (x2 - x);
    dy = (y2 - y);
    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    else
    {
        stepy = 1;
    }
    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    else
    {
        stepx = 1;
    }
    x = x - 1;
    y = y - 1;
    gotoxy(x, y);
    if (dx > dy)
    {
        p = 2 * dy - dx;
        incE = 2 * dy;
        incNE = 2 * (dy - dx);
        while (x != x2)
        {
            x = x + stepx;
            if (p < 0)
            {
                p = p + incE;
            }
            else
            {
                y = y + stepy;
                p = p + incNE;
            }
            gotoxy(x, y);
            cout << char(219);
        }
    }
    else
    {
        p = 2 * dx - dy;
        incE = 2 * dx;
        incNE = 2 * (dx - dy);
        while (y != y2)
        {
            y = y + stepy;
            if (p < 0)
            {
                p = p + incE;
            }
            else
            {
                x = x + stepx;
                p = p + incNE;
            }
            gotoxy(x, y);
            cout << char(219);
        }
    }
}

void lineaC(int x, int y, int x2, int y2, int color)
{
    color2(color, 0);
    linea(x, y, x2, y2);
    color2(15, 0);
}

void rectangulo(int x, int y, int ancho, int alto)
{
    gotoxy(x, y);
    cout << char(201);
    for (int i = 0; i < ancho; i++)
    {
        cout << char(205);
    }
    cout << char(187);
    for (int i = 0; i < alto; i++)
    {
        gotoxy(x, y + i + 1);
        cout << char(186);
        gotoxy(x + ancho + 1, y + i + 1);
        cout << char(186);
    }
    gotoxy(x, y + alto + 1);
    cout << char(200);
    for (int i = 0; i < ancho; i++)
    {
        cout << char(205);
    }
    cout << char(188);
}

void rectanguloC(int x, int y, int ancho, int alto, int color)
{
    color2(color, 0);
    rectangulo(x, y, ancho, alto);
    color2(15, 0);
}

void circulo(int x, int y, int radio)
{
    int xc = 0, yc = 0, p = 0;
    xc = 0;
    yc = radio;
    p = 1 - radio;
    do
    {
        gotoxy(x + xc, y + yc);
        cout << char(219);
        gotoxy(x + xc, y - yc);
        cout << char(219);
        gotoxy(x - xc, y + yc);
        cout << char(219);
        gotoxy(x - xc, y - yc);
        cout << char(219);
        gotoxy(x + yc, y + xc);
        cout << char(219);
        gotoxy(x + yc, y - xc);
        cout << char(219);
        gotoxy(x - yc, y + xc);
        cout << char(219);
        gotoxy(x - yc, y - xc);
        cout << char(219);
        if (p < 0)
        {
            p = p + 2 * xc + 3;
        }
        else
        {
            p = p + 2 * (xc - yc) + 5;
            yc = yc - 1;
        }
        xc = xc + 1;
    } while (xc <= yc);
}

void circuloC(int x, int y, int radio, int color)
{
    color2(color, 0);
    circulo(x, y, radio);
    color2(15, 0);
}

void texto(int x, int y, string texto)
{
    gotoxy(x, y);
    cout << texto;
}
