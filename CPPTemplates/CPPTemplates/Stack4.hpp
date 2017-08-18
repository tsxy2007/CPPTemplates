//
//  Stack4.hpp
//  CPPTemplates
//
//  Created by fengkai on 2017/8/18.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef Stack4_hpp
#define Stack4_hpp

#include <stdio.h>
using namespace std;

namespace P4
{
    template<typename T , int MAXSIZE>
    class Stack
    {
    private:
        int elems[MAXSIZE]; //数组
        int numOfElems;  //当前元素个数
    public:
        Stack();
        void Push(const T& item );
        void Pop();
        T top() const;
        bool empty() const;
        bool full() const;
        int  Size() const
        {
            return numOfElems;
        }
    public:
        T operator[](const int& index);
    };
    
    template<typename T , int MAXSIZE>
    Stack<T,MAXSIZE>::Stack():numOfElems(0)
    {
        
    }
    template<typename T , int MAXSIZE>
    void Stack<T,MAXSIZE>::Push(const T& item)
    {
        if (full())
            throw out_of_range("Stack<> Push() : full stack");
        elems[numOfElems] = item;
        numOfElems++;
    }
    
    template<typename T , int MAXSIZE>
    void Stack<T,MAXSIZE>::Pop()
    {
        if (numOfElems == 0)
            throw out_of_range("Stack<> Pop() : empty stack");
        numOfElems--;
    }
    
    template<typename T , int MAXSIZE>
    T Stack<T,MAXSIZE>::top() const
    {
        if (numOfElems == 0)
            throw out_of_range("Stack<> top() : empty stack");
        T t = elems[numOfElems-1];
        numOfElems--;
        return t;
    }
    template<typename T , int MAXSIZE>
    bool Stack<T,MAXSIZE>::empty() const
    {
        return numOfElems == 0 ;
    }
    
    template<typename T , int MAXSIZE>
    bool Stack<T,MAXSIZE>::full() const
    {
        return numOfElems == MAXSIZE;
    }
    
    template<typename T , int MAXSIZE>
    T Stack<T,MAXSIZE>::operator[](const int &index)
    {
        if (index >= numOfElems)
            throw out_of_range("Stack<> operator[]() : full stack");
        T t = elems[index];
        return t;
    }
    
}




#endif /* Stack4_hpp */
