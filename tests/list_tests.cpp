#include <gtest/gtest.h>

#include <list>

TEST(list, create) {
  // Arrange
  std::list<int> nums;
  // Act
  // --------
  // Assert
  EXPECT_EQ(typeid(std::list<int>), typeid(nums));
}

TEST(list, insert_to_end) {
  // Arrange
  std::list<int> nums{10, 20, 30};
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

TEST(list, insert_to_begin) {
  // Arrange
  std::list<int> nums{10, 20, 30};
  // Act
  nums.push_front(5);
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(list, insert_to_middle) {
  // Arrange
  std::list<int> nums{10, 20, 30, 40};
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

TEST(list, erase_end) {
  // Arrange
  std::list<int> nums{10, 20, 30};
  // Act
  nums.pop_back();
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(it, nums.end());
}

TEST(list, erase_begin) {
  // Arrange
  std::list<int> nums{10, 20, 30};
  // Act
  nums.pop_front();
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(list, erase_middle) {
  // Arrange
  std::list<int> nums{10, 20, 25, 30, 40};
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

TEST(list, get_elements) {
  // Arrange
  std::list<int> nums{10, 20, 30};
  // Act
  // --------
  // Assert
  auto it = nums.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_EQ(it, nums.end());
}

TEST(list, get_size) {
  // Arrange
  std::list<int> nums{10, 20, 30};
  // Act
  // --------
  // Assert
  EXPECT_EQ(nums.size(), 3);
}
