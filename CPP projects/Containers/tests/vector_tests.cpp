#include "tests.hpp"
#include "../vector/s21_vector.tpp"
#include <vector>

TEST(VectorTest, Constructor_default) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.data(), std_v.data());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n) {
  s21::vector<int> s21_v(5);
  std::vector<int> std_v(5);
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest,Constructor_throw) {
    EXPECT_ANY_THROW (s21::vector<double> v(-1));
}

TEST(VectorTest, Constructor_initializer_list_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest,Constructor_initializer_list_throw) {
    s21::vector<int> s21_v{2, 3, 5, 7, 1};
  
    EXPECT_THROW(s21_v.at(s21_v.size()),std::out_of_range);
}

TEST(VectorTest,Constructor_initializer_list_2){
  s21::vector<std::string> our_stack_string {"abc", "def", "ghf"};
  std::vector<std::string> std_stack_string {"abc", "def", "ghf"};

  for(auto i = 0; i < std_stack_string.size();i++){
    EXPECT_EQ(our_stack_string.at(i),std_stack_string.at(i));
  }
  
}

TEST(VectorTest, Constructor_initializer_list_3) {
  std::initializer_list<int> b;
  s21::vector<int> s21_v{b};
  std::vector<int> std_v{b};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_copy_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
  EXPECT_EQ(s21_copy.at(0), std_copy.at(0));
  EXPECT_EQ(s21_copy.at(1), std_copy.at(1));
  EXPECT_EQ(s21_copy.at(2), std_copy.at(2));
  EXPECT_EQ(s21_copy.at(3), std_copy.at(3));
  EXPECT_EQ(s21_copy.at(4), std_copy.at(4));
}

TEST(VectorTest, Constructor_copy_2) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(VectorTest, Constructor_move_1) {
  s21::vector<double> s21_v{2.2222, 3.3333, 5.555, 7.7777, 1.111111};
  s21::vector<double> tmp(s21_v);  
  s21::vector<double> s21_move(std::move(s21_v));
  
  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 0);
  EXPECT_EQ(s21_v.empty(), true);
  EXPECT_EQ(s21_v.data(), nullptr);

  EXPECT_EQ(s21_move.size(), tmp.size());
  EXPECT_EQ(s21_move.capacity(), tmp.capacity());
  EXPECT_EQ(s21_move.empty(), tmp.empty());
  EXPECT_DOUBLE_EQ(s21_move.at(0), tmp.at(0));
  EXPECT_DOUBLE_EQ(s21_move.at(1), tmp.at(1));
  EXPECT_DOUBLE_EQ(s21_move.at(2), tmp.at(2));
  EXPECT_DOUBLE_EQ(s21_move.at(3), tmp.at(3));
  EXPECT_DOUBLE_EQ(s21_move.at(4),tmp.at(4));
    
}

TEST(VectorTest, Constructor_move_asignment) {
  s21::vector<double> s21_v{2.2222, 3.3333, 5.555, 7.7777, 1.111111};
  s21::vector<double> tmp(s21_v);  
  s21::vector<double> s21_move;
  s21_move = std::move(s21_v); // perform an asignment operation not the initialization 
  
  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 0);
  EXPECT_EQ(s21_v.empty(), true);
  EXPECT_EQ(s21_v.data(), nullptr);

  EXPECT_EQ(s21_move.size(), tmp.size());
  EXPECT_EQ(s21_move.capacity(), tmp.capacity());
  EXPECT_EQ(s21_move.empty(), tmp.empty());
  EXPECT_DOUBLE_EQ(s21_move.at(0), tmp.at(0));
  EXPECT_DOUBLE_EQ(s21_move.at(1), tmp.at(1));
  EXPECT_DOUBLE_EQ(s21_move.at(2), tmp.at(2));
  EXPECT_DOUBLE_EQ(s21_move.at(3), tmp.at(3));
  EXPECT_DOUBLE_EQ(s21_move.at(4),tmp.at(4));
    
}

TEST(VectorTest, Destructor) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21_v.~vector();

  EXPECT_EQ(0, s21_v.size());
  EXPECT_EQ(0, s21_v.capacity());
  EXPECT_EQ(0, s21_v.data());
}

TEST(VectorTest, Operator_move_1) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2;
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Operator_move_2) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2{4, 5, 6};
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Element_at) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest, Element_at_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.at(1));
  EXPECT_ANY_THROW(std_v.at(1));
}

TEST(VectorTest, Element_operator_sq_brackets) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
  EXPECT_EQ(s21_v[3], std_v[3]);
  EXPECT_EQ(s21_v[4], std_v[4]);
}


TEST(VectorTest, Element_operator_square_brackets) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
}

TEST(VectorTest, Element_sq_brackets_throw) {
  s21::vector<int> s21_v;
  EXPECT_ANY_THROW(s21_v[1]);

}

TEST(VectorTest, Element_operator_square_brackets_throw_1) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[5]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_2) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[-1]);
}

TEST(VectorTest, Element_data) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(*s21_v.data(), *std_v.data());
}

TEST(VectorTest,max_size_test_1){
  s21::vector<int>s21_v;
  std::vector<int>std_v;

  EXPECT_DOUBLE_EQ(s21_v.max_size(),std_v.max_size());
}

TEST(VectorTest,max_size_test_2){
  s21::vector<double>s21_v;
  std::vector<double>std_v;

  EXPECT_DOUBLE_EQ(s21_v.max_size(),std_v.max_size());
}

TEST(VectorTest,max_size_test_3){
  s21::vector<char>s21_v;
  std::vector<char>std_v;

  EXPECT_DOUBLE_EQ(s21_v.max_size(),std_v.max_size());
}

TEST(VectorTest, Element_front) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.front(), std_v.front());
}

TEST(VectorTest, Element_front_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.front());
}

TEST(VectorTest, Element_back) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.back(), std_v.back());
}

TEST(VectorTest, Element_back_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.back());
}

TEST(VectorTest, Capacity_empty_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Capacity_empty_2) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}


TEST(VectorTest, Capacity_size_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_size_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_capacity_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_capacity_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_1) {
  std::vector<int> std_v(5,2);
  s21::vector<int> s21_v{2,2,2,2,2};
  

  std_v.reserve(20);
  s21_v.reserve(20);

  EXPECT_EQ(std_v.capacity(),s21_v.capacity());
  EXPECT_EQ(std_v.size(),s21_v.size());

  for(int i = 0; i < std_v.size(); i++){
    // std::cout << std_v[i] << " " << s21_v[i] << std::endl;

    EXPECT_EQ(std_v[i],s21_v[i]);  
  }
 
}

TEST(VectorTest, Capacity_reserve_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_3) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_4_throw) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v.reserve(-2));
  EXPECT_ANY_THROW(std_v.reserve(-2));
}

TEST(VectorTest, Capacity_shrink_to_fit_1) {
  s21::vector<double> s21_v;
  std::vector<double> std_v;
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_shrink_to_fit_2) {
  s21::vector<double> s21_v{1, 2, 3};
  std::vector<double> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Modifiers_clear_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_clear_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}


TEST(VectorTest, Modifiers_swap_1) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v;
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_2) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_3) {
  s21::vector<double> s21_v{1, 2, 3, 4};
  s21::vector<double> s21_v_copy{1, 2};
  std::vector<double> std_v{1, 2, 3, 4};
  std::vector<double> std_v_copy{1, 2};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_4) {
  s21::vector<double> s21_v{1, 2, 3, 4};
  s21::vector<double> s21_v_copy{1, 2, 3, 4, 5, 6};

  std::vector<double> std_v{1, 2, 3, 4};
  std::vector<double> std_v_copy{1, 2, 3, 4, 5, 6};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Iterators){
  s21::vector<double> s21_v{1,2,3,4};
  s21::vector<double>::iterator iter_begin = s21_v.begin();
  s21::vector<double>::iterator iter_end = s21_v.end();
  EXPECT_EQ(*iter_begin,1);
  EXPECT_EQ(*(iter_end-1),4);

}

TEST(VectorTest, Insert_01) {
  s21::vector<int> s21_v = {2, 3, 4};
  std::vector<int> std_v = {2, 3, 4};

  auto s21_it = s21_v.insert(s21_v.begin(), 1);
  auto std_it = std_v.insert(std_v.begin(), 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_02) {
  s21::vector<double> s21_v = {2, 3, 4};
  std::vector<double> std_v = {2, 3, 4};

  auto s21_it = s21_v.insert(s21_v.end()-2, 1);
  auto std_it = std_v.insert(std_v.end()-2, 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_03) {
  s21::vector<double> s21_v = {2, 3, 4};
  std::vector<double> std_v = {2, 3, 4};

  auto s21_it = s21_v.insert(s21_v.end(), 1);
  auto std_it = std_v.insert(std_v.end(), 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_04) {
  s21::vector<double> s21_v = {2.33333};
  std::vector<double> std_v = {2.33333};

  auto s21_it = s21_v.insert(s21_v.end(), 1);
  auto std_it = std_v.insert(std_v.end(), 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_05) {
  s21::vector<double> s21_v;
  std::vector<double> std_v;

  auto s21_it = s21_v.insert(s21_v.end(), 1);
  auto std_it = std_v.insert(std_v.end(), 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_06) {
  s21::vector<double> s21_v;
  std::vector<double> std_v;

  auto s21_it = s21_v.insert(s21_v.begin(), 1);
  auto std_it = std_v.insert(std_v.begin(), 1);
  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());
  EXPECT_EQ(*s21_v.data(), *std_v.data());
  EXPECT_EQ(*s21_it, *std_it);

}

TEST(VectorTest, Insert_07) {

  s21::vector<double> s21_v{1,2,3,4,5};

  auto s21_it_1 = s21_v.begin();

  s21_v.insert(s21_it_1+1,777);

  auto s21_it_2 = s21_v.begin();

  s21_v.insert(s21_it_2+1,888);

  auto s21_it_3 = s21_v.begin();

  s21_v.insert(s21_it_3+1,999);

  auto s21_it_4 = s21_v.begin();

  s21_v.insert(s21_it_4+1,000);

  auto s21_it_5 = s21_v.begin();

  s21_v.insert(s21_it_5+1,111);

  auto s21_it_6 = s21_v.begin();

  s21_v.insert(s21_it_6+1,222);

  std::vector<double> std_v{1,2,3,4,5};

  auto std_it_1 = std_v.begin();

  std_v.insert(std_it_1+1,777);

  auto std_it_2 = std_v.begin();

  std_v.insert(std_it_2+1,888);

  auto std_it_3 = std_v.begin();

  std_v.insert(std_it_3+1,999);

  auto std_it_4 = std_v.begin();

  std_v.insert(std_it_4+1,000);

  auto std_it_5 = std_v.begin();

  std_v.insert(std_it_5+1,111);

  auto std_it_6 = std_v.begin();

  std_v.insert(std_it_6+1,222);

  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());

  for(int i = 0; i < s21_v.size();i++){
    EXPECT_EQ(s21_v.at(i),std_v.at(i));
  }
  

}

TEST(VectorTest, Insert_Throw_01) {
  s21::vector<int> s21_v = {2, 3, 4};
  std::vector<int> std_v = {2, 3, 4};
  auto s21_it = s21_v.begin()-1;
    
  EXPECT_ANY_THROW( s21_v.insert(s21_it, 1));

}

TEST(VectorTest, Insert_Throw_02) {
  s21::vector<int> s21_v = {2, 3, 4};
  std::vector<int> std_v = {2, 3, 4};
  auto s21_it = s21_v.begin()+s21_v.capacity()+1;
    
  EXPECT_ANY_THROW( s21_v.insert(s21_it, 1));

}


TEST(VectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());  // Erase the first element
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 2);
}

TEST(VectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);  // Erase the last element
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, Erase_01) {

  s21::vector<double> s21_v{1,2,3,4,5};

  auto s21_it_1 = s21_v.begin();

  s21_v.erase(s21_it_1);
  s21_v.erase(s21_it_1);
  s21_v.erase(s21_it_1);

  
  std::vector<double> std_v{1,2,3,4,5};

  auto std_it_1 = std_v.begin();

  std_v.erase(std_it_1);
  std_v.erase(std_it_1);
  std_v.erase(std_it_1);

  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());

  for(int i = 0; i < s21_v.size();i++){
    EXPECT_EQ(s21_v.at(i),std_v.at(i));
  }
}

TEST(VectorTest, Erase_02) {

  s21::vector<double> s21_v{1,2,3,4,5};

  auto s21_it_1 = s21_v.end()-1;
  s21_v.erase(s21_it_1);

  auto s21_it_2 = s21_v.end()-1;

  s21_v.erase(s21_it_2);

  auto s21_it_3 = s21_v.end()-1;

  s21_v.erase(s21_it_3);

  
  std::vector<double> std_v{1,2,3,4,5};

  auto std_it_1 = std_v.end()-1;
  std_v.erase(std_it_1);
  auto std_it_2 = std_v.end()-1;
  std_v.erase(std_it_2);
  auto std_it_3 = std_v.end()-1;
  std_v.erase(std_it_3);

  
  EXPECT_EQ(s21_v.size(),std_v.size());
  EXPECT_EQ(s21_v.capacity(),std_v.capacity());

  for(int i = 0; i < s21_v.size();i++){
    EXPECT_EQ(s21_v.at(i),std_v.at(i));
  }
}

TEST(VectorTest, Erase_Throw_01) {
  s21::vector<int> v = {1, 2, 3, 4};
  EXPECT_ANY_THROW(v.erase(v.begin() - 1));
}

TEST(VectorTest, Erase_Throw_02) {
  s21::vector<int> v;
  EXPECT_ANY_THROW(v.erase(v.begin()));
}

TEST(VectorTest, Modifiers_push_back_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_push_back_2) {
  s21::vector<double> s21_v;
  std::vector<double> std_v;

  s21_v.push_back(0.2);
  s21_v.push_back(0.3);
  s21_v.push_back(0.4);
  s21_v.push_back(0.5);

  std_v.push_back(0.2);
  std_v.push_back(0.3);
  std_v.push_back(0.4);
  std_v.push_back(0.5);

  EXPECT_DOUBLE_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_DOUBLE_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_DOUBLE_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_DOUBLE_EQ(s21_v.at(3), std_v.at(3));

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_push_back_3) {
  s21::vector<int> s21_v{};
  std::vector<int> std_v{};

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));

  EXPECT_EQ(s21_v.size(), std_v.capacity());
  EXPECT_EQ(s21_v.size(), std_v.capacity());
  
}

TEST(VectorTest, Modifiers_push_back_4) {
  s21::vector<double> s21_v{};
  std::vector<double> std_v{};

  s21_v.push_back(2.5);
  s21_v.push_back(3.5);
  s21_v.push_back(4.5);
  s21_v.push_back(5.5);

  std_v.push_back(2.5);
  std_v.push_back(3.5);
  std_v.push_back(4.5);
  std_v.push_back(5.5);

  EXPECT_DOUBLE_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_DOUBLE_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_DOUBLE_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_DOUBLE_EQ(s21_v.at(3), std_v.at(3));

  EXPECT_EQ(s21_v.size(), std_v.capacity());
  EXPECT_EQ(s21_v.size(), std_v.capacity());
  
}

TEST(VectorTest, Modifiers_pop_back_1) {
  std::vector<double> v1{1.1,2.2,3.3,4.4,5.5};
  s21::vector<double> v2{1.1,2.2,3.3,4.4,5.5};
  
  for(auto i = 0; i < v2.size(); i++){
    v1.pop_back();
    v2.pop_back();  
  }

  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.size(), v2.size());

}

TEST(VectorTest, Modifiers_pop_back_2) {
  std::vector<double> v1{1.1111,2.2222,3.33333,4.44444,5.55555};
  s21::vector<double> v2{1.1111,2.2222,3.33333,4.44444,5.55555};
  
  v1.pop_back();
  v2.pop_back();  

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for(auto i = 0; i < v2.size();i++){
    EXPECT_EQ(v1.at(i),v2.at(i));  
  }

}

TEST(VectorTest, DefaultConstructor_EmptyVector) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  // for (size_t i = 0; i < size; ++i) {
  //   EXPECT_EQ(v[i], 0);
  // }
}

TEST(VectorTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(VectorTest, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, CopyConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, CopyConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(VectorTest, MoveConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, Destructor_EmptyVector) {
  s21::vector<int>* v = new s21::vector<int>();
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST(VectorTest, Destructor_NonEmptyVector) {
  s21::vector<int>* v = new s21::vector<int>{1, 2, 3};
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(VectorTest, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, IndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, ConstIndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, ConstIndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, FrontConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, FrontConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorTest, BackConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(VectorTest, BackConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(VectorTest, Data_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  // Modify the data through the pointer and check if the vector is updated
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Data_EmptyVector) {
  s21::vector<int> v;
  int* dataPtr = v.data();
  // Data pointer of an empty vector can be anything
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(VectorTest, Begin_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the vector is updated
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Begin_EmptyVector) {
  s21::vector<int> v;
  auto it = v.begin();
  // The begin() of an empty vector should be the end() too, so iterator should
  // be equal to end()
  EXPECT_EQ(it, v.end());
}

TEST(VectorTest, End_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  // end() iterator should not be dereferenced; comparing it to another iterator
  // should work
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(VectorTest, End_EmptyVector) {
  s21::vector<int> v;
  auto it = v.end();
  // The end() of an empty vector should be the begin() too, so iterator should
  // be equal to begin()
  EXPECT_EQ(it, v.begin());
}

TEST(VectorTest, CBegin_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the vector is not updated
  // (should be const_iterator) Uncommenting the following line should result in
  // a compilation error. *it = 10;
}

TEST(VectorTest, CBegin_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cbegin();
  // The cbegin() of an empty vector should be the cend() too, so iterator
  // should be equal to cend()
  EXPECT_EQ(it, v.cend());
}

TEST(VectorTest, CEnd_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cend();
  // cend() iterator should not be dereferenced; comparing it to another
  // iterator should work
  auto beginIt = v.cbegin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(VectorTest, CEnd_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cend();
  // The cend() of an empty vector should be the cbegin() too, so iterator
  // should be equal to cbegin()
  EXPECT_EQ(it, v.cbegin());
}

TEST(VectorTest, Empty_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Empty_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Size_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, Size_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

TEST(VectorTest, MaxSize) {
  const s21::vector<int> v;
  // You can't predict the exact max size, but it should be a very large value
  EXPECT_GT(v.max_size(), 0);
}

TEST(VectorTest, Reserve_IncreaseCapacity) {
  s21::vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Reserve_DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  // Capacity may not decrease immediately, but it shouldn't exceed the
  // requested value
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Capacity_EmptyVector) {
  const s21::vector<int> v;
  // The capacity of an empty vector should be at least 0
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Capacity_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  // The capacity of a non-empty vector might vary, but it should be at least
  // the size of the vector
  EXPECT_GE(v.capacity(), v.size());
}

TEST(VectorTest, ShrinkToFit_EmptyVector) {
  s21::vector<int> v;
  v.shrink_to_fit();
  // After shrink_to_fit() on an empty vector, the capacity should still be at
  // least 0
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, ShrinkToFit_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();  // Simulate a reduction in size
  v.shrink_to_fit();
  // After shrink_to_fit(), the capacity should not exceed the new size
  EXPECT_LE(v.capacity(), v.size());
  // The capacity may not necessarily decrease, but it should not be larger than
  // the initial capacity
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(VectorTest, Clear_EmptyVector) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  // Clearing an empty vector should not affect capacity
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Clear_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  // Clearing a vector should not affect capacity immediately
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  auto it = v.insert(v.begin() + 1, 2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(VectorTest, PushBack_EmptyVector) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], 1);
}

TEST(VectorTest, PushBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
}

TEST(VectorTest, PopBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, Swap_EmptyAndNonEmptyVectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), 0);
  EXPECT_TRUE(v2.empty());
}

TEST(VectorTest, InsertMany_01) {
  s21::vector<int> vec = {1, 2, 3, 7, 8};
  s21::vector<int>::const_iterator pos = vec.cbegin() + 3;

  auto res = vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), 8);

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(vec[6], 7);
  EXPECT_EQ(vec[7], 8);
  EXPECT_EQ(*res, 4);

}

TEST(VectorTest, InsertMany_02) {
  s21::vector<int> vec;
  s21::vector<int>::const_iterator pos = vec.cbegin();

  auto res = vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), 3);

  EXPECT_EQ(vec[0], 4);
  EXPECT_EQ(vec[1], 5);
  EXPECT_EQ(vec[2], 6);
  EXPECT_EQ(*res, 4);


}

TEST(VectorTest, InsertMany_03) {
  s21::vector<int> vec = {1, 2, 3, 7, 8};
  s21::vector<int>::const_iterator pos = vec.cend();

  auto res = vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), 8);

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 7);
  EXPECT_EQ(vec[4], 8);
  EXPECT_EQ(vec[5], 4);
  EXPECT_EQ(vec[6], 5);
  EXPECT_EQ(vec[7], 6);
  EXPECT_EQ(*res, 4);

}

TEST(VectorTest, InsertManyBack_01) {
  s21::vector<int> vec = {1, 2, 3};

  vec.insert_many_back(4, 5, 6);

  EXPECT_EQ(vec.size(), 6);

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
}

TEST(VectorTest, InsertManyBack_02) {
  s21::vector<int> vec;

  vec.insert_many_back(4, 5, 6);

  EXPECT_EQ(vec.size(), 3);

  EXPECT_EQ(vec[0], 4);
  EXPECT_EQ(vec[1], 5);
  EXPECT_EQ(vec[2], 6);
}
