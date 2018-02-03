#pragma once


#include <stdio.h>
using namespace std;
namespace C3
{
	//缺省模版实参
	template <typename T, typename CONT = vector< T > >
	class Stack
	{
	private:
		CONT mDatas;
	public:
		void Push (const T& item);
		void Pop ();
		T    Pop1 ();
		T Top ();
		bool empty () const
		{
			return mDatas.empty ();
		}
	};

	template <typename T, typename CONT>
	void Stack<T, CONT>::Push (const T& item)
	{
		this->mDatas.push_back (item);
	}

	template <typename T, typename CONT>
	void Stack<T, CONT>::Pop ()
	{
		if (empty ())
			throw out_of_range ("Stack<> pop() : empty stack");
		mDatas.pop_back ();
	}
	template <typename T, typename CONT>
	T Stack<T, CONT>::Pop1 ()
	{
		if (empty ())
			throw out_of_range ("Stack<> pop() : empty stack");
		T elem = mDatas.back ();
		mDatas.pop_back ();
		return elem;
	}
	template <typename T, typename CONT>
	T Stack<T, CONT>::Top ()
	{
		if (empty ())
			throw out_of_range ("Stack<> top() : empty stack");
		return mDatas.back ();
	}


	template<>
	class Stack<std::string>
	{
	private:
		std::deque<std::string> elems;
	public:
		void push (std::string const &);
		void pop ();
		std::string top ()const;
		bool empty ()const {
			return elems.empty ();
		}
	};

	void Stack<std::string>::push (std::string const& elem)
	{
		elems.push_back (elem);
	}

	void Stack<std::string>::pop ()
	{
		if (empty ())
		{
			throw out_of_range ("is already empty!");
		}
		elems.pop_back ();
	}
	std::string Stack<std::string>::top ()const
	{
		if ( empty() )
		{
			throw out_of_range ("is already empty!");
		}
		std::string ele = elems.back ();
		return ele;
	}

}

namespace C3_1
{
	/*
	偏特化
	*/
	template <class T1 , class T2>
	class A
	{
	public:
		void function (T1 Value1, T2 Value2)
		{
			cout << "Value1 = " << Value1 << endl;
			cout << "Value2 = " << Value2 << endl;
		}
	};
	template<typename T>
	class A<int, T>
	{
	public:
		void function (int value1, T value2)
		{
			cout << "Value1 = " << value1  << endl;
			cout << "Value2 = " << value2 << endl;
		}
	};

	//绝对类型特化
	template<>
	class A<int , int>
	{
	public:
		void function (int value1, int value2)
		{
			cout << "Value1 = " << value1 << endl;
			cout << "Value2 = " << value2 << endl;
		}
	};
	// 引用/指针类型特化
	template<typename T1 , typename T2>
	class A<T1* ,T2*>
	{
	public:
		void function (T1* value1, T2* value2)
		{
			cout << "Value1 = " << *value1 << endl;
			cout << "Value2 = " << *value2 << endl;
		}

	};

	template<typename T1, typename T2>
	class A<T1&, T2&>
	{
	public:
		void function (T1& value1 ,T2& value2)
		{
			cout << "Value1 = " << value1 << endl;
			cout << "Value2 = " << value2 << endl;
		}
	};

	// 转化为另外一个模板

	template < class T>
	class Number {
	public:
		T value;
		Number (T v) :value (v) {}

	};
	
	template<typename T1 , typename T2 >
	class A< Number< T1 > , Number< T2 > >
	{
	public:
		void function (Number < T1 > t1, Number< T2 > t2)
		{
			cout << "Value1 = " << t1.value << endl;
			cout << "Value2 = " << t2.value << endl;
		}

	};



}
