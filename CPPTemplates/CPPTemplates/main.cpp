//
//  main.cpp
//  CPPTemplates
//
//  Created by fengkai on 2017/8/17.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>  
#include "Stack4.hpp"
#include "Stack5.hpp"
#include "Dev3.h"
#include "dec1.hpp"
using namespace std;
namespace c2_1 // 模版函数
{
    template <typename T>
    const T& max(const T& a , const T& b)
    {
        return a > b ? a : b;
    }
//    template <typename T1 ,typename T2>
//    const T1& max(const T1& a , const T2& b)
//    {
//        return a > b ? a: b;
//    }
    template <typename T , typename T1 ,typename T2>
    const T& max (const T1& a , const T2& b)
    {
        return a > b ? a : b;
    }
}

void GetValue ( char* p ) {
	p = ( char* ) malloc ( 100 );
}
//void Test ( ) {
//	char* str = NULL;
//	GetValue ( str );
//	strcpy ( str , "Perfect" );
//	strcpy ( str + 2 , "World" );
//	printf ( str );
//}
int main(int argc, const char * argv[])
{
	//Test ( );
    // 第一章
    cout << "max is : "<< c2_1::max(1, 2)<<endl;
//     cout << "max is : "<< c2_1::max(3.1, 2)<<endl;
     cout << "max is : "<< c2_1::max<double>(3, 3.1)<<endl;
    
    // 第二章
    C3::Stack<int> stack ;
    for (int i = 0 ; i<10; i++)
    {
        stack.Push(i);
    }
    
    while (!stack.empty())
    {
        int a = stack.Pop1();
        cout<<"stack pop1 is = " << a <<endl;
    }
	//第三章
    C3::Stack<int ,deque<int> > stack_d;
    for (int i = 0 ; i<10; i++)
        stack_d.Push(i);
     for (int i = 0 ; i<10; i++)
         cout<<"stack_d pop1 is "<<stack_d.Pop1()<<endl;

	 C3::Stack<std::string> csstack;
	
	 for (size_t i = 0; i < 10; i++)
	 {
		 std::string ele = "test" + to_string(i);
		 csstack.push (ele);
	 }

	 while (!csstack.empty())
	 {
		 const std::string ele = csstack.top ();
		 cout << ele.c_str() << endl;
		 csstack.pop ();
	 }
	 {
		 int a = 1, b = 2;
		 int *a1 = &a, *b1 = &b;
		 C3_1::A<int*, int*> C3_1_a;
		 C3_1_a.function (a1, b1);
		
		 C3_1::A<int&, int&> C3_1_b;
		 C3_1_b.function (a, b);
	 }
	
    
    //第4章 非类型模版参数
    P4::Stack<int, 10> p4Stack;
    for (int i = 0; i<10; i++)
        p4Stack.Push(i);
    p4Stack.Pop();
    for (int i = 0 ; i<p4Stack.Size(); i++)
    {
        cout<<"p4stack["<< i <<"] = "<<p4Stack[i]<<endl;
    }
    
	while ( !csstack.empty() )
	{
		const std::string& ele = csstack.top ();
		cout <<"stack 3_string "<< ele.c_str() << endl;
		csstack.pop ();
	}

    //第5章
    P5::Derived5<int> d5;
    d5.foo();
    
    P5::Stack5<int> p5s;
    for (int i =0 ; i<10; i++)
    {
        p5s.Push( i );
    }
    
    P5::Stack5<int> p5s_t = p5s;
    p5s_t.print();

	P5_1::Stack<int> intStack;
	P5_1::Stack<float> floatStack;

	intStack.push (1);
	floatStack = intStack;

	while (!floatStack.empty())
	{
		cout << "floatStack item = " << floatStack.top () << endl;
		floatStack.pop ();
	}
		
			
	
    
	system ( "PAUSE " );
    return 0;
}
