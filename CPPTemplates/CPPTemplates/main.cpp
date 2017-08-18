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
#include "Stack4.hpp"
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

namespace C3
{
    //缺省模版实参
    template <typename T ,typename CONT = vector< T > >
    class Stack
    {
    private:
        CONT mDatas;
    public:
        void Push(const T& item);
        void Pop();
        T    Pop1();
        T Top();
        bool empty() const
        {
            return mDatas.empty();
        }
    };
    
     template <typename T, typename CONT>
    void Stack<T, CONT>::Push(const T& item)
    {
        this->mDatas.push_back(item);
    }
    
    template <typename T, typename CONT>
    void Stack<T, CONT>::Pop()
    {
        if ( empty( ) )
            throw out_of_range("Stack<> pop() : empty stack");
        mDatas.pop_back( );
    }
    template <typename T, typename CONT>
    T Stack<T, CONT>::Pop1()
    {
        if ( empty( ) )
            throw out_of_range("Stack<> pop() : empty stack");
        T elem = mDatas.back();
        mDatas.pop_back();
        return elem;
    }
  template <typename T, typename CONT>
    T Stack<T, CONT>::Top()
    {
        if ( empty( ) )
            throw out_of_range("Stack<> top() : empty stack");
        return mDatas.back();
    }
}

int main(int argc, const char * argv[])
{
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
    
    C3::Stack<int ,deque<int> > stack_d;
    for (int i = 0 ; i<10; i++)
        stack_d.Push(i);
     for (int i = 0 ; i<10; i++)
         cout<<"stack_d pop1 is "<<stack_d.Pop1()<<endl;
    
    
    //第4章 非类型模版参数
    P4::Stack<int, 10> p4Stack;
    for (int i = 0; i<10; i++)
        p4Stack.Push(i);
    p4Stack.Pop();
    for (int i = 0 ; i<p4Stack.Size(); i++)
    {
        cout<<"p4stack["<< i <<"] = "<<p4Stack[i]<<endl;
    }
    
    return 0;
}
