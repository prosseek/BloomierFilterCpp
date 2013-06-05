#include <limits.h>
#include <time.h>
#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include "bloomierHasher.h"

using namespace bloomier;

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
  }
};

class BloomierHasherTest : public QuickTest {
 protected:
  virtual void SetUp() {
      QuickTest::SetUp();
  }
  
  virtual void TearDown() {
      QuickTest::TearDown();
  }
  BloomierHasher* b;
};


TEST_F(BloomierHasherTest, getNeighborhood) {
    int m = 100; int k = 5;
    b = new BloomierHasher(10, m, k, 9);
    unsigned char result[k];
    b->getNeighborhood("keyValue", result);
    for (int i = 0; i < k; i++) {
        //std::cout << std::hex << int(result[i]) << std::endl;
        EXPECT_TRUE(result[i] < m);
    }
}

TEST_F(BloomierHasherTest, getM) {
    int m = 100; int k = 5;
    b = new BloomierHasher(10, m, k, 9);
    unsigned char result[k];
    b->getM("keyValue", result, k);
    for (int i = 0; i < k; i++) {
        //std::cout << std::hex << int(result[i]) << std::endl;
        // It's for debugging purposes
        //EXPECT_TRUE(result[i] < m);
    }
}
