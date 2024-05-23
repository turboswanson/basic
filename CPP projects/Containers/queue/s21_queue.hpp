#pragma once

#include "../vector/s21_vector.hpp"

namespace s21{
    template<typename T,class Container = vector<T>>
    class queue{
    public:
        
        // Queue Member functions

        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;

        // Queue Member type 

        queue();
        queue(std::initializer_list<value_type> const &items);
        queue(const queue &s);
        queue(queue &&q);
        ~queue();
        queue<value_type,Container>& operator=(queue &&q);

        // Queue Element access
        
        const_reference front();
        const_reference back();

        // Queue Capacity
        
        bool empty() const;
        size_type size() const;

        // Queue Modifiers

        void push(const_reference value);
        void pop();
        void swap(queue& other) noexcept;

        // Additional 
        template<typename ...Args>
        void insert_many_back(Args&&... args);


    private:
        Container container_;    
    
    };
}