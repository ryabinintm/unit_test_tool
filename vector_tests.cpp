#include <gtest/gtest.h>
#include <vector>

TEST(vector, vector_create) {
  std::vector<int> nums{10, 20, 30};
  EXPECT_EQ(nums.at(0), 10);
  EXPECT_EQ(nums.at(1), 20);
  EXPECT_NE(nums.at(2), 25);
  EXPECT_EQ(nums.at(2), 30);
}


