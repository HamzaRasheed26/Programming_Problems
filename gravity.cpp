#include <iostream>
#include <windows.h>
using namespace std;
void displayWorld();
void TimeTick(int);
char objects[10][10] = {{'-', '#', '#', '.', '#', '-', '#', '#', '.', '#'},
                       {'#', '-', '-', '#', '-', '#', '.', '#', '-', '#'},
                       {'-', '#', '-', '-', '-', '.', '-', '-', '#', '-'},
                       {'#', '.', '#', '-', '#', '-', '#', '-', '-', '-'},
                       {'#', '-', '.', '-', '-', '#', '-', '-', '#', '-'},
                       {'-', '#', '#', '.', '#', '.', '-', '.', '-', '-'},
                       {'#', '-', '-', '#', '-', '#', '-', '-', '#', '-'},
                       {'-', '#', '-', '-', '-', '-', '#', '#', '.', '-'},
                       {'#', '.', '#', '-', '#', '#', '.', '#', '-', '#'},
                       {'#', '-', '.', '-', '-', '-', '-', '-', '#', '-'}};

bool gravity = true;
int main()
{
    displayWorld();

    while (true)
    {
        if (gravity == true)
        {

            TimeTick(1);
        }
        system("cls");
        displayWorld();
        Sleep(50);
    }

    return 0;
}
void displayWorld()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << objects[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void TimeTick(int ti)
{
    char temp;
    for (int x = 0; x < ti; x++)
    {
        for (int j = 0; j < 10; j++)
        {
            temp = objects[9][j];
            for (int k = 9; k >= 0; k--)
            {
                objects[k + 1][j] = objects[k][j];
            }
            objects[0][j] = temp;
        }
    }
}