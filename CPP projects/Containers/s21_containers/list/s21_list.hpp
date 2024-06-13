#pragma once

#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

 protected:
  struct node {
    value_type value_;
    node *next;
    node *prev;
    node(int value) : value_(value), next(nullptr), prev(nullptr) {}
  };

 public:
  class ListIterator {
    friend class list<T>;

   private:
    node *cur_node;
    node *first;
    node *last;

   public:
    ListIterator();
    ListIterator(list<T>::node *node, list<T>::node *first_node,
                 list<T>::node *last_node);
    ListIterator &operator++(int);
    ListIterator &operator--(int);
    ListIterator &operator++();
    ListIterator &operator--();
    reference operator*();
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;
  };

  class ListConstIterator : public ListIterator {
    friend class list<T>;

   private:
    node *cur_node;
    node *first;
    node *last;

   public:
    ListConstIterator();
    ListConstIterator(const ListIterator &node);
    const_reference operator*() const;
    bool operator==(const ListIterator &other) const;
  };

  list();
  list(size_type n);
  list(const std::initializer_list<value_type> &items);
  list(const list &other);
  list(list &&other);
  ~list();

  list<value_type> &operator=(list &other);
  list<value_type> &operator=(list &&other);
  bool operator==(const list &other) const;

  const_reference front() const;
  const_reference back() const;

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <class... Args>
  void insert_many_back(Args &&...args);

  template <class... Args>
  void insert_many_front(Args &&...args);

 protected:
  void list_init();
  void copy_list(const list &other);
  void push_node(const_reference value, bool mode);
  void delete_node(bool mode);

 private:
  node *first_;
  node *last_;
};
}  // namespace s21

#include "s21_list.tpp"