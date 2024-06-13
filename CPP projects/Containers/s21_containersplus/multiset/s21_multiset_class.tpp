#pragma once

#include "../../s21_containers/vector/s21_vector.hpp"
#include "s21_multiset_class.hpp"

namespace s21 {

/*
 * Constructors
 * */

template <typename value_type>
multiset<value_type>::multiset() {
  clearFields();
}

template <typename value_type>
multiset<value_type>::multiset(std::initializer_list<value_type> const &items) {
  clearFields();
  for (auto item : items) {
    insert(item);
  }
}

template <typename key_type>
multiset<key_type>::multiset(const multiset &s) {
  clearFields();
  for (auto i : s) {
    insert(i);
  }
}

template <typename key_type>
multiset<key_type>::multiset(multiset &&s) : head(nullptr) {
  moveMultiSet(s);
}

template <typename key_type>
multiset<key_type>::~multiset() {
  clear();
}

/*
 * Operators
 */

template <typename key_type>
typename multiset<key_type>::multiset &multiset<key_type>::operator=(
    multiset &&s) {
  return moveMultiSet(s);
}

/*
 * Iteration
 */

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() {
  return _begin();
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() const {
  return _begin();
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::end() {
  return _end();
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::end() const {
  return _end();
}

/*
 * Modifiers
 */

template <typename key_type>
void multiset<key_type>::clear() {
  if (head != nullptr) {
    deleteNodes(head);
  }
  clearFields();
}

template <typename key_type>
std::pair<typename multiset<key_type>::iterator, bool>
multiset<key_type>::insert(const value_type &value) {
  node *new_node = nullptr;

  if (head == nullptr) {
    new_node = new node{.val = value,
                        .count = 1,
                        .parent = nullptr,
                        .left = nullptr,
                        .right = nullptr};
    head = new_node;
    min_val = value;
    max_val = value;
    min_ptr = new_node;
    max_ptr = new_node;
  } else {
    new_node = insertNode(head, value);
  }

  iterator iter;
  bool res = false;
  iter.current = new_node;
  iter.step = new_node->count;
  res = true;
  size_val++;

  return std::make_pair(iter, res);
}

template <typename key_type>
template <typename... Args>
s21::vector<std::pair<typename multiset<key_type>::iterator, bool>>
multiset<key_type>::insert_many(Args &&...args) {
  s21::vector<std::pair<iterator, bool>> res;
  for (auto arg : {args...}) {
    auto it = insert(arg);
    res.push_back(it);
  }
  return res;
}

template <typename key_type>
void multiset<key_type>::erase(iterator pos) {
  if (this != pos.set_ptr || pos.current == nullptr) return;
  if (pos.current->count > 1) {
    pos.current->count--;
    size_val--;
    return;
  }
  if (pos.current->parent == nullptr && pos.current->left == nullptr &&
      pos.current->right == nullptr) {
    clearFields();
    delete pos.current;
    return;
  }

  node *merged = mergeNode(pos.current->right, pos.current->left);

  if (pos.current == min_ptr) {
    auto next = pos;
    ++next;
    min_val = next.current->val;
    min_ptr = next.current;
  } else if (pos.current == max_ptr) {
    auto prev = pos;
    --prev;
    max_val = prev.current->val;
    max_ptr = prev.current;
  }

  if (merged != nullptr) {
    if (merged->left != nullptr) merged->left->parent = pos.current;
    if (merged->right != nullptr) merged->right->parent = pos.current;
    if (merged == min_ptr) {
      min_val = merged->val;
      min_ptr = pos.current;
    }
    if (merged == max_ptr) {
      max_val = merged->val;
      max_ptr = pos.current;
    }
    pos.current->left = merged->left;
    pos.current->right = merged->right;
    pos.current->val = merged->val;
    delete merged;
  } else {
    if (pos.current->parent->left == pos.current) {
      pos.current->parent->left = nullptr;
    } else {
      pos.current->parent->right = nullptr;
    }
    delete pos.current;
  }
  size_val--;
}

template <typename key_type>
void multiset<key_type>::swap(multiset<key_type> &other) {
  if (this == &other) {
    return;
  }

  auto head_tmp = head;
  auto min_val_tmp = min_val;
  auto min_ptr_tmp = min_ptr;
  auto max_val_tmp = max_val;
  auto max_ptr_tmp = max_ptr;
  auto size_val_tmp = size_val;

  head = other.head;
  min_val = other.min_val;
  min_ptr = other.min_ptr;
  max_val = other.max_val;
  max_ptr = other.max_ptr;
  size_val = other.size_val;

  other.head = head_tmp;
  other.min_val = min_val_tmp;
  other.min_ptr = min_ptr_tmp;
  other.max_val = max_val_tmp;
  other.max_ptr = max_ptr_tmp;
  other.size_val = size_val_tmp;
}

template <typename key_type>
void multiset<key_type>::merge(multiset<key_type> &other) {
  if (other.head != nullptr) {
    mergeNode(head, other.head);
    size_val += other.size_val;
    other.clearFields();
  }
}

/*
 * Capacity
 */

template <typename key_type>
bool multiset<key_type>::empty() {
  return size() == 0;
}

template <typename key_type>
size_t multiset<key_type>::size() {
  return size_val;
}

template <typename key_type>
size_t multiset<key_type>::max_size() {
  /* return std::numeric_limits<size_type>::max() / (sizeof(node) * 2); */
  return 461168601842738790 / 2;
}

/*
 * Lookup
 */

template <typename key_type>
typename multiset<key_type>::iterator multiset<key_type>::find(
    const key_type &key) {
  auto _end = end();
  for (auto iter = begin(); iter != _end; ++iter) {
    if (*iter == key) {
      return iter;
    }
  }
  return _end;
}

template <typename key_type>
bool multiset<key_type>::contains(const key_type &key) {
  if (find(key) != end()) {
    return true;
  }
  return false;
}

/*
 * Private methods
 */

template <typename key_type>
void multiset<key_type>::clearFields() {
  head = nullptr;
  min_ptr = nullptr;
  min_val = 0;
  max_ptr = nullptr;
  max_val = 0;
  size_val = 0;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::_begin() const {
  multiset::iterator result;
  result.current = min_ptr;
  result.val = min_val;
  result.set_ptr = this;
  result.step = 1;
  return result;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::_end() const {
  multiset::iterator result;
  result.current = nullptr;
  result.set_ptr = this;
  result.step = 1;
  return result;
}

template <typename key_type>
void multiset<key_type>::deleteNodes(node *head) {
  if (head->left != nullptr) {
    deleteNodes(head->left);
  }
  if (head->right != nullptr) {
    deleteNodes(head->right);
  }
  delete head;
}

template <typename value_type>
typename multiset<value_type>::node *multiset<value_type>::insertNode(
    node *head, const value_type &value) {
  if (head->val == value) {
    head->count++;
    return head;
  }
  return insertNode(head, new node{.val = value,
                                   .count = 1,
                                   .parent = nullptr,
                                   .left = nullptr,
                                   .right = nullptr});
}

template <typename value_type>
typename multiset<value_type>::node *multiset<value_type>::insertNode(
    node *head, node *node) {
  if (head->val == node->val) {
    head->count += node->count;
    delete node;
    return head;
  }

  if (head->val > node->val) {
    if (head->left == nullptr) {
      node->parent = head;
      head->left = node;

      if (node->val <= min_val) {
        min_val = node->val;
        min_ptr = node;
      }
      return head->left;
    } else {
      return insertNode(head->left, node);
    }
  } else {
    if (head->right == nullptr) {
      node->parent = head;
      head->right = node;

      if (node->val >= max_val) {
        max_val = node->val;
        max_ptr = node;
      }
      return head->right;
    } else {
      return insertNode(head->right, node);
    }
  }
}

template <typename key_type>
typename multiset<key_type>::node *multiset<key_type>::mergeNode(
    node *to_head, node *from_head) {
  if (to_head == nullptr) {
    return from_head;
  }
  if (from_head != nullptr) {
    mergeNode(*to_head, *from_head);
  }
  return to_head;
}

template <typename key_type>
void multiset<key_type>::mergeNode(node &to_head, node &from_head) {
  if (from_head.left != nullptr) {
    mergeNode(to_head, *from_head.left);
  }
  if (from_head.right != nullptr) {
    mergeNode(to_head, *from_head.right);
  }
  from_head.left = nullptr;
  from_head.right = nullptr;
  insertNode(&to_head, &from_head);
}

template <typename key_type>
typename multiset<key_type>::multiset &multiset<key_type>::moveMultiSet(
    multiset &other) {
  clear();

  head = other.head;
  min_ptr = other.min_ptr;
  min_val = other.min_val;
  max_ptr = other.max_ptr;
  max_val = other.max_val;
  size_val = other.size_val;

  other.head = nullptr;
  other.min_ptr = nullptr;
  other.min_val = 0;
  other.max_ptr = nullptr;
  other.max_val = 0;
  other.size_val = 0;

  return *this;
}

}  // namespace s21
