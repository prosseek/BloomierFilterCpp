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

void Util::byteArrayXor(unsigned char result[], const unsigned char input[])
{
    int size = std::min(sizeof(result)/sizeof(unsigned char), sizeof(input)/sizeof(unsigned char));

    for (int i = 0; i < size; i++)
    {
        result[i] = result[i] ^ input[i];
    }
}

int Util::getByteSize(int value)
{
    // return q//8 + (1 if q % 8 != 0 else 0
    return value / 8 + (value % 8 == 0 ? 0 : 1);
}

} // namespace