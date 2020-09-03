#pragma once

#include <array>
#include <cassert>

namespace AUTO
{
	template<typename T, auto MaxSize>
	class Stack
	{
	public:
		using size_type = decltype(MaxSize);
	private:
		std::array<T, MaxSize> elems;
		size_type numElems;
	public:
		Stack();
		void push(T const& elem);
		void pop();
		T const& top()const;
		bool empty()const 
		{
			return numElems == 0;
		}
		auto size() const
		{
			return numElems;
		}
	};

	template<typename T, auto MaxSize>
	T const& Stack<T, MaxSize>::top() const
	{
		assert(!elems.empty());
		return elems[numElems - 1];
	}

	template<typename T, auto MaxSize>
	void Stack<T, MaxSize>::pop()
	{
		assert(!elems.empty());
		--numElems;
	}

	template<typename T, auto MaxSize>
	void Stack<T, MaxSize>::push(T const& elem)
	{
		assert(numElems < MaxSize);
		elems[numElems] = elem;
		numElems++;
	}

	template<typename T, auto MaxSize>
	Stack<T, MaxSize>::Stack()
		:numElems(0)
	{

	}


}
 