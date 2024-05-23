#pragma once

#include <iostream>
#include <limits>

namespace s21{

    template<typename T>
    class vector {
    public:

        // Vector member type
        
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = T*;
        using const_iterator = const T*; 
        using size_type = std::size_t;
    
        // Vector member functions

        vector();
        vector(size_type n);
        vector(const std::initializer_list<value_type>& items);
        vector(const vector &other);
        vector(vector&& other);
        ~vector();
        vector<value_type>& operator = (vector&& other);
    
        // Vector Element access
    
        reference at(size_type pos);
        reference operator [](size_type pos);
        const_reference front() const; 
        const_reference back() const; 
        value_type* data() noexcept;

        // Vector Iterators

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        // Capacity

        bool empty() const noexcept;
        size_type size() const noexcept;
        size_type max_size() const noexcept;    
        void reserve(size_type size);
        size_type capacity() const noexcept;
        void shrink_to_fit();

        // Vector Modifiers
        void clear() noexcept;
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void swap(vector& other) noexcept;

        // Additional 

        template<typename... Args>
        iterator insert_many(const_iterator pos, Args&&... args);
        template<typename... Args>
        void insert_many_back(Args&&... args);

    private:
        value_type *ptr_;
        size_type size_;
        size_type capacity_;

        // AUX
        
        void vector_init();
        void copy_vector(const vector& other);
        void replace(const vector& other);
        void remove();         
    };

}
