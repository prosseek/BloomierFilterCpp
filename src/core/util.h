//
// Created by smcho on 5/30/13.
// Copyright (c) 2013 ___MPC___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __Util_H_
#define __Util_H_

#include <iostream>
#include <list>
namespace bloomier {

class Util {
public:
    template <class T>
    static void addAll(std::vector<T>&, const std::vector<T>);

    // template<class T>
    // void removeAll(std::vector<T>&, const std::vector<T>);

    template <class T1, class T2>
    static void removeAll(std::map<T1, T2>&, const std::vector<T2>);
};
}

#endif //__Util_H_
