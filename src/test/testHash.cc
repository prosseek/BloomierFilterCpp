#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include "hash.h"

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class HashTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      QuickTest::TearDown();
  }
};


TEST_F(HashTest, getHash) {
    // res = getHash("abc", 1, 10, 5) # seed:1, m = 10, k = 5
    // returns 5 has numbers for the key "abc" that is less than m
    // [9, 2, 3, 5, 4]
    int k = 5;
    unsigned char result[5];
    int m = 10;
    std::string key = "abc";
    int seed = 1;
    
    bloomier::Hash::getHash(key, seed, m, k, result);
    std::set<int> values;
    for (int i = 0; i < k; i++) 
    {
        values.insert(result[i]);
        EXPECT_TRUE(result[i] < m);
    }
    // assert that there is no duplication
    // the set doesn't have duplication so the length of the set should be k
    EXPECT_EQ(values.size(), k);
}
