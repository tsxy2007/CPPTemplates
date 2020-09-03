#pragma once
template<typename... Elements>
class TypeList
{

};


template <typename List>
class FrontT;
template<typename Head,typename... Tail>
class FrontT<TypeList<Head,Tail...>>
{
public:
	using Type = Head;
};
template<typename List>
using Front = typename FrontT<List>::Type;



template<typename List>
class PopFrontT;
template<typename Head,typename... Tail>
class PopFrontT<TypeList<Head, Tail...>>
{
public:
	using Type = TypeList<Tail...>;
};
template<typename List>
using PopFront = typename PopFrontT<List>::Type;

template<typename List,typename NewElement>
class PushFrontT;


template<typename... Elements,typename NewElement>
class PushFrontT;
template<typename... Elements,typename NewElement>
class PushFrontT<TypeList<Elements...>, NewElement>
{
public:
	using Type = TypeList<NewElement, Elements...>;
};
template<typename List, typename NewElement>
using PushFront = typename PushFrontT<List, NewElement>::Type;