#pragma once
#include <iostream>

namespace AddSpace
{
	template<typename T>
	class AddSpace
	{
	private:
		T const& ref;
	public:
		AddSpace(T const& r) : ref(r)
		{

		}
		friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s)
		{
			return os << s.ref << " ";
		}
	};

	template<typename... Args>
	void print(Args... args)
	{
		(std::cout << ... << AddSpace(args)) << '\n';
	}
}