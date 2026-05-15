#pragma once
#include <vector>
using namespace std;

template <class T>
class MyStack
{
private:
	vector<T> container;

public:
	MyStack()
	{
		container.clear();
	}

	bool isEmpty()
	{
		return container.empty();
	}

	void push(T element)
	{
		container.push_back(element);
	}

	void pop()
	{
		if(!isEmpty())
			return container.pop_back();
	}

	T top() const
	{
		return container.at(container.size() - 1);
	}

	void clearAll()
	{
		container.clear();
	}
};

