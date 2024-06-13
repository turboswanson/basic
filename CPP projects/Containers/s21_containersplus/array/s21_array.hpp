#pragma once

#include <iostream>
#include <limits>

namespace s21 {

template <typename T, std::size_t N>
class array {
 public:
  // Array Member functions

  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // Array Member functions

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array() = default;
  array &operator=(const array &a);
  array &operator=(array &&a) noexcept;

  // Array Element access

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  iterator data() noexcept;

  // Array Iterators

  iterator begin() noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator cend() const noexcept;

  // Array Capacity
  bool empty() noexcept;
  size_type size() noexcept;
  size_type max_size() noexcept;

  // Array Modifiers
  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  T arr_[N];
  size_type size_;
};

#include "s21_array.tpp"

}  // namespace s21