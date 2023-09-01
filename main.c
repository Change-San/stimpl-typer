#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define WIDTH 80
#define HEIGHT 25

void Location(int x, int y);
void clearScreen();
void drawBoard(int counter, int xpos, char* line, char target, char* arrow);
void generateRandomLine(char* line);

int main()
{
    srand(time(NULL));
    int counter = 0;
    int xpos = 0;
    char line[WIDTH];
    char arrow[WIDTH] = {24};
    int i = 1;
    for(i = 1; i < WIDTH; i++)
    {
        arrow[i] = ' ';
    }
    char target;
    char input;
    generateRandomLine(line);
    target = line[0];
    drawBoard(counter, xpos, line, target, arrow);
    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == 27)
            {
                break;  // 若按下Esc键，程序关闭
            }
            if (toupper(input) == target)
            {
                counter++;
                line[xpos] = ' ';
                arrow[xpos] = ' ';
                arrow[xpos+1] = 24;
                if (xpos == WIDTH - 1)
                {
                    generateRandomLine(line);
                    xpos = 0;
                }else{
                    xpos++;
                }
                target = line[xpos];
                drawBoard(counter, xpos, line, target, arrow);
            }
        }
    }
    return 0;
}

void Location(int x, int y)         //坐标定位函数
{
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut,pos);
}

void clearScreen()
{
    system("cls");
}

void drawBoard(int counter, int xpos, char* line, char target, char* arrow)
{
    clearScreen();
    Location(WIDTH/2, HEIGHT/4);
    printf("%d", counter);
    Location(0, HEIGHT/2);
    int i = 0;
    for (i = 0; i < WIDTH; i++)
    {
        printf("%c", line[i]);
    }
    Location(0, HEIGHT/2+1);
    for(i = 0; i < WIDTH; i++)
    {
        printf("%c", arrow[i]);
    }
}

void generateRandomLine(char* line)
{
    for (int i = 0; i < WIDTH; i++)
    {
        line[i] = 'A' + rand() % 26;
    }
}
