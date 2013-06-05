#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "bloomierFilter.h"
#include "util.h"

using namespace std;

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class BloomierFilterTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      QuickTest::TearDown();
  }
};

TEST_F(BloomierFilterTest, simpleGetTest) {
    int hash = 0; int m = 10; int k = 5; int q = 24;
    map<string, int> mp; mp["abc"] = 10; mp["def"] = 20; mp["abd"] = 30;
    vector<string> keys = {"abc", "def", "abd"};
    auto bf = bloomier::BloomierFilter(hash, &mp, m, k, q);
    int result;
    EXPECT_TRUE(bf.get("abc", result)); //, true);
    EXPECT_EQ(10, result);
    EXPECT_TRUE(bf.get("def", result)); // , true);
    EXPECT_EQ(20, result);
    EXPECT_TRUE(bf.get("abd", result)); // , true);
    EXPECT_EQ(30, result);
    EXPECT_FALSE(bf.get("xyz", result));
}

TEST_F(BloomierFilterTest, simpleSetTest) {
    int hash = 0; int m = 10; int k = 5; int q = 24;
    map<string, int> mp; mp["abc"] = 10; mp["def"] = 20; mp["abd"] = 30;
    vector<string> keys = {"abc", "def", "abd"};
    auto bf = bloomier::BloomierFilter(hash, &mp, m, k, q);
    int result;
    EXPECT_TRUE(bf.set("abc", 1024)); //, true);
    EXPECT_TRUE(bf.get("abc", result)); // , true);
    EXPECT_EQ(1024, result);
}

