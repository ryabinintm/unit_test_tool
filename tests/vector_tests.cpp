#include <gtest/gtest.h>

#include <vector>

TEST(vector, create) {
  // Arrange
  std::vector<int> nums;
  // Act
  // -------- 
  // Assert
  EXPECT_EQ(typeid(std::vector<int>), typeid(nums));
}

TEST(vector, insert_to_end) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  nums.push_back(40);
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(*it++, 40);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, insert_to_begin) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  nums.insert(nums.begin(), 5);
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, insert_to_middle) {
  // Arrange
  std::vector<int> nums{10, 20, 30, 40};
  // Act
  auto it = nums.begin();
  const int middle = nums.size() / 2;
  std::advance(it, middle);
  nums.insert(it, 25);
  // Assert
  it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 25);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(*it++, 40);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, erase_end) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  nums.pop_back();
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, erase_begin) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  nums.erase(nums.begin());
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, erase_middle) {
  // Arrange
  std::vector<int> nums{10, 20, 25, 30, 40};
  // Act
  auto it = nums.begin();
  const int middle = nums.size() / 2;
  std::advance(it, middle);
  nums.erase(it);
  // Assert
  it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(*it++, 40);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, get_elements) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  // --------
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(vector, get_size) {
  // Arrange
  std::vector<int> nums{10, 20, 30};
  // Act
  // --------
  // Assert
  EXPECT_EQ(nums.size(), 3);
}
