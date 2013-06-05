#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "UtilEncode.h"

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class UtilEncodeTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
  }

  std::vector<int> aList; // = {10, 20, 30, 40};
  std::vector<int> bList;
  std::map<std::string, int> aMap;
};

TEST_F(UtilEncodeTest, encode) {
    int value = 1000;

    unsigned char expected[] = {232, 3, 0, 0, 0};
    unsigned char array[] = {0, 0, 0, 0, 0};
    int width = sizeof(array)/sizeof(unsigned char);
    bloomier::UtilEncode::encode(value, width, array); // , width);
    for (int i = 0; i < width; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
    
    // when array is smaller than 4, the value will be truncated
    value = 1000; 
    unsigned char expected2[] = {232}; // , 0, 0, 0, 0};
    unsigned char array2[] = {0};
    width = sizeof(array2)/sizeof(unsigned char);
    // std::cout << "***" << width << std::endl; 
    bloomier::UtilEncode::encode(value, width, array2); //, width);
    for (int i = 0; i < width; i++) {
        EXPECT_EQ(array2[i], expected2[i]);
    }
}

TEST_F(UtilEncodeTest, decode) {
    int value = 1000;

    unsigned char expected[] = {232, 3, 0, 0, 0};
    int width = sizeof(expected)/sizeof(unsigned char);
    
    int result = bloomier::UtilEncode::decode(expected, width);
    EXPECT_EQ(value, result);
    
    unsigned char expected2[] = {232}; // , 0, 0, 0, 0};
    width = sizeof(expected2)/sizeof(unsigned char);
    result = bloomier::UtilEncode::decode(expected2, width);
    EXPECT_EQ(232, result); 
    
    value = 232 + 3*(int(1) << 8) + 111 * (int(1) << 16) + 1 * (int(1) << 24);
    unsigned char expected3[] = {232, 3, 111, 1};
    width = sizeof(expected3)/sizeof(unsigned char);
    
    result = bloomier::UtilEncode::decode(expected3, width);
    EXPECT_EQ(value, result);
}
