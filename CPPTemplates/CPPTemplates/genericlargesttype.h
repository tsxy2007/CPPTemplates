#pragma once

template<typename List,bool Empty = IsEmpty<List>::value>
class LargestTypeT;


template<typename List>
class LargestTypeT<List, false>
{
private:
	using Contender = Front<List>;
	using Best = typename LargestTypeT<PopFront<List>>::Type;
public:
	using Type = IfThenElse<(sizeof(Contender) >= sizeof(Best)), Contender, Best>;
};

template<typename List>
class LargestTypeT<List, true>
{
public:
	using Type = char;
};

template<typename List>
using LargestType = typename LargestTypeT<List>::Type;