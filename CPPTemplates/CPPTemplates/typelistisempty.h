#pragma once

template<typename List>
class IsEmpty
{
public:
	static constexpr bool value = false;
};

template<>
class IsEmpty<TypeList<>>
{
public:
	static constexpr bool value = true;
};