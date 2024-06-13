#include "test_main.hpp"

TEST(Multiset_Constructors, Test_1) {
  s21::multiset<int> m1;

  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());
  ASSERT_TRUE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 0);
  ASSERT_EQ(*(m1.end()), 0);
  ASSERT_EQ(*(--m1.end()), 0);
}

TEST(Multiset_Constructors, Test_2) {
  std::initializer_list<int> arr = {2, 1, 2};
  s21::multiset<int> m1(arr);

  ASSERT_EQ(m1.size(), 3);
  ASSERT_FALSE(m1.empty());
  ASSERT_FALSE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 1);
  ASSERT_EQ(*(m1.end()), 3);
  ASSERT_EQ(*(--m1.end()), 2);
}

TEST(Multiset_Constructors, Test_3) {
  s21::multiset<int> m1({0, 1, 2, 2});

  ASSERT_EQ(m1.size(), 4);
  ASSERT_FALSE(m1.empty());
  ASSERT_FALSE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 0);
  ASSERT_EQ(*(m1.end()), 4);
  ASSERT_EQ(*(--m1.end()), 2);
}

TEST(Multiset_Constructors, Test_4) {
  s21::multiset<int> m1({});

  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());
  ASSERT_TRUE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 0);
  ASSERT_EQ(*(m1.end()), 0);
  ASSERT_EQ(*(--m1.end()), 0);
}

TEST(Multiset_Constructors, Test_5) {
  s21::multiset<int> m1({0, -1, 1, 0});
  s21::multiset<int> m2(m1);

  ASSERT_EQ(m1.size(), 4);
  ASSERT_FALSE(m1.empty());
  ASSERT_FALSE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), -1);
  ASSERT_EQ(*(m1.end()), 4);
  ASSERT_EQ(*(--m1.end()), 1);

  ASSERT_EQ(m2.size(), 4);
  ASSERT_FALSE(m2.empty());
  ASSERT_FALSE(m2.begin() == m2.end());
  ASSERT_EQ(*(m2.begin()), -1);
  ASSERT_EQ(*(m2.end()), 4);
  ASSERT_EQ(*(--m2.end()), 1);
}

TEST(Multiset_Constructors, Test_6) {
  s21::multiset<int> m1({0, -1, 1, 0});
  s21::multiset<int> m2 = m1;

  ASSERT_EQ(m1.size(), 4);
  ASSERT_FALSE(m1.empty());
  ASSERT_FALSE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), -1);
  ASSERT_EQ(*(m1.end()), 4);
  ASSERT_EQ(*(--m1.end()), 1);

  ASSERT_EQ(m2.size(), 4);
  ASSERT_FALSE(m2.empty());
  ASSERT_FALSE(m2.begin() == m2.end());
  ASSERT_EQ(*(m2.begin()), -1);
  ASSERT_EQ(*(m2.end()), 4);
  ASSERT_EQ(*(--m2.end()), 1);
}

TEST(Multiset_Constructors, Test_7) {
  s21::multiset<int> m1({0, -1, 1, 0});
  s21::multiset<int> m2(std::move(m1));

  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());
  ASSERT_TRUE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 0);
  ASSERT_EQ(*(m1.end()), 0);
  ASSERT_EQ(*(--m1.end()), 0);

  ASSERT_EQ(m2.size(), 4);
  ASSERT_FALSE(m2.empty());
  ASSERT_FALSE(m2.begin() == m2.end());
  ASSERT_EQ(*(m2.begin()), -1);
  ASSERT_EQ(*(m2.end()), 4);
  ASSERT_EQ(*(--m2.end()), 1);
}

TEST(Multiset_Constructors, Test_8) {
  s21::multiset<int> m1({0, -1, 1, 1});
  s21::multiset<int> m2;
  s21::multiset<int> m3 = m2 = std::move(m1);

  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());
  ASSERT_TRUE(m1.begin() == m1.end());
  ASSERT_EQ(*(m1.begin()), 0);
  ASSERT_EQ(*(m1.end()), 0);
  ASSERT_EQ(*(--m1.end()), 0);

  ASSERT_EQ(m2.size(), 4);
  ASSERT_FALSE(m2.empty());
  ASSERT_FALSE(m2.begin() == m2.end());
  ASSERT_EQ(*(m2.begin()), -1);
  ASSERT_EQ(*(m2.end()), 4);
  ASSERT_EQ(*(--m2.end()), 1);

  ASSERT_EQ(m3.size(), 4);
  ASSERT_FALSE(m3.empty());
  ASSERT_FALSE(m3.begin() == m3.end());
  ASSERT_EQ(*(m3.begin()), -1);
  ASSERT_EQ(*(m3.end()), 4);
  ASSERT_EQ(*(--m3.end()), 1);
}

TEST(Multiset_Constructors, Test_9) {
  ASSERT_NO_THROW({ s21::multiset<int> m1({0, -1, 1, 1, 1}); });
}

TEST(Multiset_Iterators, begin_1) {
  std::initializer_list<double> arr{0.12, 0.12};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.begin(), *std.begin());
}

TEST(Multiset_Iterators, begin_2) {
  std::initializer_list<double> arr{0.12, 24.45,     24.46,
                                    0.12, -9999.999, -9999.998};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.begin(), *std.begin());
}

TEST(Multiset_Iterators, begin_3) {
  std::initializer_list<double> arr{};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.begin(), *std.begin());
}

TEST(Multiset_Iterators, begin_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;
  s21::multiset<std::initializer_list<int>*> s21({&il2, &il1});
  std::multiset<std::initializer_list<int>*> std({&il2, &il1});

  ASSERT_EQ(*s21.begin(), *std.begin());
}

TEST(Multiset_Iterators, begin_5) {
  std::initializer_list<double> arr{0.12};
  const s21::multiset<double> s21(arr);
  const std::multiset<double> std(arr);

  ASSERT_EQ(*s21.begin(), *std.begin());
}

TEST(Multiset_Iterators, end_1) {
  std::initializer_list<double> arr{0.12};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.end(), *std.end());
}

TEST(Multiset_Iterators, end_2) {
  std::initializer_list<double> arr{0.12, 24.45, 24.46, -9999.999, -9999.998};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.end(), *std.end());
}

TEST(Multiset_Iterators, end_3) {
  std::initializer_list<double> arr{};
  s21::multiset<double> s21(arr);
  std::multiset<double> std(arr);

  ASSERT_EQ(*s21.end(), *std.end());
}

TEST(Multiset_Iterators, end_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;
  s21::multiset<std::initializer_list<int>*> s21({&il2, &il1});
  std::multiset<std::initializer_list<int>*> std({&il2, &il1});

  ASSERT_EQ(*s21.end(), *std.end());
}

TEST(Multiset_Modifiers, clear_1) {
  s21::multiset<int> s21{1, 2, 3, 1};

  s21.clear();

  ASSERT_EQ(s21.size(), 0);
  ASSERT_TRUE(s21.empty());
  ASSERT_TRUE(s21.begin() == s21.end());
  ASSERT_EQ(*(s21.begin()), 0);
  ASSERT_EQ(*(s21.end()), 0);
  ASSERT_EQ(*(--s21.end()), 0);
}

TEST(Multiset_Modifiers, clear_2) {
  s21::multiset<int> s21{1, 2, 2, 2, 2, 2, 2, 3};

  s21.clear();

  ASSERT_EQ(s21.size(), 0);
  ASSERT_TRUE(s21.empty());
  ASSERT_TRUE(s21.begin() == s21.end());
  ASSERT_EQ(*(s21.begin()), 0);
  ASSERT_EQ(*(s21.end()), 0);
  ASSERT_EQ(*(--s21.end()), 0);
}

TEST(Multiset_Modifiers, insert_1) {
  s21::multiset<int> s21{};
  std::multiset<int> std{};

  s21.insert(1);
  s21.insert(1);
  std.insert(1);
  std.insert(1);
  s21.insert(-1);
  s21.insert(-1);
  std.insert(-1);
  std.insert(-1);
  s21.insert(1);
  std.insert(1);
  s21.insert(999);
  s21.insert(999);
  std.insert(999);
  std.insert(999);
  s21.insert(0);
  std.insert(0);
  s21.insert(2);
  std.insert(2);

  ASSERT_EQ(s21.size(), std.size());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i < (s21.size()); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
  *s21i++;
  *stdi++;
}

TEST(Multiset_Modifiers, insert_2) {
  s21::multiset<double> s21{};
  std::multiset<double> std{};

  s21.insert(1.1);
  s21.insert(1.1);
  std.insert(1.1);
  std.insert(1.1);
  s21.insert(-1.1);
  s21.insert(-1.1);
  std.insert(-1.1);
  std.insert(-1.1);
  s21.insert(1.99);
  std.insert(1.99);
  s21.insert(1.97);
  std.insert(1.97);
  s21.insert(1.98);
  std.insert(1.98);
  s21.insert(999);
  std.insert(999);
  s21.insert(0);
  s21.insert(0);
  std.insert(0);
  std.insert(0);
  s21.insert(2.0001);
  std.insert(2.0001);

  ASSERT_EQ(s21.size(), std.size());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, insert_3) {
  s21::multiset<std::string*> s21{};
  std::multiset<std::string*> std{};

  std::string i1;
  s21.insert(&i1);
  std.insert(&i1);
  std::string i2;
  s21.insert(&i2);
  std.insert(&i2);
  std::string i3;
  s21.insert(&i3);
  std.insert(&i3);

  ASSERT_EQ(s21.size(), std.size());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_1) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  s21.erase(s21.find(1));
  std.erase(std.find(1));

  ASSERT_EQ(s21.size(), std.size());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_2) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  s21.erase(s21.begin()++);
  std.erase(std.begin()++);

  ASSERT_EQ(s21.size(), std.size());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_3) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_4) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_5) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_7) {
  std::initializer_list<int> il{1, 2, 3, 0, 1, -5};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21i++;
  stdi++;
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_8) {
  std::initializer_list<int> il{1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
}

TEST(Multiset_Modifiers, erase_9) {
  std::initializer_list<int> il{2, 1, 1};
  s21::multiset<int> s21{il};
  s21::multiset<int> s21c{il};
  std::multiset<int> std{il};
  std::multiset<int> stdc{il};

  s21.erase(s21c.begin());
  std.erase(stdc.begin());

  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_10) {
  std::initializer_list<int> il{1, 2, 2};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_11) {
  std::initializer_list<int> il{2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_12) {
  std::initializer_list<int> il{1, 0, 0, 2};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_13) {
  std::initializer_list<int> il{3, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21i++;
  stdi++;
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());

  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i <= s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_14) {
  std::initializer_list<int> il{3, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.end();
  auto stdi = std.end();
  s21.erase(s21i);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_15) {
  std::initializer_list<int> il{3, 2, 2, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.find(2);
  auto stdi = std.find(2);
  std.erase(stdi);
  s21.erase(s21i);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_16) {
  std::initializer_list<int> il{3, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.find(2);
  auto stdi = std.find(2);
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_17) {
  std::initializer_list<int> il{7, 1, 5, 2};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, erase_18) {
  std::initializer_list<int> il{1, 2, 3};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  auto s21i = s21.begin();
  auto stdi = std.begin();
  s21.erase(s21i);
  std.erase(stdi);

  ASSERT_EQ(s21.size(), std.size());
  s21i = s21.begin();
  stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, swap_1) {
  std::initializer_list<int> il1{3, 2, 2, 1};
  std::initializer_list<int> il2{4, 5, 5, 6};
  s21::multiset<int> s21_1{il1};
  s21::multiset<int> s21_2{il2};
  std::multiset<int> std_1{il1};
  std::multiset<int> std_2{il2};

  s21_1.swap(s21_2);
  std_1.swap(std_2);

  ASSERT_EQ(s21_1.size(), std_1.size());
  auto s21i = s21_1.begin();
  auto stdi = std_1.begin();
  for (size_t i = 0; i < s21_1.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }

  ASSERT_EQ(s21_2.size(), std_2.size());
  s21i = s21_2.begin();
  stdi = std_2.begin();
  for (size_t i = 0; i < s21_2.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, swap_2) {
  std::initializer_list<int> il{3, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  s21.swap(s21);
  std.swap(std);

  ASSERT_EQ(s21.size(), std.size());
  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Modifiers, merge_1) {
  std::initializer_list<int> il1{3, 2, 2, 1, 1};
  std::initializer_list<int> il2{4, 5, 5, 6};
  s21::multiset<int> s21_1{il1};
  s21::multiset<int> s21_2{il2};
  std::multiset<int> std_1{il1};
  std::multiset<int> std_2{il2};

  s21_1.merge(s21_2);
  std_1.merge(std_2);

  ASSERT_EQ(s21_1.size(), std_1.size());
  auto s21i = s21_1.begin();
  auto stdi = std_1.begin();
  for (size_t i = 0; i < s21_1.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }

  ASSERT_EQ(s21_2.size(), std_2.size());
  ASSERT_EQ(*s21_2.begin(), *std_2.begin());
  ASSERT_EQ(*s21_2.end(), *std_2.end());
}

TEST(Multiset_Modifiers, merge_3) {
  std::initializer_list<int> il1{3, 2, 2, 1, 1};
  std::initializer_list<int> il2{5, 5, 4, 6, 5};
  s21::multiset<int> s21_1{il1};
  s21::multiset<int> s21_2{il2};
  std::multiset<int> std_1{il1};
  std::multiset<int> std_2{il2};

  s21_1.merge(s21_2);
  std_1.merge(std_2);

  ASSERT_EQ(s21_1.size(), std_1.size());
  auto s21i = s21_1.begin();
  auto stdi = std_1.begin();
  for (size_t i = 0; i < s21_1.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }

  ASSERT_EQ(s21_2.size(), std_2.size());
  ASSERT_EQ(*s21_2.begin(), *std_2.begin());
  ASSERT_EQ(*s21_2.end(), *std_2.end());
}

TEST(Multiset_Modifiers, merge_2) {
  std::initializer_list<int> il1{3, 3, 2, 1};
  s21::multiset<int> s21_1{il1};
  s21::multiset<int> s21_2{};
  std::multiset<int> std_1{il1};
  std::multiset<int> std_2{};

  s21_1.merge(s21_2);
  std_1.merge(std_2);

  ASSERT_EQ(s21_1.size(), std_1.size());
  auto s21i = s21_1.begin();
  auto stdi = std_1.begin();
  for (size_t i = 0; i < s21_1.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }

  ASSERT_EQ(s21_2.size(), std_2.size());
  ASSERT_EQ(*s21_2.begin(), *std_2.begin());
  ASSERT_EQ(*s21_2.end(), *std_2.end());
}

TEST(Multiset_Capacity, empty_1) {
  std::initializer_list<int> il{3, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(s21.empty(), std.empty());
}

TEST(Multiset_Capacity, empty_2) {
  s21::multiset<int> s21{};
  std::multiset<int> std{};

  ASSERT_EQ(s21.empty(), std.empty());
}

TEST(Multiset_Capacity, size_1) {
  s21::multiset<int> s21{};
  std::multiset<int> std{};

  ASSERT_EQ(s21.size(), std.size());
}

TEST(Multiset_Capacity, size_2) {
  std::initializer_list<int> il{3, 2, 2, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(s21.size(), std.size());
}

TEST(Multiset_Capacity, maxsize) {
  s21::multiset<int> s21{};
  ASSERT_EQ(s21.max_size(), 230584300921369395);
}

TEST(Multiset_Lookup, find_1) {
  std::initializer_list<int> il{3, 2, 3, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(*s21.find(3), *std.find(3));
}

TEST(Multiset_Lookup, find_2) {
  std::initializer_list<int> il{3, 2, 1, 2};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(*s21.find(2), *std.find(2));
}

TEST(Multiset_Lookup, find_3) {
  std::initializer_list<int> il{3, 2, 1, 1};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(*s21.find(1), *std.find(1));
}

TEST(Multiset_Lookup, find_4) {
  std::initializer_list<int> il{};
  s21::multiset<int> s21{il};
  std::multiset<int> std{il};

  ASSERT_EQ(*s21.find(1), *std.find(1));
}

TEST(Multiset_Lookup, find_5) {
  s21::multiset<int> s21{};
  std::multiset<int> std{};

  ASSERT_EQ(*s21.find(1), *std.find(1));
}

TEST(Multiset_Lookup, contains_1) {
  s21::multiset<int> s21{};

  ASSERT_EQ(s21.contains(1), false);
}
TEST(Multiset_Lookup, contains_2) {
  s21::multiset<int> s21{1, 2, 3};

  ASSERT_EQ(s21.contains(4), false);
}

TEST(Multiset_Lookup, contains_3) {
  s21::multiset<int> s21{1, 2, 3, 1};

  ASSERT_EQ(s21.contains(1), true);
}

TEST(Multiset_Iter, star_1) {
  s21::multiset<double> s21{1.1, 1.5, 1.5, 2.5};
  std::multiset<double> std{1.1, 1.5, 1.5, 2.5};

  auto s21i = s21.find(1.5);
  auto stdi = std.find(1.5);

  ASSERT_EQ(*s21i, *stdi);
}

TEST(Multiset_Iter, star_2) {
  s21::multiset<double> s21{1.5};
  std::multiset<double> std{1.5};

  auto s21i = s21.end();
  auto stdi = std.end();

  ASSERT_EQ(*s21i, *stdi);
}

TEST(Multiset_Iter, star_3) {
  s21::multiset<int> s21{1, 1, 1};
  std::multiset<int> std{1, 1, 1};

  auto s21i = s21.end();
  auto stdi = std.end();

  ASSERT_EQ(*s21i, *stdi);
}

TEST(Multiset_Iter, star_4) {
  s21::multiset<int> s21{};
  std::multiset<int> std{};

  auto s21i = s21.begin();
  auto stdi = std.begin();

  ASSERT_EQ(*s21i, *stdi);
}

TEST(Multiset_Iter, increment_1) {
  s21::multiset<int> s21{2, 1, 3, 3, 4, 9};
  std::multiset<int> std{2, 1, 3, 3, 4, 9};

  auto s21i = s21.begin();
  auto stdi = std.begin();

  for (size_t i = 0; i < s21.size() * 2; i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}

TEST(Multiset_Iter, increment_2) {
  s21::multiset<int> s21{2, 1, 3, 4, 9, 9};
  std::multiset<int> std{2, 1, 3, 4, 9, 9};

  auto s21i = s21.begin();
  auto stdi = std.begin();

  for (size_t i = 0; i < s21.size() * 2; i++) {
    ASSERT_EQ(*(++s21i), *(++stdi));
  }
}

TEST(Multiset_Iter, increment_3) {
  s21::multiset<int>::iterator s21i;
  s21::multiset<int>::iterator stdi;

  ASSERT_EQ(*(++s21i), *(++stdi));
}

TEST(Multiset_Iter, decrement_1) {
  s21::multiset<int> s21{2, 1, 3, 4, 4, 9};
  std::multiset<int> std{2, 1, 3, 4, 4, 9};

  auto s21i = s21.end();
  auto stdi = std.end();

  for (size_t i = s21.size() * 2; i > 0; i--) {
    ASSERT_EQ(*s21i--, *stdi--);
  }
}

TEST(Multiset_Iter, decrement_2) {
  s21::multiset<int> s21{2, 1, 3, 4, 9, 9};
  std::multiset<int> std{2, 1, 3, 4, 9, 9};

  auto s21i = s21.end();
  auto stdi = std.end();

  for (size_t i = s21.size() * 2; i > 0; i--) {
    ASSERT_EQ(*(--s21i), *(--stdi));
  }
}

TEST(Multiset_Iter, decrement_3) {
  s21::multiset<int> s21{5, 3, 1, 3, 2, 4, 9};
  std::multiset<int> std{5, 3, 1, 3, 2, 4, 9};

  auto s21i = s21.end();
  auto stdi = std.end();

  for (size_t i = s21.size() * 2; i > 0; i--) {
    ASSERT_EQ(*(--s21i), *(--stdi));
  }
}

TEST(Multiset_Additional, insert_many_1) {
  s21::multiset<int> s21{};
  std::multiset<int> std{1, 6, 5, 6, 6, 6};

  s21.insert_many(1, 6, 5, 6, 6, 6);

  ASSERT_EQ(s21.size(), std.size());
  auto s21i = s21.begin();
  auto stdi = std.begin();
  for (size_t i = 0; i < s21.size(); i++) {
    ASSERT_EQ(*s21i++, *stdi++);
  }
}
