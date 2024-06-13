#pragma once

#include "../../s21_containers/vector/s21_vector.hpp"

namespace s21 {

template <typename Key>
class multiset {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  struct node {
    value_type val;
    int count;
    node *parent;
    node *left;
    node *right;
  };

  class MultiSetIterator {
    friend class multiset;

   private:
    node *current{nullptr};
    const multiset *set_ptr{nullptr};
    value_type val{0};
    int step{1};

   public:
    value_type operator*();
    MultiSetIterator &operator++();
    MultiSetIterator operator++(int);
    MultiSetIterator &operator--();
    MultiSetIterator operator--(int);

    bool operator==(const MultiSetIterator &other) const;
    bool operator!=(const MultiSetIterator &other) const;
  };  // class MultiSetIterator

  friend class MultiSetIterator;

  node *head;
  node *min_ptr;
  value_type min_val;
  node *max_ptr;
  value_type max_val;

  union size_val_union {
    size_type _size_type;
    value_type _value_type;
  };
  size_type size_val;

  MultiSetIterator _begin() const;
  MultiSetIterator _end() const;

  void clearFields();
  void deleteNodes(node *head);

  node *insertNode(node *head, const value_type &value);
  node *insertNode(node *head, node *node);
  node *mergeNode(node *to_head, node *from_head);
  void mergeNode(node &to_head, node &from_head);
  multiset &moveMultiSet(multiset &other);

 public:
  using iterator = MultiSetIterator;
  using const_iterator = const MultiSetIterator;

  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &s);
  multiset(multiset &&s);
  ~multiset();

  /* Operators */

  multiset &operator=(multiset &&s);

  /* Iterators */

  iterator begin();
  iterator begin() const;
  iterator end();
  iterator end() const;

  /* Capacity */

  bool empty();
  size_type size();
  size_type max_size();

  /* Modifiers */

  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
  /* void insert_many(Args &&...args); */
  void erase(iterator pos);
  void swap(multiset &other);
  void merge(multiset &other);

  /* Lookup */
  iterator find(const key_type &key);
  bool contains(const key_type &key);
};

}  // namespace s21
