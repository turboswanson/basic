#ifndef S21_MAP
#define S21_MAP

#include <iostream>

#define AAA std::cout << "\n\nHERE\n\n";

namespace s21 {

template <class Key, class T> 
class map {
  class Node;

 public:
  class MapIterator;
  class MapConstIterator;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using iterator = MapIterator;
  using const_iterator = MapConstIterator;

private:
  class Node {
    friend class map;
    Node* left;
    Node* right;
    Node* parrent;
    bool is_red;
    Node(key_type key, mapped_type mapped);
    Node(key_type key, mapped_type mapped, bool is_red);
    Node(key_type key);
    Node(key_type key, bool is_red);

   public:
    key_type first;
    mapped_type second;
  };

 private:
  friend class Node;
  friend class MapIterator;
  Node* root;
  size_t size_map;

 public:
  class MapIterator {
    MapIterator get_next_iterator(Node* it);
    MapIterator get_prev_iterator(MapIterator& it);
    Node* get_next_node(Node* it);
    Node* get_prev_it(Node* it);
    Node* get_min_it(Node* node);
    Node* get_max_it(Node* node);
    std::pair<const Key, T>& get_this_node(Node* node);

    friend class map;
    Node* it_node;
    MapIterator(Node* node);

   public:
    MapIterator& operator++();
    MapIterator& operator--();
    bool operator==(const MapIterator& other);
    bool operator!=(const MapIterator& other);
    std::pair<const Key, T&>* operator->();
    std::pair<const Key, T&>& operator*();
  };

  class MapConstIterator {
   protected:
    Node* const_it_node;
    Node* get_next_node_const(Node* it) const;
    Node* get_prev_it_const(Node* it) const;
    Node* get_min_it_const(Node* node) const;
    Node* get_max_it_const(Node* node) const;
   public:
    friend class map;
    MapConstIterator(Node* node);
    MapConstIterator& operator++();
    MapConstIterator& operator--() const;
    bool operator==(const MapConstIterator& other);
    bool operator!=(const MapConstIterator& other);
    Node* operator->();
  };

  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map();
  map& operator=(map<Key, T>&& m);

  T& at(const Key& key);
  T& operator[](const Key& key);

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();
  void clear();

  std::pair<iterator, bool> insert(const value_type& value) {
    iterator it = insert_fix(value.first);
    it.it_node->second = value.second;
    if(it == nullptr)
        return std::pair<iterator, bool>(it, false);
    return std::pair<iterator, bool>(it, true);
  }

  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void erase(Key key);
  void swap(map& other);
  void merge(map& other) {
    for (auto it = other.begin(); it != other.end(); ++it)
      insert(it->first, it->second);
  }

  void print_map();
  bool contains(const Key& key);
  iterator find(const Key& key);

 private:
  iterator get_min_pair(Node* node);
  iterator get_max_pair(Node* node);
  const_iterator get_min_pair_const(Node* node) const;
  const_iterator get_max_pair_const(Node* node) const;
  void print_map(Node* node, int x, int y);
  void insert(Node* node, key_type key, mapped_type mapped, Node* it);
  void insert(Node* node, key_type key);
  void insert(iterator& it);
  void insert(const_iterator& it);
  iterator insert_fix(Key key);
  void clear(Node* node);
  Node* delete_node(Node* node, Key key);
  iterator find(Node* node, Key key);
  void delete_node_2(iterator it);
  int child_count(Node* node);

  // balance funcs

  void swap_nodes(Node* a, Node* b);
  void swap_nodes_col_off(Node* a, Node* b);
  void right_rotate(Node* node);
  void left_rotate(Node* node);
  void balance_map(Node* node);
  void balance_after_delete(Node* node);
  void delete_black_node_without_childs(Node* node);
};
}  // namespace s21

#endif