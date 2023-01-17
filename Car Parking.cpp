#include <iostream>
#include <conio.h>

using namespace std;

int pre;

void parking_exit(int parking_lot[3][5]);
void moving(int stair, int pos );
void floor(int x, int parking_lot[3][5]);
void takeInput(int parking_lot[][5]);
void Print(int parking_lot[][5]);

main()
{
    int parking_lot[3][5] = {{2, 0, 0, 1, 0},
                             {1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0}};
    takeInput( parking_lot);
    Print(parking_lot);
    parking_exit(parking_lot);
}

void takeInput(int parking_lot[][5])
{
    int a = 2;
    for(int x = 0; x < 3; x++)
    {
        if ( x != 2)
        {
            cout << " For Floor " << a << endl;
        }
        else{
            cout << " For ground floor "<<endl;
        }
        for ( int y = 0; y < 5; y++)
        {
            cout << " Enter the " << y + 1 << " place value : ";
            cin >> parking_lot[x][y];
            cout << endl;
        }
        a--;
    }
}

void Print(int parking_lot[][5])
{
    for ( int x = 0; x< 3; x ++)
    {
         for ( int y = 0; y < 5; y++)
         {
             cout << "\t" << parking_lot[x][y]; 
         }
         cout << endl;
    }
}

void parking_exit(int parking_lot[3][5])
{
    int pos;
    floor(0, parking_lot);
    floor(1, parking_lot);
    if (pre != 4)
    {
        cout << " Move Right : " << 4 - pre;
    }
}

void floor(int x, int parking_lot[3][5])
{
    int stair;
    int position;
    if (x == 1)
    {
        position = pre;
    }
    for (int i = 0; i < 5; i++)
    {
        if (parking_lot[x][i] == 1)
        {

            stair = i;
            pre = i;
        }
        if (parking_lot[x][i] == 2)
        {

            position = i;
        }
    }
    moving(stair, position);
}

void moving(int stair, int pos)
{

    if (pos > stair)
    {
        cout << " Move Left : " << pos - stair << endl;
    }
    else if (pos < stair)
    {
        cout << " Move Right : " << stair - pos << endl;
    }

    cout << " Move Down : 1" << endl;
}