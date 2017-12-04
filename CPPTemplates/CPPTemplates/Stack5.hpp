//
//  Stack5.hpp
//  CPPTemplates
//
//  Created by 朱同宽 on 2017/8/20.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef Stack5_hpp
#define Stack5_hpp

#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;

namespace P5
{

    template<typename T>
    class Stack5
    {
    private:
        vector<T> mElems;
    public:
        Stack5();
        void Push(const T& item);
        void Pop();
        T&   Top() ;
        bool empty() const ;
        template<typename T1>
        Stack5<T>& operator=(Stack5<T1>  const& op1);
        void print();
    public:
        int size()
        {
            return this->mElems.size( );
        }
    };
    
    template <typename T>
    Stack5<T>::Stack5( )
    {
        
    }
    
    template <typename T>
    void Stack5<T>::Push(const T& item)
    {
        this->mElems.push_back(item);
    }
    
    template<typename T>
    void Stack5<T>::Pop()
    {
        if ( this->empty( ) )
            throw out_of_range("Stack<> pop() : empty stack");
        this->mElems.pop_back( );

    }
    
    template<typename T>
    T& Stack5<T>::Top()
    {
        if ( this->empty( ) )
            throw out_of_range("Stack<> Top() : empty stack");
        T t = this->mElems.back();
        this->mElems.pop_back();
        return t;
    }
    
    template<typename T>
    bool Stack5<T>::empty() const
    {
        return this->mElems.empty();
        
    }
    
    template<typename T>
    void Stack5<T>::print()
    {
        for (int i = 0; i<mElems.size(); i++)
        {
            cout<<"mElems["<<i<<"] = "<<mElems[i]<<endl;
        }
    }
    
    template<typename T>
    template<typename T2>
    Stack5<T>& Stack5<T>::operator= (Stack5<T2>  const& op1)
    {
        
        if ( (void*)this == (void*)&op1 )
            return *this;
        
        Stack5<T2> tmp(op1);
        
        this->mElems.clear();
        while ( !tmp.empty( ) )
        {
            this->mElems.push_front( tmp.top( ) );
            tmp.pop( );
        }
        
        return *this;
    }
    
    
    
    
    template<typename T>
    class Test5Base
    {
    public:
        void exit();
    };
    
    template<typename T>
    void Test5Base<T>::exit()
    {
        cout<<"Test5Base exit"<<endl;
    }
    
    template<typename T>
    class Derived5 : public Test5Base<T>
    {
    public:
        void foo()
        {
            this->exit(); //调用父类
        }
        
    };
    
}

#endif /* Stack5_hpp */
