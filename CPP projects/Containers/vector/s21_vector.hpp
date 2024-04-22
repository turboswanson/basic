#pragma once

#include <iostream>

namespace s21{

    template<typename T>
    class vector {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using reference = value_type&;
        using const_reference = const value_type&;
    public:
        vector();
        vector(size_type n);
        vector(const std::initializer_list<value_type>& items);
        vector(const vector &other);
        vector(vector&& other);
        vector<value_type>& operator = (vector&& other);
        ~vector();
    public:
        //Vector Element access
        value_type* data() noexcept;
        reference at(size_type pos);
        //Capacity
        bool empty() const noexcept;
        size_type size() const noexcept;
        size_type capacity() const noexcept;    
    private:
        value_type *ptr_;
        size_type size_;
        size_type capacity_;
    private:
        void vector_init();
        void copy_vector(const vector& other);
        void swap(const vector& other);
        void remove();         
    };
}
