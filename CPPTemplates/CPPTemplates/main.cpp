//
//  main.cpp
//  CPPTemplates
//
//  Created by fengkai on 2017/8/17.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include <iostream>
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
int main(int argc, const char * argv[])
{
    cout << "max is : "<< c2_1::max(1, 2)<<endl;
//     cout << "max is : "<< c2_1::max(3.1, 2)<<endl;
     cout << "max is : "<< c2_1::max<double>(3, 3.1)<<endl;
    return 0;
}
