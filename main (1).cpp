#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "input.h"

using namespace std;

int menuOption();

void Challenge2();
void Challenge4();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 2: Challenge2(); break;
        case 4: Challenge4(); break;
        //case 9: Challenge9(); break;
        //case 14: Challenge14(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;

}

int menuOption()
{
    system("cls");

    cout << "\n\tCMPR 121 - Chapter 19 Stacks and Queues by Diana Contreras";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t 2. Dynamic Stack Template";
    cout << "\n\t\t 4. Dynamic Queue Template";
    cout << "\n\t\t 9. ";
    cout << "\n\t\t14. ";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0. Exit";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\tOption: ", 0, 14);

}

void Challenge2()
{
    MyStack<string> test;

    test.push("Nicholas Quach");
    test.push("John Doe");

    cout << "\n\tTop: " << test.top();

    test.pop();
    test.pop();
    test.pop();

    test.clearAll();
}

void Challenge4()
{
    MyQueue<double> test;

    test.pushBack(666.6);
    test.pushBack(12.3);
    test.pushFront(15.23);

    cout << "\n\tFront: " << test.getFront();
    cout << "\n\tBack: " << test.getBack();

    test.popBack();
    test.popBack();
    test.popBack();
    test.popBack();
    test.popFront();
    test.popFront();
    test.popFront();

    test.clearAll();
}