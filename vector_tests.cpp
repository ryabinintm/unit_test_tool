#include <gtest/gtest.h>
#include <vector>

TEST(vector, create) {
  std::vector<int> nums;
  EXPECT_EQ(typeid(std::vector<int>), typeid(nums));
}

TEST(vector, insert_to_end) {
  std::vector<int> nums{10, 20, 30};
  nums.push_back(40);
  EXPECT_EQ(nums.at(nums.size() - 1), 40);
}

TEST(vector, insert_to_begin) {
  std::vector<int> nums{10, 20, 30};
  nums.insert(nums.begin(), 40);
  EXPECT_EQ(nums.at(0), 40);
}

TEST(vector, insert_to_middle) {
  std::vector<int> nums{10, 20, 30, 40};
  const int middle = nums.size() / 2;
  nums.insert(nums.begin() + middle, 25);
  EXPECT_EQ(nums.at(middle), 25);
}

TEST(vector, erase_end) {
  std::vector<int> nums{10, 20, 30};
  nums.erase(nums.end() - 1);
  EXPECT_EQ(nums.at(nums.size() - 1), 20);
}

TEST(vector, erase_begin) {
  std::vector<int> nums{10, 20, 30};
  nums.erase(nums.begin());
  EXPECT_EQ(nums.at(0), 20);
}

TEST(vector, erase_middle) {
  std::vector<int> nums{10, 20, 30};
  const int middle = nums.size() / 2;
  nums.erase(nums.begin() + middle);
  EXPECT_EQ(nums.at(0), 10);
  EXPECT_EQ(nums.at(1), 30);
}

TEST(vector, get_elements) {
  std::vector<int> nums{10, 20, 30};
  EXPECT_EQ(nums.at(0), 10);
  EXPECT_EQ(nums.at(1), 20);
  EXPECT_EQ(nums.at(2), 30);
}

TEST(vector, get_size) {
  std::vector<int> nums{10, 20, 30};
  EXPECT_EQ(nums.size(), 3);
}
