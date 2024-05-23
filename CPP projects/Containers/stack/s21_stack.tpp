#include "s21_stack.hpp"
// #include "../vector/s21_vector.hpp"

using namespace s21;

// Stack Member functions 

template<typename T,class Container>
stack<T,Container>::stack():container_() {};

template<typename T,class Container>
stack<T,Container>::stack(const std::initializer_list<T>& items) : container_(items){}

template<typename T, class Container>
stack<T,Container>::stack(const stack& s):container_(s.container_){}


template<typename T,class Container>
stack<T,Container>::stack(stack &&s) : container_(std::move(s.container_)){}

template<typename T,class Container>
stack<T,Container>::~stack(){}

template<typename T,class Container>
stack<T,Container>& stack<T,Container>::operator=(stack &&s){
    this->container_ = std::move(s.container_);

    return *this;    
}

 // Stack Element access
 template<typename T,class Container>
 typename stack<T,Container>::const_reference stack<T,Container>:: top(){
    return this->container_.back();   
 }

// Stack Capacity
template<typename T,class Container>
bool stack<T,Container> :: empty() const {
    return this->container_.empty();
}

template<typename T,class Container>
typename stack<T,Container> :: size_type stack<T,Container>::size() const{
    return this->container_.size();
}

template<typename T,class Container>
void stack<T,Container> :: push(typename stack<T,Container>::const_reference value){
    this->container_.push_back(value);
}

template<typename T,class Container>
void stack<T,Container> :: pop() {
    this->container_.pop_back();
}

template<typename T,class Container>
void stack<T,Container> :: swap(stack& other) noexcept{
    this->container_.swap(other.container_);
}

template<typename T,class Container>
template<typename... Args>
void stack<T,Container> :: insert_many_front(Args&&... args){
    this->container_.insert_many(container_.cbegin(),args...);
}



