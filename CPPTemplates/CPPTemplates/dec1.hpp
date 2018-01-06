//
//  dec1.hpp
//  CPPTemplates
//
//  Created by 朱同宽 on 2017/8/20.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef dec1_hpp
#define dec1_hpp

#include <stdio.h>
#include <deque>
using namespace std;



namespace P5_4
{
    template <typename T, template <typename ELEM> class CONT = std::deque >
    class Stack {
    private:
		CONT<T> elems;
    public:
        void    push(T const& ) ;// 压入元素
        void    pop(); //弹出元素
        T&      top(); //获取最上层元素
        bool    empty()const ; //是否为空
    };
    
    template <typename T, template <typename ELEM> class CONT >
    void Stack<T,CONT>::push(T const& item)
    {
        elems.push_back(item);
    }
    
    template <typename T, template <typename ELEM> class CONT >
    void Stack<T,CONT>::pop()
    {
        if ( this->empty( ) )
            throw out_of_range("Stack<> pop() : empty stack");
        elems.pop_back();
    }
    
    template <typename T, template <typename ELEM> class CONT >
    T& Stack<T,CONT>::top()
    {
        if ( this->empty( ) )
            throw out_of_range("Stack<> top() : empty stack");
        T t = this->elems.back();
        this->elems.pop_back();
        return t;
    }
    
    template <typename T, template <typename ELEM> class CONT >
    bool Stack<T,CONT>::empty( )const
    {
        return elems.empty();
    }
}


#endif /* dec1_hpp */
