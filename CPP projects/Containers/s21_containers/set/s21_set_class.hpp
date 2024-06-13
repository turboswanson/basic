#pragma once

#include "../vector/s21_vector.hpp"

namespace s21 {

template <typename Key>
class set {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  struct node {
    value_type val;
    node *parent;
    node *left;
    node *right;
  };

  class SetIterator {
    friend class set;

   private:
    node *current{nullptr};
    const set *set_ptr;
    value_type val{0};

   public:
    value_type operator*();
    SetIterator &operator++();
    SetIterator operator++(int);
    SetIterator &operator--();
    SetIterator operator--(int);

    bool operator==(const SetIterator &other) const;
    bool operator!=(const SetIterator &other) const;
  };  // class SetIterator

  friend class SetIterator;

  node *head;
  node *min_ptr;
  value_type min_val{0};
  node *max_ptr;
  value_type max_val{0};

  union size_val_union {
    size_type _size_type;
    value_type _value_type;
  };
  size_type size_val;

  SetIterator _begin() const;
  SetIterator _end() const;

  void clearFields();
  void deleteNodes(node *head);

  node *insertNode(node *head, node *node);
  node *mergeNode(node *to_head, node *from_head);
  void mergeNode(node &to_head, node &from_head);
  set &moveSet(set &other);

 public:
  using iterator = SetIterator;
  using const_iterator = const SetIterator;

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);
  ~set();

  /* Operators */

  set &operator=(set &&s);

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
  void swap(set &other);
  void merge(set &other);

  /* Lookup */
  iterator find(const key_type &key);
  bool contains(const key_type &key);
};

}  // namespace s21
