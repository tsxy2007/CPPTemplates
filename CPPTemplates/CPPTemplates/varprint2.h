#pragma once
#include <iostream>

namespace PP_2
{
	template<typename T>
	void print(T arg)
	{
		std::cout << arg << std::endl;
	}

	template<typename T, typename... Types>
	void print(T firstArg, Types...args)
	{
		print(firstArg);
		print(args...);
	}
}
