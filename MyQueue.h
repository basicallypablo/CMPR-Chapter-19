#pragma once
#include <stdexcept>

using namespace std;

template <class T>
class MyQueue
{
private:
    // Node for linked queue
    struct QueueNode
    {
        T value;
        QueueNode* next;

        QueueNode(const T& nodeValue)
        {
            value = nodeValue;
            next = nullptr;
        }
    };

    QueueNode* frontNode;
    QueueNode* rearNode;
    int queueSize;

    void copyFrom(const MyQueue<T>& other)
    {
        QueueNode* current = other.frontNode;

        // Copy each node
        while (current != nullptr)
        {
            enqueue(current->value);
            current = current->next;
        }
    }

public:
    MyQueue()
    {
        // Empty queue
        frontNode = nullptr;
        rearNode = nullptr;
        queueSize = 0;
    }

    MyQueue(const MyQueue<T>& other)
    {
        // Copy constructor
        frontNode = nullptr;
        rearNode = nullptr;
        queueSize = 0;
        copyFrom(other);
    }

    ~MyQueue()
    {
        // Free memory
        clearAll();
    }

    MyQueue<T>& operator=(const MyQueue<T>& other)
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
        return frontNode == nullptr;
    }

    int size() const
    {
        // Return size
        return queueSize;
    }

    void enqueue(const T& element)
    {
        // Add to back
        QueueNode* newNode = new QueueNode(element);

        if (isEmpty())
        {
            frontNode = newNode;
            rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        queueSize++;
    }

    bool dequeue(T& removedElement)
    {
        // Remove from front
        if (isEmpty())
            return false;

        QueueNode* temp = frontNode;
        removedElement = temp->value;
        frontNode = frontNode->next;

        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
        queueSize--;

        return true;
    }

    bool dequeue()
    {
        // Remove without returning value
        if (isEmpty())
            return false;

        QueueNode* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
        queueSize--;

        return true;
    }

    bool getFront(T& frontElement) const
    {
        // Get front value
        if (isEmpty())
            return false;

        frontElement = frontNode->value;
        return true;
    }

    bool getBack(T& backElement) const
    {
        // Get back value
        if (isEmpty())
            return false;

        backElement = rearNode->value;
        return true;
    }

    T getFront() const
    {
        // Return front value
        if (isEmpty())
            throw out_of_range("ERROR: Queue is empty.");

        return frontNode->value;
    }

    T getBack() const
    {
        // Return back value
        if (isEmpty())
            throw out_of_range("ERROR: Queue is empty.");

        return rearNode->value;
    }

    void clearAll()
    {
        // Remove all nodes
        while (!isEmpty())
            dequeue();
    }

    void pushBack(const T& element)
    {
        // Old name for enqueue
        enqueue(element);
    }

    bool popFront()
    {
        // Old name for dequeue
        return dequeue();
    }

    void pushFront(const T& element)
    {
        // Add to front
        QueueNode* newNode = new QueueNode(element);

        if (isEmpty())
        {
            frontNode = newNode;
            rearNode = newNode;
        }
        else
        {
            newNode->next = frontNode;
            frontNode = newNode;
        }

        queueSize++;
    }

    bool popBack()
    {
        // Remove from back
        if (isEmpty())
            return false;

        if (frontNode == rearNode)
        {
            delete frontNode;
            frontNode = nullptr;
            rearNode = nullptr;
            queueSize = 0;
            return true;
        }

        QueueNode* current = frontNode;

        while (current->next != rearNode)
            current = current->next;

        delete rearNode;
        rearNode = current;
        rearNode->next = nullptr;
        queueSize--;

        return true;
    }
};
