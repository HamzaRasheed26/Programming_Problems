#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
//------------Variable Declaration---------//
struct marks
{
    string subject;
    float s_marks;
    marks *m_next;
};
struct student
{
    string name;
    student *next;
    marks *s_next;
};
student *s_head = NULL;
marks *head = NULL;
//------------Function Prototypes---------//
int menu();
void Input();
void addRecord(string name, string subject, float m);
student *getLastRecord(student *s_head);
void display();
void print();
//---------------Main Body---------------//
main()
{
    int option = menu();
    while (true)
    {
        if (option == 1)
        {
            Input();
            cout << endl;
            getch();
            system("cls");
        }
        if (option == 2)
        {
            print();
            cout << endl;
            getch();
            system("cls");
        }
        if(option == 3)
        {
            break;
        }
        option = menu();
        getch();
        system("cls");
    }
}
//---------Functions Definition---------//
int menu()
{
  
    int op;
    cout << endl;
    cout << endl;
    cout << "\t Menu" << endl;
    cout<<"_____________________________________"<<endl;
    cout << endl;
    cout << "\t1. Add Record" << endl;
    cout << "\t2. view Record" << endl;
    cout << "\t3. Exit" << endl;
    cout << endl;
    cout<<"____________________________________"<<endl;
    cout << "Select any option:";
    cin >> op;
    return op;
}
void Input()
{
    string name, subject;
    float mark;
    cout << endl;
    cout << "Enter name of student: ";
    cin >> name;
    cout << "Enter Subject: ";
    cin >> subject;
    cout << "Enter marks: ";
    cin >> mark;
    cout << endl;
    addRecord(name, subject, mark);
}
void addRecord(string name, string subject, float mark)
{
    while (s_head != NULL)
    {
        if (s_head->name == name)
        {
            while (head != NULL)
            {
                marks *m_record = new marks;
                m_record->subject = subject;
                m_record->s_marks = mark;
                m_record->m_next = NULL;
            }
        }
    }
    student *s_record = new student;
    s_record->name = name;
    s_record->s_next = NULL;
    s_record->next = NULL;
    marks *my_record = new marks;
    my_record->subject = subject;
    my_record->s_marks = mark;
    my_record->m_next = NULL;
    if (s_head == NULL)
    {
        s_head = s_record;
    }
    else
    {
        student *temp = getLastRecord(s_head);
        temp->next = s_record;
    }
}
student *getLastRecord(student *s_head)
{
    while (s_head != NULL)
    {
        s_head = s_head->next;
    }
    return s_head;
}
void display(student *temp)
{
    cout << temp->name;
    cout << endl;
    while (temp->s_next != NULL)
    {
        while (head != NULL)
        {
            cout << "Subject:  " << temp->s_next->subject << "\t\t";
            cout << "Marks: " << temp->s_next->s_marks;
            head = head->m_next;
        }
    }
}
void print()
{
    student *myRecord = s_head;
    while (myRecord->next != NULL)
    {
        display(myRecord);
        myRecord = myRecord->next;
    }
}