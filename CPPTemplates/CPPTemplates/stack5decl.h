#pragma once
#include <deque>
namespace stack_5111
{

	template<typename T>
	class Stack
	{
	private:
		std::deque<T> elems;
	public:
		void push(T const&);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return elems.empty();
		}
		template<typename T2>
		Stack& operator=(Stack<T2> const& op)
		{
			Stack<T2> tmp(op);
			elems.clear();
			while (!tmp.empty())
			{
				elems.push_front(tmp.top());
				tmp.pop();
			}
			return *this;
		}
		template<typename> friend class Stack;
	};
	

	template<typename T>
	T const& Stack<T>::top() const
	{
		if (this->empty())
			throw out_of_range("Stack<> Top() : empty stack");
		T t = this->elems.back();
		return t;
	}

	template<typename T>
	void Stack<T>::pop()
	{
		elems.pop_back();
	}

	template<typename T>
	void Stack<T>::push(T const& elem)
	{
		elems.push_front(elem);
	}

}