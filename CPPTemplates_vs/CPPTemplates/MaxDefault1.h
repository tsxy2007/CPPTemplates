#pragma once
#include <stdio.h>
#include <type_traits>

namespace P6
{
	template< typename T1, typename T2, typename RT = std::decay_t< decltype(true ? T1() : T2()) > >
	RT max(T1 a, T2 b) 
	{
		return a > b ? a : b;
	}

}