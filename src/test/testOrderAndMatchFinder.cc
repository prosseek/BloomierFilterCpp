#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "orderAndMatch.h"
#include "orderAndMatchFinder.h"
#include "util.h"

using namespace std;

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class OrderAndMatchFinderTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      QuickTest::TearDown();
  }
};

TEST_F(OrderAndMatchFinderTest, findTest) {
//    EXPECT_EQ(values.size(), k);
    int hash = 0; int m = 10; int k = 5; int q = 5;
    map<string, int> mp; mp["abc"] = 10; mp["def"] = 20; mp["abd"] = 30;
    vector<string> keys = {"abc", "def", "abd"};
    
    auto oamf = new bloomier::OrderAndMatchFinder(hash, &mp, m, k, q);
    auto oam = oamf->find();
    
    auto tauList = oam->getTauList();
    for (auto i = tauList->begin(); i != tauList->end(); i++)
    {
        //cout << *i << endl;
        EXPECT_TRUE(*i < k);
    }
    
    auto piList = oam->getPiList();
    for (auto i = piList->begin(); i != piList->end(); i++)
    {
        bool res = bloomier::Util::in(keys, *i);
        EXPECT_TRUE(res);
        //cout << *i << endl;
    }
    EXPECT_TRUE(tauList->size() == 3); // there are three key values
    EXPECT_TRUE(piList->size() == 3); 
    
    // auto h = new Order(hash, m, k, q);
    // auto s = new SingletonFindingTweaker(mp, h);
    // s->tweak("abc");
    // delete h;
    delete oamf;
}
