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
#include <list>
#include <forward_list>
#include <sstream>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include "Stack4.hpp"
#include "Stack5.hpp"
#include "Dev3.h"
#include "dec1.hpp"
#include "TestVector.hpp"
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
#define ARRAY_SIZE 500000


int compare_int(const void * ele1, const void * ele2)
{
    return *(int*)ele1 - *(int*)ele2;
}
namespace JJ02
{
    //    void test_function(long& value);
    int find(const void * a, const void * b)
    {
        string as = *(string*)a;
        string bs = *(string*)b;
        return as.compare(bs);
    }
    void test_function(long& value)
    {
        vector<string> c ;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0 ; i<value; i++) {
            try {
                snprintf(buf, 10, "%d",rand());
                c.push_back(string(buf));
            } catch (exception& p) {
                cout<<"i = "<<i<<p.what()<<endl;
                abort();
            }
        }
        cout<<"c push_back millis = "<<clock() - timeStart <<endl;
        cout<<"c size = "<<c.size()<<endl;
        cout<<"c capacity = "<<c.capacity()<<endl;
        cout<<"c data = "<<c.data()<<endl;
        
        timeStart = clock();
        snprintf(buf, 10, "%d",rand());
        string target(buf);
        auto pItem = std::find(c.begin(), c.end(), target );
        cout<<"pItem = "<<*pItem<<endl;
        cout<<"::find millis = "<<clock() - timeStart <<endl;
        
        timeStart = clock();
        sort(c.begin(), c.end());
        string* pItem1 = (string*)bsearch(&target, c.data(), c.size(), sizeof(string),find );
        cout<<"bsearch millis = "<<clock() - timeStart <<endl;
    }
}

namespace JJ03
{
    void test_function(long &value)
    {
        list<string> c ;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0 ; i<value; i++) {
            try {
                snprintf(buf, 10, "%d",rand());
                c.push_back(string(buf));
            } catch (exception& p) {
                cout<<"i = "<<i<<p.what()<<endl;
                abort();
            }
        }
        cout<<"c push_back millis = "<<clock() - timeStart <<endl;
        cout<<"c size = "<<c.size()<<endl;
        cout<<"c max size = "<<c.max_size()<<endl;
        
        timeStart = clock();
        snprintf(buf, 10, "%d",rand());
        string target(buf);
        ::find(c.begin(), c.end(), target);
        cout<<"c push_back millis = "<<clock() - timeStart <<endl;
    }
}
namespace JJ04
{
    void test_function(long&vale)
    {
        forward_list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0 ; i<vale ; i++)
        {
            try
            {
                snprintf(buf, 10, "%d",rand());
                c.push_front(string(buf));
            }
            catch (exception& p)
            {
                cout<<"i = "<<i<<p.what()<<" bad_block "<<endl;
            }
        }
        cout<<"c push_front millison =  "<< clock() - timeStart <<endl;
    }
}

int main(int argc, const char * argv[])
{
    long i = 1000000;
//    JJ02::test_function(i);
//    JJ03::test_function(i);
    JJ04::test_function(i);
    
//    typedef vector<int,allocator<int>>  VectorInt;
//
//    int ia[6] = {27,210,12,47,109,83};
//    vector<int,allocator<int>> vi(ia,ia+6);
//    cout<<count_if(vi.begin(), vi.end(),[=](int& i){
//        return i> 40;
//    })<<endl;
//
//    for_each( vi.begin(), vi.end(), [](int& i){
////        i*=2;
//        cout<<"i = "<<i<<endl;
//    });
//
//    for (auto& ele : vi)
//    {
//        cout<< "ele = " <<ele<<endl;
//    }
//    array<int, ARRAY_SIZE> array_int;
//
//    clock_t timeStart = clock();
//
//    for (int i = 0; i<ARRAY_SIZE; i++)
//    {
//        array_int[i] = rand();
//    }
//
//    cout<<"milli-seconds : "<<(clock() - timeStart)<<endl;
//    timeStart = clock();
//    qsort(array_int.data(), ARRAY_SIZE, sizeof(int),compare_int);
//    cout<<"qsort milli-seconds : "<<(clock() - timeStart)<<endl;
//    timeStart = clock();
//    sort(array_int.begin(), array_int.end(), [=](int& item1 , int& item2){
//        return item1 > item2;
//    });
//    cout<<"sort milli-seconds : "<<(clock() - timeStart)<<endl;
//    timeStart = clock();
//    search(array_int.begin(), array_int.end());
    
	//Test ( );
//    // 第一章
//    cout << "max is : "<< c2_1::max(1, 2)<<endl;
////     cout << "max is : "<< c2_1::max(3.1, 2)<<endl;
//     cout << "max is : "<< c2_1::max<double>(3, 3.1)<<endl;
//
//    // 第二章
//    C3::Stack<int> stack ;
//    for (int i = 0 ; i<10; i++)
//    {
//        stack.Push(i);
//    }
//
//    while (!stack.empty())
//    {
//        int a = stack.Pop1();
//        cout<<"stack pop1 is = " << a <<endl;
//    }
//    //第三章
//    C3::Stack<int ,deque<int> > stack_d;
//    for (int i = 0 ; i<10; i++)
//        stack_d.Push(i);
//     for (int i = 0 ; i<10; i++)
//         cout<<"stack_d pop1 is "<<stack_d.Pop1()<<endl;
//
//     C3::Stack<std::string> csstack;
//
//     for (size_t i = 0; i < 10; i++)
//     {
//         std::string ele = "test" + to_string(i);
//         csstack.push (ele);
//     }
//
//     while (!csstack.empty())
//     {
//         const std::string ele = csstack.top ();
//         cout << ele.c_str() << endl;
//         csstack.pop ();
//     }
//     {
//         int a = 1, b = 2;
//         int *a1 = &a, *b1 = &b;
//         C3_1::A<int*, int*> C3_1_a;
//         C3_1_a.function (a1, b1);
//
//         C3_1::A<int&, int&> C3_1_b;
//         C3_1_b.function (a, b);
//     }
//
//
//    //第4章 非类型模版参数
//    P4::Stack<int, 10> p4Stack;
//    for (int i = 0; i<10; i++)
//        p4Stack.Push(i);
//    p4Stack.Pop();
//    for (int i = 0 ; i<p4Stack.Size(); i++)
//    {
//        cout<<"p4stack["<< i <<"] = "<<p4Stack[i]<<endl;
//    }
//
//    while ( !csstack.empty() )
//    {
//        const std::string& ele = csstack.top ();
//        cout <<"stack 3_string "<< ele.c_str() << endl;
//        csstack.pop ();
//    }
//
//    //第5章
//    P5::Derived5<int> d5;
//    d5.foo();
//
//    P5::Stack5<int> p5s;
//    for (int i =0 ; i<10; i++)
//    {
//        p5s.Push( i );
//    }
//
//    P5::Stack5<int> p5s_t = p5s;
//    p5s_t.print();
//
//    P5_1::Stack<int> intStack;
//    P5_1::Stack<float> floatStack;
//
//    intStack.push (1);
//    floatStack = intStack;
//
//    while (!floatStack.empty())
//    {
//        cout << "floatStack item = " << floatStack.top () << endl;
//        floatStack.pop ();
//    }
//
			
	
    
	system ( "PAUSE " );
    return 0;
}
