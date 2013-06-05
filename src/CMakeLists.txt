cmake_minimum_required(VERSION 2.8)
project( bloomier )

# cmake -DCMAKE_BUILD_TYPE:STRING=Debug ../src
# http://www.cmake.org/Wiki/CMake_Useful_Variables#Compilers_and_Tools
set(CMAKE_CXX_FLAGS_DEBUG, ON)
set(CMAKE_CXX_COMPILER "/opt/local/bin/g++-mp-4.8")
#set(CMAKE_CXX_COMPILER "/usr/bin/llvm-g++-4.2")
# http://stackoverflow.com/questions/5334095/cmake-multiarchitecture-compilation
set(CMAKE_CXX_FLAGS "-std=c++11 -m64")
# cmake -DCMAKE_OSX_ARCHITECTURES=x86_64

include_directories(/usr/local/include)
include_directories(.)
include_directories(./core)
link_directories(/usr/local/lib)

set(bloomier_srcs 
    main.cpp 
    
    # bloomier filter code
    bloomierfilter.cpp 
    core/util.cpp
    core/utilEncode.cpp
    core/hash.cpp
    core/bloomierHasher.cpp
    core/singletonFindingTweaker.cpp
    core/orderAndMatchFinder.cpp
    
    # test code
    test/testutil.cc
    test/testUtilEncode.cc
    test/testHash.cc
    test/testBloomierHasher.cc
    test/testSingletonFindingTweaker.cc
    test/testOrderAndMatchFinder.cc
    test/testBloomierFilter.cc
    )
    
add_executable(bl ${bloomier_srcs})
target_link_libraries(bl gtest.a)