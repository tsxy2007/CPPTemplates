#pragma once

template<long long N>
struct Fib
{
	enum { Value = Fib<N-1>::Value + Fib<N - 2>::Value };
};
template<>
struct Fib<2>
{
	enum { Value = 1 };
};

template<>
struct Fib<1>
{
	enum { Value = 1 };
};