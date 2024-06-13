#pragma once

#include "s21_multiset.hpp"

namespace s21 {

template <typename key_type>
key_type multiset<key_type>::iterator::operator*() {
  if (set_ptr == nullptr) {
    return val;
  }
  if (current == nullptr) {
    union size_val_union val;
    val._size_type = set_ptr->size_val;
    return val._value_type;
  }
  return val;
}

template <typename value_type>
typename multiset<value_type>::iterator&
multiset<value_type>::iterator::operator++() {
  if (current == nullptr) {
    if (set_ptr != nullptr) {
      current = set_ptr->max_ptr;
      val = set_ptr->max_val;
    }
    return *this;
  }
  if (current->count > step) {
    step++;
    return *this;
  }
  if (current == set_ptr->max_ptr) {
    current = nullptr;
    return *this;
  }

  if (current->right != nullptr) {
    current = current->right;
    while (current->left != nullptr) {
      current = current->left;
    }
  } else {
    value_type curr = current->val;
    while (curr >= current->val) {
      current = current->parent;
    }
  }
  val = current->val;
  step = 1;
  return *this;
}

template <typename value_type>
typename multiset<value_type>::iterator
multiset<value_type>::iterator::operator++(int) {
  iterator iter = *this;
  ++(*this);
  return iter;
}

template <typename value_type>
typename multiset<value_type>::iterator&
multiset<value_type>::iterator::operator--() {
  if (current == nullptr) {
    if (set_ptr != nullptr && set_ptr->max_ptr != nullptr) {
      current = set_ptr->max_ptr;
      val = set_ptr->max_val;
      step = set_ptr->max_ptr->count;
    }
    return *this;
  }
  if (step > 1) {
    step--;
    return *this;
  }
  if (current == set_ptr->min_ptr) {
    current = nullptr;
    return *this;
  }

  if (current->left != nullptr) {
    current = current->left;
    while (current->right != nullptr) {
      current = current->right;
    }
  } else {
    value_type curr = current->val;
    while (curr <= current->val) {
      current = current->parent;
    }
  }
  val = current->val;
  step = current->count;
  return *this;
}

template <typename value_type>
typename multiset<value_type>::iterator
multiset<value_type>::iterator::operator--(int) {
  iterator iter = *this;
  --(*this);
  return iter;
}

template <typename value_type>
bool multiset<value_type>::iterator::operator==(
    const typename multiset<value_type>::iterator& other) const {
  if (current == other.current) {
    return true;
  }
  return false;
}

template <typename value_type>
bool multiset<value_type>::iterator::operator!=(
    const typename multiset<value_type>::iterator& other) const {
  if (current == other.current && set_ptr == other.set_ptr) {
    return false;
  }
  return true;
}

}  // namespace s21
