#include "s21_containers.hpp"
#include "./vector/s21_vector.tpp"

using namespace s21;
// #include <vector>
// #include <iostream>

int main(){
    vector<double> v1{1,2,3,4,5};
    vector<double> v2;
    v2 = std::move(v1);
   return 0;
}