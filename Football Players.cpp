#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct football
{
    string name;
    string position;
    int touchdowns;
    int catches;
    int passingYard;
    int receivingYard;
    int rushingYard;
};

int count = 0;
const int size = 10;

void head();
char menu();
football addPlayer();
void show(football player);
void viewPlayer(football player[size]);
void search(football player[size]);
int finding(football player[size], string search);
void loadData(football player[size]);
string parseData(string line, int field);
void storeData(football player);

main()
{

    football player[size];

    loadData(player);

    while (true)
    {
        system("cls");
        char Option;
        Option = menu();

        if (Option == '1')
        {
            viewPlayer(player);
        }
        else if (Option == '2')
        {
            player[count] = addPlayer();
            char yn;
            cout << " DO YOU WANT SAVE DATA ! (Y/N) : ";
            cin >> yn;
            if ( yn == 'y' || yn == 'Y')
            {
                storeData( player[count]);
                count++;
            }
            
        }
        else if (Option == '3')
        {
            search(player);
        }
        else if (Option == '4')
        {
            break;
        }
    }
}

void head()
{
    cout << "****************************************" << endl;
    cout << "*      Football Players Information    *" << endl;
    cout << "****************************************" << endl;
    cout << "\n";
}

char menu()
{
    char Option;
    head();
    cout << " Menu >> " << endl;
    cout << "________________________________________" << endl;
    cout << "\n";
    cout << " 1. View All Players " << endl;
    cout << " 2. Add Player " << endl;
    cout << " 3. Search " << endl;
    cout << " 4. Exit" << endl;

    cout << "\n Select Your Option.....";
    Option = getche();

    return Option;
}

football addPlayer()
{
    football player;
    system("cls");
    head();
    cout << " Add Player >> " << endl;
    cout << "________________________________________" << endl;
    cout << "\n";
    cout << " PLayer Name : ";

    getline(cin, player.name);
    cout << " Position : ";
    cin >> player.position;
    cout << " Number of Touchdowns : ";
    cin >> player.touchdowns;
    cout << " Number of Catches : ";
    cin >> player.catches;
    cout << " Number of Passing Yards  : ";
    cin >> player.passingYard;
    cout << " Number of Receving Yards : ";
    cin >> player.receivingYard;
    cout << " Number of Rushing Yards : ";
    cin >> player.rushingYard;
    cout << "\n New Player Added Succesfully :)" << endl;
    cout << "\n Press any Key to continue.....";
    getch();
    return player;
}

void viewPlayer(football player[size])
{
    system("cls");
    head();
    cout << " All Players >> " << endl;
    cout << "________________________________________" << endl;
    cout << "\n";
    cout << " Name\t\tPosition\tTouchdowns\tCatches\tPassing Yard\tReceiving Yard\tRushing Yard" << endl;
    cout << "\n";

    for (int idx = 0; idx < count; idx++)
    {
        show(player[idx]);
    }
    cout << "\n Press any Key to continue.....";
    getch();
}

void show(football player)
{
    cout << " " << player.name << "\t\t" << player.position << "\t\t" << player.touchdowns << "\t\t" << player.catches << "\t" << player.passingYard << "\t\t" << player.receivingYard << "\t\t" << player.rushingYard << endl;
}

void search(football player[size])
{
    string search;
    system("cls");
    head();
    cout << " Search Player >> " << endl;
    cout << "________________________________________" << endl;
    cout << "\n";

    cout << " Enter Player Name : ";
    // cin.ignore();
    getline(cin, search);

    int idx = -1;
    idx = finding(player, search);

    getch();

    if (idx > count || idx < 0)
    {
        cout << " Nothing Find :( " << endl;
    }
    else
    {
        cout << " Name\t\tPosition\tTouchdowns\tCatches\tPassing Yard\tReceiving Yard\tRushing Yard" << endl;
        cout << "\n";
        show(player[idx]);
    }

    cout << "\n Press any Key to continue.....";
    getch();
}

int finding(football player[size], string search)
{
    for (int idx = 0; idx < count; idx++)
    {
        if (search == player[idx].name)
        {
            return idx;
        }
    }
    return -1;
}

void loadData(football player[size])
{
    fstream file;
    string line;

    file.open("PlayersData.txt", ios::in);

    while (!file.eof())
    {
        getline(file, line);

        player[count].name = parseData(line, 1);
        player[count].position = parseData(line, 2);
        player[count].touchdowns = stoi(parseData(line, 3));
        player[count].catches = stoi(parseData(line, 4));
        player[count].passingYard = stoi(parseData(line, 5));
        player[count].receivingYard = stoi(parseData(line, 6));
        player[count].rushingYard = stoi(parseData(line, 7));
        count++;
    }

    file.close();
}

string parseData(string line, int field)
{
    string item;
    int comma = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (comma == field)
        {
            item = item + line[i];
        }
    }
    return item;
}

void storeData(football player)
{
    fstream file;

    file.open("PlayersData.txt", ios::app);

    file << "\n";
    file << player.name << ",";
    file << player.position << ",";
    file << player.touchdowns << ",";
    file << player.catches << ",";
    file << player.passingYard << ",";
    file << player.receivingYard << ",";
    file << player.rushingYard << ",";

    file.close();
}