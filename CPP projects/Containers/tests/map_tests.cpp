#include <map>

#include "test_main.hpp"

TEST(iterator, iterating_funcs_1) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  int arr[] = {1, 2, 3, 4};
  int i = 0;
  for (auto it : a) {
    ASSERT_EQ(it.first, arr[i]);
    ASSERT_EQ(it.second, arr[i++] + 1);
  }
  a.clear();
}

TEST(iterator, iterating_funcs_2) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  int arr[] = {1, 2, 3, 4};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); ++it) {
    EXPECT_TRUE(it->first == arr[i]);
    EXPECT_EQ(it->second, arr[i++] + 1);
  }
  a.clear();
}

TEST(iterator, iterating_funcs_3) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.find(3);
  ASSERT_TRUE(it->first == 3);
  ASSERT_EQ(it->second, 4);
  a.clear();
}

TEST(iterator, iterating_funcs_4) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_FALSE(a.begin() == a.end());
  ASSERT_TRUE(a.begin() != a.end());
  a.clear();
}

TEST(iterator, iterating_funcs_5) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.find(3);
  auto it_1 = *it;
  ASSERT_EQ(it_1.first, 3);
  ASSERT_EQ(it_1.second, 4);
  a.clear();
}

TEST(iterator, iterating_funcs_6) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.find(3);
  it->second = -4;
  ASSERT_EQ(a.find(3)->second, -4);
  a.clear();
}

TEST(iterator, iterating_funcs_7) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.find(3);
  --it;
  ASSERT_TRUE(it->first == 2);
}

TEST(iterator, iterating_funcs_8) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5),
                          std::pair<int, int>(5, 6), std::pair<int, int>(6, 7)};
  auto it = a.find(6);
  int res = 6;
  a.print_map();
  for (; it != a.begin(); --it) {
    ASSERT_TRUE(it->first == res);
    ASSERT_TRUE(it->second == res + 1);
    --res;
  }
}

TEST(const_iterator, iterating_funcs_2) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  int arr[] = {1, 2, 3, 4};
  int i = 0;
  for (auto it = a.cbegin(); it != a.cend(); ++it) {
    ASSERT_TRUE(it->first == arr[i]);
    ASSERT_TRUE(it->second == arr[i++] + 1);
  }
  a.clear();
}

TEST(const_iterator, iterating_funcs_4) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_FALSE(a.cbegin() == a.cend());
  ASSERT_TRUE(a.cbegin() != a.cend());
  a.clear();
}

TEST(const_iterator, iterating_funcs_5) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.cbegin();
  auto it_1 = *it;
  ASSERT_EQ(it_1.first, 1);
  ASSERT_EQ(it_1.second, 2);
  a.clear();
}

TEST(const_iterator, iterating_funcs_6) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  auto it = a.cbegin();
  ++it;
  --it;
  ASSERT_TRUE(it->first == 1);
}

TEST(const_iterator, iterating_funcs_7) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5),
                          std::pair<int, int>(5, 6), std::pair<int, int>(6, 7)};
  auto it = a.cbegin();
  for (int i = 0; i < 5; ++i) ++it;
  int res = 6;
  for (; it != a.cbegin(); --it) {
    ASSERT_TRUE(it->first == res);
    ASSERT_TRUE(it->second == res + 1);
    --res;
  }
}

TEST(Map_init, init_1) {
  s21::map<int, double> a;
  ASSERT_EQ(a.size(), 0);
}

TEST(Map_init, init_2) {
  s21::map<int, double> a = {std::pair<int, double>(1, 1.5),
                             std::pair<int, double>(2, 2.5),
                             std::pair<int, double>(3, 3.5)};
  ASSERT_EQ(a.size(), 3);
}

TEST(Map_init, init_3) {
  s21::map<int, double> a = {std::pair<int, double>(1, 1.5),
                             std::pair<int, double>(2, 2.5),
                             std::pair<int, double>(3, 3.5)};
  s21::map<int, double> b(a);
  ASSERT_EQ(b.size(), 3);
}

TEST(Map_init, init_4) {
  std::vector<s21::map<int, double>> res;
  res.push_back(s21::map<int, double>());
  ASSERT_EQ(res[0].size(), 0);
}

TEST(Map_init, init_5) {
  // s21::map<int, double> a = {std::pair<int, double>(1, 1.5), std::pair<int,
  // double>(2, 2.5), std::pair<int, double>(3, 3.5)};

  s21::map<int, double> b;
  b = s21::map<int, double>();
  ASSERT_EQ(b.size(), 0);
}

TEST(Map_func, at_1) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_EQ(a.at(3), 4);
}

TEST(Map_func, at_2) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  a.at(3) = -2;
  ASSERT_EQ(a.at(3), -2);
}

TEST(Map_func, at_3) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_THROW(a.at(-2), std::out_of_range);
}

TEST(Map_func, operator_1) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_EQ(a[3], 4);
}

TEST(Map_func, operator_2) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  a[3] = -2;
  ASSERT_EQ(a[3], -2);
}

TEST(Map_func, operator_3) {
  s21::map<int, int> a;
  a[3] = -2;
  ASSERT_TRUE(a.contains(3));
  ASSERT_EQ(a[3], -2);
}

TEST(Map_func, empty_1) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  ASSERT_FALSE(a.empty());
}

TEST(Map_func, empty_2) {
  s21::map<int, int> a;
  ASSERT_TRUE(a.empty());
}

TEST(Map_func, empty_3) {
  s21::map<int, int> a = {std::pair<int, int>(1, 2), std::pair<int, int>(2, 3),
                          std::pair<int, int>(3, 4), std::pair<int, int>(4, 5)};
  a.clear();
  ASSERT_TRUE(a.empty());
}

TEST(Map_func, insert_1) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) {
    auto it = a.insert(std::pair<int, int>(i, i + 1));
    ASSERT_TRUE(it.second);
    ASSERT_TRUE(it.first != nullptr);
    ASSERT_TRUE(it.first->first == i);
    ASSERT_EQ(it.first->second, i + 1);
  }
}

TEST(Map_func, insert_2) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) {
    auto it = a.insert(i, i + 1);
    ASSERT_TRUE(it.second);
    ASSERT_TRUE(it.first != nullptr);
    ASSERT_TRUE(it.first->first == i);
    ASSERT_EQ(it.first->second, i + 1);
  }
}

TEST(Map_func, swap) {
  s21::map<std::string, int> a = {std::pair<std::string, int>("a", 1),
                                  std::pair<std::string, int>("b", 2),
                                  std::pair<std::string, int>("c", 3)};
  s21::map<std::string, int> b = {std::pair<std::string, int>("d", 4),
                                  std::pair<std::string, int>("e", 5)};
  a.swap(b);
  ASSERT_EQ(a.size(), 2);
  ASSERT_EQ(b.size(), 3);
  ASSERT_TRUE(a.contains("d"));
  ASSERT_TRUE(a.contains("e"));
  ASSERT_TRUE(b.contains("a"));
  ASSERT_TRUE(b.contains("b"));
  ASSERT_TRUE(b.contains("c"));
}

TEST(Map_func, erase_1) {
  s21::map<std::string, int> a = {std::pair<std::string, int>("a", 1),
                                  std::pair<std::string, int>("b", 2),
                                  std::pair<std::string, int>("c", 3)};
  auto it = a.find("b");
  a.erase(it);
  ASSERT_FALSE(a.contains("b"));
  ASSERT_EQ(a.size(), 2);
}

TEST(Map_func, erase_2) {
  s21::map<std::string, int> a = {std::pair<std::string, int>("a", 1),
                                  std::pair<std::string, int>("b", 2),
                                  std::pair<std::string, int>("c", 3)};
  a.erase("b");
  ASSERT_FALSE(a.contains("b"));
  ASSERT_EQ(a.size(), 2);
}

TEST(Map_func, erase_3) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(0));
  a.erase(0);
  ASSERT_FALSE(a.contains(0));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_4) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(2));
  a.erase(2);
  ASSERT_FALSE(a.contains(2));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_5) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(1));
  a.erase(1);
  ASSERT_FALSE(a.contains(1));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_6) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(4));
  a.erase(4);
  ASSERT_FALSE(a.contains(4));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_7) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(7));
  a.erase(7);
  ASSERT_FALSE(a.contains(7));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_8) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(9));
  a.erase(9);
  ASSERT_FALSE(a.contains(9));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_9) {
  s21::map<int, int> a;
  for (int i = 0; i < 10; ++i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(3));
  a.erase(3);
  ASSERT_FALSE(a.contains(3));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_10) {
  s21::map<int, int> a;
  for (int i = 9; i >= 0; --i) a.insert(std::pair<int, int>(i, i + 1));
  ASSERT_EQ(a.size(), 10);
  ASSERT_TRUE(a.contains(3));
  a.erase(3);
  ASSERT_FALSE(a.contains(3));
  ASSERT_EQ(a.size(), 9);
}

TEST(Map_func, erase_11) {
  s21::map<int, int> a;
  for (int i = 9; i >= 0; --i) a.insert(std::pair<int, int>(i, i + 1));
  a.insert(10, 11);
  a.insert(15, 16);
  a.insert(14, 15);
  ASSERT_EQ(a.size(), 13);
  ASSERT_TRUE(a.contains(9));
  a.erase(9);
  ASSERT_FALSE(a.contains(9));
  ASSERT_EQ(a.size(), 12);
}

TEST(Map_func, erase_12) {
  s21::map<int, int> a;
  for (int i = 10; i < 70; i += 10) a.insert(std::pair<int, int>(i, i + 1));
  a.insert(35, 36);
  ASSERT_EQ(a.size(), 7);
  ASSERT_TRUE(a.contains(60));
  a.erase(50);
  a.erase(60);
  ASSERT_FALSE(a.contains(60));
  ASSERT_EQ(a.size(), 5);
}

TEST(Map_func, erase_13) {
  s21::map<int, int> a;
  for (int i = 10; i < 140; i += 10) a.insert(std::pair<int, int>(i, i + 1));
  a.insert(95, 96);
  a.insert(97, 98);
  a.insert(85, 86);
  ASSERT_EQ(a.size(), 16);
  ASSERT_TRUE(a.contains(120));
  a.erase(110);
  a.erase(130);
  a.erase(120);
  ASSERT_FALSE(a.contains(120));
  ASSERT_EQ(a.size(), 13);
}

TEST(Map_func, insert_or_assign_1) {
  s21::map<int, int> a;
  a.insert_or_assign(2, 2);
  ASSERT_EQ(a.find(2)->second, 2);
  a.insert_or_assign(2, 10);
  ASSERT_EQ(a.size(), 1);
  ASSERT_EQ(a.find(2)->second, 10);
}

TEST(Map_func, at_error_1) {
  s21::map<int, int> a;
  ASSERT_THROW(a.at(3), std::out_of_range);
}
