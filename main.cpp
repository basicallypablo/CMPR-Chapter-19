//Name: Pablo Lopez worked with Kevin Ortiz and Ricardo Salgado
//Date: 05/10/2026
//Description: Chapter 19 Assignments CMPR 121

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "MyStack.h"
#include "MyQueue.h"
#include "input.h"

using namespace std;

// Function prototypes
int menuOption();

void Challenge2();
void Challenge4();
void Challenge9();
void Challenge14();

bool hasBalancedParentheses(const string& text);

int main()
{
    do
    {
        // Display menu and run selected challenge
        switch (menuOption())
        {
        case 0:
            return EXIT_SUCCESS;
        case 2:
            Challenge2();
            break;
        case 4:
            Challenge4();
            break;
        case 9:
            Challenge9();
            break;
        case 14:
            Challenge14();
            break;
        default:
            cout << "\n\tERROR - Invalid option. Please re-enter.\n";
            break;
        }

        cout << "\n";
        system("pause");

    } while (true);
}

int menuOption()
{
    system("cls");

    // Main menu display
    cout << "\n\t CMPR121: Chapter 19 - Stacks and Queues by Pablo Lopez 05/10/2026";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t 2. Dynamic Stack Template";
    cout << "\n\t\t 4. Dynamic Queue Template";
    cout << "\n\t\t 9. File Reverser";
    cout << "\n\t\t14. Balanced Parentheses";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t 0. Exit";
    cout << "\n\t" << string(100, char(205));

    // Validate menu option
    return inputInteger("\n\tOption: ", 0, 14);
}

void Challenge2()
{
    system("cls");

    cout << "\n\t2. Dynamic Stack Template";
    cout << "\n\t" << string(70, char(196)) << "\n";

    // Create integer stack
    MyStack<int> numberStack;

    cout << "\n\tPushing integers onto the stack: 10, 20, 30\n";

    // Push values onto stack
    numberStack.push(10);
    numberStack.push(20);
    numberStack.push(30);

    int topNumber = 0;

    // Display top value
    if (numberStack.top(topNumber))
        cout << "\tCurrent top value: " << topNumber << "\n";

    cout << "\tCurrent stack size: " << numberStack.size() << "\n";
    cout << "\tPopping values in LIFO order: ";

    int poppedNumber = 0;

    // Pop all values
    while (numberStack.pop(poppedNumber))
        cout << poppedNumber << " ";

    cout << "\n\tCurrent stack size: " << numberStack.size() << "\n";

    // Test empty stack
    if (!numberStack.pop(poppedNumber))
        cout << "\tThe stack is empty, so nothing else can be popped.\n";

    // Create string stack
    MyStack<string> wordStack;

    cout << "\n\tPushing strings onto another stack: Red, Green, Blue\n";

    // Push string values
    wordStack.push("Red");
    wordStack.push("Green");
    wordStack.push("Blue");

    string poppedWord = "";

    cout << "\tPopping strings in LIFO order: ";

    // Pop all strings
    while (wordStack.pop(poppedWord))
        cout << poppedWord << " ";

    cout << "\n";
}

void Challenge4()
{
    system("cls");

    cout << "\n\t4. Dynamic Queue Template";
    cout << "\n\t" << string(70, char(196)) << "\n";

    // Create double queue
    MyQueue<double> numberQueue;

    cout << "\n\tEnqueuing doubles into the queue: 12.5, 25.75, 40.25\n";

    // Add values to queue
    numberQueue.enqueue(12.5);
    numberQueue.enqueue(25.75);
    numberQueue.enqueue(40.25);

    double frontValue = 0.0;
    double backValue = 0.0;

    // Display front value
    if (numberQueue.getFront(frontValue))
        cout << "\tFront value: " << frontValue << "\n";

    // Display back value
    if (numberQueue.getBack(backValue))
        cout << "\tBack value: " << backValue << "\n";

    cout << "\tCurrent queue size: " << numberQueue.size() << "\n";
    cout << "\tDequeuing values in FIFO order: ";

    double removedValue = 0.0;

    // Remove all values
    while (numberQueue.dequeue(removedValue))
        cout << removedValue << " ";

    cout << "\n\tCurrent queue size: " << numberQueue.size() << "\n";

    // Test empty queue
    if (!numberQueue.dequeue(removedValue))
        cout << "\tThe queue is empty, so nothing else can be dequeued.\n";

    // Create string queue
    MyQueue<string> wordQueue;

    cout << "\n\tEnqueuing strings into another queue: Hydrogen, Oxygen, Carbon\n";

    // Add strings to queue
    wordQueue.enqueue("Hydrogen");
    wordQueue.enqueue("Oxygen");
    wordQueue.enqueue("Carbon");

    string removedWord = "";

    cout << "\tDequeuing strings in FIFO order: ";

    // Remove all strings
    while (wordQueue.dequeue(removedWord))
        cout << removedWord << " ";

    cout << "\n";
}

void Challenge9()
{
    system("cls");

    cout << "\n\t9. File Reverser";
    cout << "\n\t" << string(70, char(196)) << "\n\n";

    // File names used for this challenge
    string inputFileName = "INPUT.DAT";
    string outputFileName = "OUTPUT.DAT";

    // Open input file
    ifstream inputFile(inputFileName, ios::in | ios::binary);

    if (!inputFile)
    {
        cout << "\tERROR: File, " << inputFileName << " cannot be opened.\n";
        return;
    }

    // Stack stores characters
    MyStack<char> characterStack;

    char character = '\0';

    cout << "\tReading characters from " << inputFileName << " into the stack...\n";
    cout << "\t";

    // Read and display each character
    while (inputFile.get(character))
    {
        characterStack.push(character);
        cout << character;
    }

    inputFile.close();

    // Open output file
    ofstream outputFile(outputFileName, ios::out | ios::binary);

    if (!outputFile)
    {
        cout << "\n\n\tERROR: File, " << outputFileName << " cannot be created.\n";
        return;
    }

    cout << "\n\n\tWriting stack of characters to " << outputFileName << "...\n";
    cout << "\t";

    // Pop, write, and display each character
    while (characterStack.pop(character))
    {
        outputFile.put(character);
        cout << character;
    }

    outputFile.close();

    cout << "\n";
}

void Challenge14()
{
    system("cls");

    cout << "14. Balanced Parentheses\n";
    cout << string(120, char(196)) << "\n\n";

    string text = inputString("Enter a string with parentheses (): ", true);

    if (hasBalancedParentheses(text))
        cout << "\nThe input string has balanced paretheneheses.\n";
    else
        cout << "\nThe input string does not have balanced paretheneheses.\n";
}

bool hasBalancedParentheses(const string& text)
{
    // Stack stores left parentheses
    MyStack<char> parentheses;

    char removedParenthesis = '\0';

    // Check each character
    for (char character : text)
    {
        if (character == '(')
            parentheses.push(character);
        else if (character == ')')
        {
            // No matching left parenthesis
            if (!parentheses.pop(removedParenthesis))
                return false;
        }
    }

    // Balanced if stack is empty
    return parentheses.isEmpty();
}
