#include "s21_containers.hpp"
#include "./vector/s21_vector.tpp"

using namespace s21;
// #include <vector>
// #include <iostream>

int main(){ 
  s21::vector<double> s21_v{2.2222, 3.3333, 5.555, 7.7777, 1.111111};
  s21::vector<double> s21_move;
  s21_move = std::move(s21_v);
  
  
  return 0;
}