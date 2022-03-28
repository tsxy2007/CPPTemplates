#pragma once
#include <iostream>
namespace PP_OPERATOR
{
	// error
	template<typename T>
	void print(T arg)
	{
		std::cout << arg << ' '; // print passed argument
	}
	template<typename T, typename... Types>
	void print(T firstArg, Types... args)
	{
		print(firstArg);
		if (sizeof...(args) > 0)
		{ // error if sizeof...(args)==0
			print(args...); // and no print() for no arguments declared
		}
	}
	template<typename... T>
	void printDouble(T const& ... args)
	{
		print(args + args ...);
	}
}