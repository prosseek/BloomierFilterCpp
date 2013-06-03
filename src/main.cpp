//
//  main.cpp
//  BloomierFilter
//
//  Created by smcho on 05/30/13.
//  Copyright (c) 2013 ___MPC___. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>

int main(int argc,  char ** argv)
{
    std::cout << "Running main() from gtest_main.cc\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
    return 0;
}
