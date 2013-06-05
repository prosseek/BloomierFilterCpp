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
    std::vector<std::string> aList = {"abc", "def"};
    //aList.push_back(10); aList.push_back(20); aList.push_back(30); aList.push_back(40);
    // bList.push_back(10); bList.push_back(20);
    EXPECT_EQ(3, aMap.size());
    bloomier::Util::removeAll(aMap, aList);
    EXPECT_EQ(1, aMap.size());
    EXPECT_EQ(40, aMap["xyz"]);
}

TEST_F(UtilTest, byteArrayXor1) {
    unsigned char a[] = {0x00, 0xFF, 0xFF};
    unsigned char b[] = {0xFF, 0xFF, 0x00, 0xFF};
    unsigned char expected[] = {0xFF, 0x00, 0xFF};
    bloomier::Util::byteArrayXor(a, b, 3);
    for (int i = 0; i < 3; i++)
        EXPECT_EQ(a[i], expected[i]);
}

TEST_F(UtilTest, byteArrayXor2) {
    unsigned char a[] =       {0xFF, 0xFF, 0xFF};
    unsigned char b[] = {0x00, 0xFF, 0x00, 0xFF, 0x00};
    unsigned char expected[] = {0x00, 0xFF, 0x00};
    bloomier::Util::byteArrayXor(a, b + 1, 3);
    for (int i = 0; i < 3; i++)
        EXPECT_EQ(a[i], expected[i]);
}

TEST_F(UtilTest, setInArray) {
    unsigned char a[] =       {0xFF, 0xFF, 0xFF};
    unsigned char b[] = {0x00, 0xFF, 0x00, 0xFF, 0x00};
    unsigned char expected[] = {0xFF, 0x00, 0xFF};
    bloomier::Util::setInArray(a, b + 1, 3);
    for (int i = 0; i < 3; i++)
        EXPECT_EQ(a[i], expected[i]);
}

TEST_F(UtilTest, getByteSize) {
    unsigned char a[] = {8, 10, 12, 16};
    unsigned char expected[] = {1,2,2,2};

    for (int i = 0; i < sizeof(a)/sizeof(unsigned char); i++)
        EXPECT_EQ(bloomier::Util::getByteSize(a[i]), expected[i]);
}

TEST_F(UtilTest, inSetTest) {
    // auto s = new SingletonFindingTweaker(null, null);
    std::set<int> values;
    values.insert(10); values.insert(20); values.insert(30);
    EXPECT_TRUE(bloomier::Util::in(values, 10));
    EXPECT_FALSE(bloomier::Util::in(values, 50));
}

TEST_F(UtilTest, inVectorTest) {
    // auto s = new SingletonFindingTweaker(null, null);
    std::vector<int> values;
    values.push_back(10); values.push_back(20); values.push_back(30);
    EXPECT_TRUE(bloomier::Util::in(values, 10));
    EXPECT_FALSE(bloomier::Util::in(values, 50));
}

TEST_F(UtilTest, deepcopy) {
    // auto s = new SingletonFindingTweaker(null, null);
    std::map<std::string, int> source;
    source["abc"] = 10; source["def"] = 20; source["xyz"] = 30;
    std::map<std::string, int> dest;
    
    //std::cout << dest["abc"] << std::endl;
    
    bloomier::Util::deepcopy(source, dest);
    source.clear();
    EXPECT_TRUE(dest["abc"] == 10);
    EXPECT_TRUE(dest["def"] == 20);
    EXPECT_TRUE(dest["xyz"] == 30);
}
