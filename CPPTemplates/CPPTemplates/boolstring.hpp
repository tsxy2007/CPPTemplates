#pragma once
#include <string>

class BoolString
{
public:
	BoolString(std::string const& s):
		value(s)
	{}
	template<typename T = std::string>
	T get() const
	{
		return value;
	}
	
private:
	std::string value;
};

template<>
inline bool BoolString::get<bool>() const {
	return value == "true" || value == "1" || value == "on";
}

class SomeCompilerSpecificName
{
public:
	SomeCompilerSpecificName();
	template<typename T1,typename T2>
	auto operator()(T1 x, T2 y) const
	{
		return x + y;
	}
};

SomeCompilerSpecificName::SomeCompilerSpecificName()
{

}
