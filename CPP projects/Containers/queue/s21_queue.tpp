#include "s21_queue.hpp"

using namespace s21;

template<typename T,class Container>
queue<T,Container>::queue():container_() {};

template<typename T,class Container>
queue<T,Container>::queue(const std::initializer_list<T>& items) : container_(items){}

template<typename T, class Container>
queue<T,Container>::queue(const queue& s):container_(s.container_){}


template<typename T,class Container>
queue<T,Container>::queue(queue &&s) : container_(std::move(s.container_)){}

template<typename T,class Container>
queue<T,Container>::~queue(){}

template<typename T,class Container>
queue<T,Container>& queue<T,Container>::operator=(queue &&s){
    this->container_ = std::move(s.container_);

    return *this;    
}

// Queue Element access
 
 template<typename T,class Container>
 typename queue<T,Container>::const_reference queue<T,Container>:: front(){
    return this->container_.front();   
 }

 template<typename T,class Container>
 typename queue<T,Container>::const_reference queue<T,Container>:: back(){
    return this->container_.back();   
 }

// Queue Capacity

template<typename T,class Container>
bool queue<T,Container> :: empty() const {
    return this->container_.empty();
}

template<typename T,class Container>
typename queue<T,Container> :: size_type queue<T,Container>::size() const{
    return this->container_.size();
}

template<typename T,class Container>
void queue<T,Container> :: push(typename queue<T,Container>::const_reference value){
    this->container_.push_back(value);
}

template<typename T,class Container>
void queue<T,Container> :: pop() {
    this->container_.erase(this->container_.begin());
}

template<typename T,class Container>
void queue<T,Container> :: swap(queue& other) noexcept{
    this->container_.swap(other.container_);
}

// Additional

template<typename T,class Container>
template<typename ...Args>
void queue<T,Container> :: insert_many_back(Args&& ...args){
    this->container_.insert_many(container_.cend(),args...);
}