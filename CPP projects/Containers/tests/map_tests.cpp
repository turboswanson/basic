#include "tests.hpp"
#include "../map/s21_map.tpp"
#include <map>

TEST(mapConstructorTest, DefaultConstructor) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(mapConstructorTest, InitializerListConstructor_01) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(mapConstructorTest, InitializerListConstructor_02) {
  s21::map<int, int> m{{1, 111}, {2, 222}, {3, 333}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), 111);
  EXPECT_EQ(m.at(2), 222);
  EXPECT_EQ(m.at(3), 333);
}

TEST(mapConstructorTest, InitializerListConstructor_03) {
  s21::map<double, double> m{{1.11111, 2.22222}, {3.33333, 4.44444}, {5.55555, 6.66666}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1.11111), 2.22222);
  EXPECT_EQ(m.at(3.33333), 4.44444);
  EXPECT_EQ(m.at(5.55555), 6.66666);
}

TEST(mapConstructorTest, InitializerListConstructor_04) {
  s21::map<double, char> m{{1.11111, 'a'}, {3.33333, 'b'}, {5.55555, 'c'}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1.11111), 'a');
  EXPECT_EQ(m.at(3.33333), 'b');
  EXPECT_EQ(m.at(5.55555), 'c');
}

TEST(mapConstructorTest, CopyConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_EQ(copy_m.at(1), "one");
  EXPECT_EQ(copy_m.at(2), "two");
  EXPECT_EQ(copy_m.at(3), "three");
}

// TEST(mapTest, Clear) {
//   s21::map<int, int> my_map;
//   std::map<int, int> orig_map;
//   my_map.clear();
//   orig_map.clear();
//   EXPECT_EQ(my_map.empty(), orig_map.empty());
//   my_map.insert(std::make_pair(1, 1));
//   orig_map.insert(std::make_pair(1, 1));
//   EXPECT_EQ(my_map.empty(), orig_map.empty());
//   my_map.clear();
//   orig_map.clear();
//   EXPECT_EQ(my_map.empty(), orig_map.empty());
// }

TEST(mapTest, Capacity) {
  s21::map<char, std::string> my_map;
  std::map<char, std::string> orig_map;
  EXPECT_TRUE(my_map.empty() == orig_map.empty());
  my_map.insert('z', "wow");
  EXPECT_FALSE(my_map.empty() == orig_map.empty());
  EXPECT_EQ(my_map.size(), 1);
}

TEST(mapTest, InsertKeyValue) {
  s21::map<int, std::string> map;
  map.insert(1, "one");
  EXPECT_EQ(map.size(), 1);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");

  map.insert(2, "two");
  EXPECT_EQ(map.size(), 2);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");

  map.insert(3, "three");
  EXPECT_EQ(map.size(), 3);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map.contains(3), true);
  EXPECT_EQ(map[3], "three");

}

TEST(mapTest, InsertPair) {
  s21::map<int, std::string> map;
  map.insert(std::make_pair(1, "one"));
  EXPECT_EQ(map.size(), 1);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");

  map.insert(std::make_pair(2, "two"));
  EXPECT_EQ(map.size(), 2);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");

  map.insert(std::make_pair(3, "three"));
  EXPECT_EQ(map.size(), 3);
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map.contains(3), true);
  EXPECT_EQ(map[3], "three");
}

TEST(mapTest, Insert_01) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(1, 'a');
  my_map.insert(2, 'a');
  my_map.insert(3, 'a');
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.insert_or_assign(1, 'b');
  auto i = orig_map.begin();
  EXPECT_TRUE((*pr1.first).first == (*i).first);
  EXPECT_FALSE((*pr1.first).second == (*i).second);
}

TEST(mapTest, Insert_02) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(1, 'a');
  my_map.insert(2, 'a');
  my_map.insert(3, 'a');
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

}

TEST(mapTest, Insert_03) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(std::make_pair(1, 'a'));
  my_map.insert(std::make_pair(2, 'a'));
  my_map.insert(std::make_pair(3, 'a'));
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

}


TEST(mapTest, InsertOrAssign) {
  s21::map<int, std::string> map;
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  EXPECT_TRUE(inserted1);
//   EXPECT_EQ(it1->first, 1);
  EXPECT_EQ(it1->second, "one");

  auto [it2, inserted2] = map.insert_or_assign(1, "NEW_ONE");
  EXPECT_FALSE(inserted2);
//   EXPECT_EQ(it2->first, 1);
  EXPECT_EQ(it2->second, "NEW_ONE");

  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");

  EXPECT_EQ(map.size(), 5);
  EXPECT_EQ(map[1], "NEW_ONE");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
  EXPECT_EQ(map[4], "four");
  EXPECT_EQ(map[5], "five");
}

TEST(mapTest, AtAndOperatorBrackets) {
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_THROW(map.at(4), std::out_of_range);
  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(map, MapOperator) {
  s21::map<char, std::string> my_map = {
      {'a', "Arise"}, {'b', "Begin"}, {'c', "Common"}};
  std::map<char, std::string> orig_map = {
      {'a', "Arise"}, {'b', "Begin"}, {'c', "Common"}};
  my_map['a'] = "Anything";
  orig_map['a'] = "Anything";
  orig_map['b'] = "Bore";
  EXPECT_TRUE(my_map['a'] == orig_map['a']);
  EXPECT_FALSE(my_map['b'] == orig_map['b']);
  EXPECT_TRUE(my_map['c'] == orig_map['c']);
}

TEST(mapTest, MapAtOperator) {
  s21::map<char, std::string> my_map = {
      {'a', "Angel"}, {'b', "Box"}, {'c', "Car"}};
  std::map<char, std::string> orig_map = {
      {'a', "Angel"}, {'b', "Box"}, {'c', "Car"}};
  my_map.at('a') = "Amount";
  orig_map.at('a') = "Amount";
  orig_map.at('b') = "Black";
  EXPECT_TRUE(my_map['a'] == orig_map['a']);
  EXPECT_FALSE(my_map['b'] == orig_map['b']);
  EXPECT_TRUE(my_map['c'] == orig_map['c']);
}

TEST(mapTest, MapAtOperatorException) {
  s21::map<char, std::string> my_map = {
      {'a', "Auto"}, {'b', "Big"}, {'c', "Call"}};
  EXPECT_THROW(my_map.at('g') = "Repair", std::out_of_range);
}

TEST(mapTest, EmptyAndSize) {
  s21::map<int, char> empty_map;
  s21::map<int, char> map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

// TEST(mapTest, Erase) {
//   s21::map<int, std::string> map;

//   map.insert({1, "one"});
//   map.insert({2, "two"});
//   map.insert({3, "three"});
//   map.insert({4, "four"});

//   auto it1 = map.begin();
//   map.erase(it1);
//   EXPECT_EQ(map.size(), 3);
//   EXPECT_FALSE(map.contains(1));
// }

// TEST(mapTest, MapErase_02) {
//   s21::map<int, char> my_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
//   std::map<int, char> orig_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
//   EXPECT_EQ(my_map.size(), orig_map.size());
//   my_map.erase(my_map.begin());
//   orig_map.erase(orig_map.begin());
//   EXPECT_EQ(my_map.size(), orig_map.size());
//   auto my_it = my_map.begin();
//   auto orig_it = orig_map.begin();
//   for (; my_it != my_map.end(); ++my_it, ++orig_it) {
//     EXPECT_TRUE((*my_it).first == (*orig_it).first);
//     EXPECT_TRUE((*my_it).second == (*orig_it).second);
//   }
// }

TEST(mapTest, Swap_01) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

// TEST(mapTest, Swap_02) {
//   s21::map<int, int> my_map = {{1, 1}};
//   s21::map<int, int> my_swap_map = {{3, 3}, {4, 4}};

//   my_map.swap(my_swap_map);
//   EXPECT_EQ(my_map.size(), 2);
//   EXPECT_EQ(my_swap_map.size(), 1);
//   auto x = (*(my_map.begin())).first;
//   auto y = (*(my_swap_map.begin())).first;
//   EXPECT_EQ(x, 3);
//   EXPECT_EQ(y, 1);
// }

TEST(mapTest, Merge_01) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));
}

TEST(mapTest, Contains) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}