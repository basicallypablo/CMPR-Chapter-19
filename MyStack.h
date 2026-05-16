#pragma once
#include <stdexcept>

using namespace std;

template <class T>
class MyStack
{
private:
    // Node for linked stack
    struct StackNode
    {
        T value;
        StackNode* next;

        StackNode(const T& nodeValue, StackNode* nextNode = nullptr)
        {
            value = nodeValue;
            next = nextNode;
        }
    };

    StackNode* topNode;
    int stackSize;

    void copyFrom(const MyStack<T>& other)
    {
        StackNode* otherCurrent = other.topNode;
        StackNode* newCurrent = nullptr;

        // Copy each node
        while (otherCurrent != nullptr)
        {
            StackNode* newNode = new StackNode(otherCurrent->value);

            if (topNode == nullptr)
            {
                topNode = newNode;
                newCurrent = topNode;
            }
            else
            {
                newCurrent->next = newNode;
                newCurrent = newCurrent->next;
            }

            otherCurrent = otherCurrent->next;
            stackSize++;
        }
    }

public:
    MyStack()
    {
        // Empty stack
        topNode = nullptr;
        stackSize = 0;
    }

    MyStack(const MyStack<T>& other)
    {
        // Copy constructor
        topNode = nullptr;
        stackSize = 0;
        copyFrom(other);
    }

    ~MyStack()
    {
        // Free memory
        clearAll();
    }

    MyStack<T>& operator=(const MyStack<T>& other)
    {
        // Assignment operator
        if (this != &other)
        {
            clearAll();
            copyFrom(other);
        }

        return *this;
    }

    bool isEmpty() const
    {
        // Check if empty
        return topNode == nullptr;
    }

    int size() const
    {
        // Return size
        return stackSize;
    }

    void push(const T& element)
    {
        // Add to top
        topNode = new StackNode(element, topNode);
        stackSize++;
    }

    bool pop(T& poppedElement)
    {
        // Remove from top
        if (isEmpty())
            return false;

        StackNode* temp = topNode;
        poppedElement = temp->value;
        topNode = topNode->next;

        delete temp;
        stackSize--;

        return true;
    }

    bool pop()
    {
        // Remove without returning value
        if (isEmpty())
            return false;

        StackNode* temp = topNode;
        topNode = topNode->next;

        delete temp;
        stackSize--;

        return true;
    }

    bool top(T& topElement) const
    {
        // Get top value
        if (isEmpty())
            return false;

        topElement = topNode->value;
        return true;
    }

    T top() const
    {
        // Return top value
        if (isEmpty())
            throw out_of_range("ERROR: Stack is empty.");

        return topNode->value;
    }

    void clearAll()
    {
        // Remove all nodes
        while (!isEmpty())
            pop();
    }
};
