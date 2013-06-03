//
// Created by smcho on 5/30/13.
// Copyright (c) 2013 ___MPC___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//

#include <vector>
#include <map>
#include <string>
#include <algorithm>    // std::find
#include "Util.h"

namespace bloomier {

template <class T>
void Util::addAll(std::vector<T>& aList, const std::vector<T> bList)
{
    // copy all the elements in bList list into aList
    for (auto it = bList.begin(); it != bList.end(); ++it)
    {
        aList.push_back(*it);
    }
}
// specialization
template void Util::addAll<int>(std::vector<int>&, const std::vector<int>);

/**
* Remove all the elements in bList from aList
*/
// template <class T>
// void removeAll(std::vector<T>& aList, const std::vector<T> bList)
// {
//     for (auto it = bList.begin(); it != bList.end(); ++it)
//     {
//         auto pointer = std::find(aList.begin(), aList.end(), *it);
//         if (pointer != aList.end()) {
//             aList.erase(pointer);
//         }
//         //aList.remove(*it);
//     }
// }
//template void removeAll<int>(std::vector<int>&, const std::vector<int>);

template <class T1, class T2>
void Util::removeAll(std::map<T1, T2>& aMap, const std::vector<T2> bList)
{
    std::list<T1> keys;
    // 1. get all the keys that has the elements from bList
    for (auto it = bList.begin(); it != bList.end(); ++it)
    {
        for (auto j = aMap.begin(); j != aMap.end(); ++j)
        {
            if (j->second == *it) keys.push_back(j->first);
        }
    }
    // 2. remove all the items of the key
    for (auto it = keys.begin(); it != keys.end(); ++it)
    {
        aMap.erase(*it);
    }
}
template void Util::removeAll(std::map<std::string, int>& , const std::vector<int>);

} // namespace