#pragma once
#include <vector>
#include <stdexcept>

namespace ZZ01
{
template <typename T>
class Stack
{
public:
	void push(T const& elem);
	void pop();
	T top() const;
	bool empty() const;
private:
	std::vector<T> elems;
};

template <typename T>
T ZZ01::Stack<T>::top() const
{
	if (empty())
	{
		throw std::out_of_range("stack<>::top():empty stack");
	}
	return elems.back();
}

template <typename T>
void ZZ01::Stack<T>::pop()
{
	if (empty())
	{
		throw std::out_of_range("Stack<>::pop() : empty stack");
	}
	elems.pop_back();
}

template <typename T>
bool ZZ01::Stack<T>::empty() const
{
	return elems.empty();
}

template <typename T>
void ZZ01::Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

}