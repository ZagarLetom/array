#include <gtest/gtest.h>

#include <array>

#include "s21_array.h"

TEST(ALL, constructor_default) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(my_fake_array.data(), original_array.data());
  EXPECT_NE(my_fake_array.data(), nullptr);
  EXPECT_NE(original_array.data(), nullptr);
}
/*
TEST(ALL, constructor_init_list) {
  std::initializer_list<int, 5> temp = {2, 4, 6, 4, 2};
  std::array<int,5> original_array(temp);
  s21::array<int,5> my_fake_array(temp);
  std::cout << my_fake_array.size() << std::endl;
  std::cout << original_array.size() << std::endl;
  EXPECT_NE(original_array.data(), nullptr);
  EXPECT_NE(my_fake_array.data(), nullptr);
  EXPECT_EQ(my_fake_array.size(), original_array.size());
}*/

TEST(ALL, constructor_copy) {
  s21::array<int, 5> temp;
  s21::array<int, 5> my_fake_array(temp);
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(my_fake_array.data(), original_array.data());
  EXPECT_NE(original_array.data(), nullptr);
  EXPECT_NE(my_fake_array.data(), nullptr);
}

TEST(ALL, constructor_move) {
  s21::array<int, 5> temp;
  s21::array<int, 5> my_fake_array(std::move(temp));
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(original_array.data(), nullptr);
  EXPECT_NE(my_fake_array.data(), nullptr);
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(temp.size(), 0);
  EXPECT_NE(my_fake_array.size(), temp.size());
  EXPECT_EQ(temp.data(), nullptr);
}

TEST(ALL, at) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (int i = 0; i < 5; i++) {
    my_fake_array.at(i) = i + 96;
    original_array.at(i) = i + 96;
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(my_fake_array.at(i), original_array.at(i));
  }
  EXPECT_ANY_THROW(my_fake_array.at(7));
  EXPECT_ANY_THROW(original_array.at(7));
}

TEST(ALL, overload_accessor) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (int i = 0; i < 5; i++) {
    my_fake_array[i] = i + 96;
    original_array[i] = i + 96;
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(my_fake_array[i], original_array[i]);
  }
}

TEST(ALL, front) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake_array[0] = 97;
  EXPECT_NE(my_fake_array.front(), original_array.front());
  original_array[0] = 97;
  EXPECT_EQ(my_fake_array.front(), original_array.front());
}

TEST(ALL, back) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake_array[4] = 21;
  EXPECT_NE(my_fake_array.back(), original_array.back());
  original_array[4] = 21;
  EXPECT_EQ(my_fake_array.back(), original_array.back());
}

TEST(ALL, data) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.data(), nullptr);
  EXPECT_EQ(my_fake_array.data(), original_array.data());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.data(), nullptr);
  EXPECT_NE(my_fake_array2.data(), original_array2.data());
}

TEST(ALL, begin) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.begin(), nullptr);
  EXPECT_EQ(my_fake_array.begin(), original_array.begin());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.begin(), nullptr);
  EXPECT_NE(my_fake_array2.begin(), original_array2.begin());
}

TEST(ALL, end) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.end(), nullptr);
  EXPECT_EQ(my_fake_array.end(), original_array.end());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.end(), nullptr);
  EXPECT_NE(my_fake_array2.end(), original_array2.end());
}

TEST(ALL, empty) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_EQ(my_fake_array.empty(), true);
  EXPECT_EQ(original_array.empty(), true);
  EXPECT_NE(my_fake_array2.empty(), true);
  EXPECT_NE(original_array2.empty(), true);
}

TEST(ALL, size) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), original_array.size());
}

TEST(ALL, max_size) {
  s21::array<int, 5> m0;
  std::array<int, 5> o0;
  EXPECT_EQ(m0.max_size(), o0.max_size());
  s21::array<double, 5> m1;
  std::array<double, 5> o1;
  EXPECT_EQ(m1.max_size(), o1.max_size());
  s21::array<long long, 5> m2;
  std::array<long long, 5> o2;
  EXPECT_EQ(m2.max_size(), o2.max_size());
  s21::array<int, 5> m01;
  std::array<int, 5> o01;
  EXPECT_EQ(m01.max_size(), o01.max_size());
}

TEST(ALL, swap) {
  s21::array<int, 5> my_fake;
  std::array<int, 5> original;
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake[3] = 33;
  original[3] = 33;
  my_fake[4] = 0;
  original[4] = 0;
  my_fake_array[3] = 0;
  original_array[3] = 0;
  my_fake_array[4] = 44;
  original_array[4] = 44;
  my_fake.swap(my_fake_array);
  original.swap(original_array);
  EXPECT_EQ(my_fake[3], 0);
  EXPECT_EQ(my_fake[4], 44);
  EXPECT_EQ(original[3], 0);
  EXPECT_EQ(original[4], 44);
}

TEST(ALL, fill) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (size_t i = 0; i < my_fake_array.size(); i++) {
    EXPECT_NE(my_fake_array[i], 41);
    EXPECT_NE(original_array[i], 77);
  }
  my_fake_array.fill(41);
  original_array.fill(77);
  for (size_t i = 0; i < my_fake_array.size(); i++) {
    EXPECT_EQ(my_fake_array[i], 41);
    EXPECT_EQ(original_array[i], 77);
  }
}
