#include <iostream>
#include <map>
#include <vector>

namespace s21{
  template<typename T>
  struct Node {
    using value_type = T;
    value_type value;
    Node *prev;
    Node *next;
    Node(double val){
      value = val;
      prev = nullptr;
      next = nullptr;
    }
  };

  template<typename T>
  class List{
  using value_type = T;
  private:
    Node<value_type> *head;
    Node<value_type> *tail;
    size_t size;
  public:
    List() : head(nullptr), tail(nullptr),size(0){}
    ~List(){
      Node<value_type> *current = head;

      while(current != nullptr){
        Node<value_type> *tmp = current;
        current =  current->next;
        delete tmp;
      }
    }

    void push_back(value_type num){
      Node<value_type> *node_ = new Node<value_type>(num);
      
      if(head == nullptr){
        head = node_;
        tail = node_;
      } else {
        tail->next = node_;
        node_->prev = tail;
        tail = node_;
      }

      this->size++;
    }

    void push_front(value_type num){
      Node<value_type> *node_ = new Node<value_type>(num);

      if(head == nullptr){
        head = node_;
        tail = node_;

      }else{
        node_->next = head;
        head->prev = node_;
        head = node_;
      }

      this->size++;
    }

    void pop_front(){
      if(head != nullptr){
        Node<value_type> *tmp = head;
        head = head->next;

        if(head != nullptr){
          head->prev = nullptr;
        }

        delete tmp;
        this->size--;
      }
    }

    void pop_tail(){
      if(tail != nullptr){
        Node<value_type> *tmp = tail;
        tail = tail->prev;

        if(tail != nullptr){
          tail->next = nullptr;  
        }

        delete tmp;
        this->size--;
      }
    }

    size_t get_size() { return size;}

    void print(){
      Node<value_type> *current = this->head;

      while(current != nullptr){
        std::cout << current->value << std:: endl;
        current = current->next;
      }

      std::cout << "The size is " << this->get_size() << std::endl;
    }
  };
}

int main(){

s21::List<double> list_;
list_.push_back(1);
list_.pop_tail();
list_.print();
return 0;
  
}