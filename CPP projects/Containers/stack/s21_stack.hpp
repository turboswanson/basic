#pragma once

#include "../vector/s21_vector.hpp"

namespace s21{
    template<typename T,class Container = vector<T>>
    class stack{
    public:
        
        // Stack Member functions

        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;

        // Stack Member type 

        stack();
        stack(const std::initializer_list<value_type>& items);
        stack(const stack &s);
        stack(stack &&s);
        ~stack();
        stack<value_type,Container>& operator=(stack &&s);

        // Stack Element access
        
        const_reference top();

        // Stack Capacity
        
        bool empty() const;
        size_type size() const;

        // Stack Modifiers

        void push(const_reference value);
        void pop();
        void swap(stack& other) noexcept;

        // Additional 
        template<typename ...Args>
        void insert_many_front(Args&&... args);

    private:
        Container container_;    
    
    };
}