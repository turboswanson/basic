#include "tests.hpp"
#include "../stack/s21_stack.tpp"
#include "../vector/s21_vector.tpp"
#include <stack>

TEST(StackTest, Constructor_Default) {
  s21::stack<double> our_stack;
  std::stack<double> std_stack;
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(StackTest, Constructor_List) {
  s21::stack<double> our_stack = {1, 2, 3};
  std::stack<double> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(StackTest, Constructor_Copy) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_copy(our_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}

TEST(StackTest, Operator_Copy) {
  s21::stack<int> our_stack_int {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty(our_stack_int);
  std::stack<int> std_stack_empty(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(StackTest, Constructor_Move) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_move(std::move(our_stack));
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(StackTest, Operator_Move) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(StackTest, Top) {
  s21::stack<int> our_stack_int {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<double> our_stack_double {1.1f, 2.1f, 3.1f};
  std::stack<double> std_stack_double;
  std_stack_double.push(1.1f);
  std_stack_double.push(2.1f);
  std_stack_double.push(3.1f);
  s21::stack<std::string> our_stack_string = {"abc", "def", "ghf"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("abc");
  std_stack_string.push("def");
  std_stack_string.push("ghf");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(our_stack_string.top(), std_stack_string.top());
}

TEST(StackTest, Empty) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_3) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}

TEST(StackTest, Push) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  our_stack_int.pop();
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  
  EXPECT_ANY_THROW(s21_stack.pop(););
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(Stack, InsertManyFront_01) {
  s21::stack<int> our_stack_int;
  our_stack_int.insert_many_front(1, 2, 3);
  EXPECT_EQ(our_stack_int.top(), 3);
}

TEST(Stack, InsertManyFront_02) {
  s21::stack<int> our_stack_int;
  our_stack_int.insert_many_front(1, 2, 3);
  
  EXPECT_EQ(our_stack_int.top(), 3);
  our_stack_int.pop();

  EXPECT_EQ(our_stack_int.top(), 2);
  our_stack_int.pop();

  EXPECT_EQ(our_stack_int.top(), 1);
  our_stack_int.pop();

}