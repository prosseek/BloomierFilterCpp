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

class SingletonFindingTweakerTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      QuickTest::TearDown();
  }
};


TEST_F(SingletonFindingTweakerTest, addAll) {
    // std::vector<int> aList = {10, 20, 30, 40}; 
    // bList.push_back(100); bList.push_back(200);
    // EXPECT_EQ(4, aList.size());
    // bloomier::Util::addAll(aList, bList);
    // EXPECT_EQ(6, aList.size());
}

