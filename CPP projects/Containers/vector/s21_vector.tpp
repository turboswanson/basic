#include "s21_vector.hpp"

namespace s21 {
    template<typename T>
    vector<T> :: vector(){
        this->vector_init();
    }

    template<typename T>
    vector<T> :: vector(size_type n) {
        if(!n){
            this->vector_init();
        } else {
            size_ = n;
            capacity_ = n;
            ptr_ = new T[n];
        }
    }

    template<typename T>
    vector<T> :: vector(const std::initializer_list<value_type>& items)
                 : vector(items.size()){
        int index = 0;

        for(auto &element : items){
            ptr_[index] = element;
            ++index;
        }
    }

    template<typename T>
    vector<T> :: vector(vector&& other) {
        this->swap(other);
        other.vector_init();   
    }

    template<typename T>
    vector<T> :: vector(const vector &other) {
        this->copy_vector(other);
    }

    template<typename T>
    vector<T>& vector<T> :: operator = (vector&& other) {
       this->swap(other);
        other.vector_init(); 

        return *this;
    }


    template<typename T>
    vector<T> :: ~vector(){
        this->remove();
    }

    
    // AUX

    template<typename T>
    void vector<T> :: vector_init() {
        this->size_ = 0;
        this->capacity_ = 0;
        this->ptr_ = nullptr;
    }

    template<typename T>
    void vector<T> :: remove(){
        if(this->ptr_){
            delete[] ptr_;
        }

        ptr_ = nullptr;

        this->size_ = 0;
        this->capacity_ = 0;
    }

    template<typename T>
    void vector<T> :: copy_vector(const vector& other) {
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
        this->ptr_ = new T[this->size_];

        for(int i = 0; i < this->size_;i++){
            this->ptr_[i] = other.ptr_[i];
        }    
    }

    template<typename T>
    void vector<T> :: swap(const vector& other){
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
        this->ptr_ = other.ptr_;
    }

}