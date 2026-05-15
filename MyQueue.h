#pragma once
#include <list>
using namespace std;

template <class T>
class MyQueue
{
private:
	list<T> container;

public:
	MyQueue()
	{
		container.clear();
	}

	void pushFront(T element)
	{
		container.push_front(element);
	}

	void pushBack(T element)
	{
		container.push_back(element);
	}

	T getFront() const
	{
		return container.front();
	}

	T getBack() const
	{
		return container.back();
	}

	bool isEmpty() const
	{
		return container.empty();
	}

	void popFront()
	{
		if(!isEmpty())
			container.pop_front();
	}

	void popBack()
	{
		if (!isEmpty())
			container.pop_back();
	}

	void clearAll()
	{
		container.clear();
	}
};

