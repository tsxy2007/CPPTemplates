#pragma once
#include <type_traits>

namespace P6
{
	template<typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
	RT max(T1 a, T2 b)
	{
		return b < a ? a : b;
	}

	template<typename T1, typename T2, typename RT = std::common_type_t<T1,T2> >
	RT max1(T1 a, T2 b)
	{
		return b < a ? a : b;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
}