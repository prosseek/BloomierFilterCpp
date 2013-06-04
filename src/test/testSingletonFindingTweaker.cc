#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "bloomierHasher.h"
#include "singletonFindingTweaker.h"

using namespace bloomier;
using namespace std;

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

TEST_F(SingletonFindingTweakerTest, tweakTest) {
    int hash = 0; int m = 10; int k = 5; int q = 5;
    auto h = new BloomierHasher(hash, m, k, q);
    map<string, int> mp; mp["abc"] = 10; mp["def"] = 20; mp["abd"] = 30;
    unsigned char result[k];
    auto s = new SingletonFindingTweaker(mp, h);
    s->tweak("abc");
    delete h;
    delete s;
    
    // std::vector<int> aList = {10, 20, 30, 40}; 
    // bList.push_back(100); bList.push_back(200);
    // EXPECT_EQ(4, aList.size());
    // bloomier::Util::addAll(aList, bList);
    // EXPECT_EQ(6, aList.size());
}

