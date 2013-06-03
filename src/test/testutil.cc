#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "Util.h"

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class UtilTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      //std::cout << "Tearing down...\n";
      aList.clear();
      bList.clear();
      aMap.clear();
      QuickTest::TearDown();
  }

  std::vector<int> aList; // = {10, 20, 30, 40};
  std::vector<int> bList;
  std::map<std::string, int> aMap;
};


TEST_F(UtilTest, addAll) {
    std::vector<int> aList = {10, 20, 30, 40}; 
    bList.push_back(100); bList.push_back(200);
    EXPECT_EQ(4, aList.size());
    bloomier::Util::addAll(aList, bList);
    EXPECT_EQ(6, aList.size());
}

TEST_F(UtilTest, removeAll) {
    aMap["abc"] = 10; aMap["def"] = 120; aMap["xyz"] = 40;
    aList.push_back(10); aList.push_back(20); aList.push_back(30); aList.push_back(40);
    // bList.push_back(10); bList.push_back(20);
    EXPECT_EQ(3, aMap.size());
    bloomier::Util::removeAll(aMap, aList);
    EXPECT_EQ(1, aMap.size());
    EXPECT_EQ(120, aMap["def"]);
}

TEST_F(UtilTest, byteArrayXor) {
    unsigned char a[] = {0x00, 0xFF, 0xFF};
    unsigned char b[] = {0xFF, 0xFF, 0x00, 0xFF};
    unsigned char expected[] = {0xFF, 0x00, 0xFF};
    bloomier::Util::byteArrayXor(a, b);
    for (int i = 0; i < 3; i++)
        EXPECT_EQ(a[i], expected[i]);
}

TEST_F(UtilTest, getByteSize) {
    unsigned char a[] = {8, 10, 12, 16};
    unsigned char expected[] = {1,2,2,2};

    for (int i = 0; i < sizeof(a)/sizeof(unsigned char); i++)
        EXPECT_EQ(bloomier::Util::getByteSize(a[i]), expected[i]);
}
