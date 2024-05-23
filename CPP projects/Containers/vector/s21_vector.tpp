#include "s21_vector.hpp"
 
using namespace s21;

    template<typename T>
    static void copy_vector_data(T* src, T* dst,uint size){
        for(auto i = 0; i < size;i++){
                dst[i] = src[i];
        }    
    }

    template<typename T>
    static void shift_array_right(T* arr,int index,uint size){
        for(auto i = size; i > index;i--){
            arr[i] = arr[i-1];             
        }     
    }

    template<typename T>
    static void shift_array_left(T* arr,int index,uint size){
        for(auto i = index; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
    }

    template<typename T>
    vector<T> :: vector(){
        this->vector_init();
    }

    template<typename T>
    vector<T> :: vector(size_type n) {
        if(n < 0 || n >= this->max_size()){
            throw std::out_of_range("Vector size should be non-negative");
        }

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
    vector<T> :: vector(const vector &other) {
        this->copy_vector(other);
    }

    template<typename T>
    vector<T> :: vector(vector&& other) {
        this->replace(other);
        other.vector_init();   
    }

    template<typename T>
    vector<T>& vector<T> :: operator = (vector&& other) {
       delete[] this->ptr_;
       
       this->replace(other);
       
        other.vector_init(); 

        return *this;
    }


    template<typename T>
    vector<T> :: ~vector(){
        this->remove();
    }

    // Vector Element access

    template<typename T>
    typename vector<T>::reference vector<T> :: at(vector<T>::size_type pos){
        if (pos >= size() || pos < 0) {
            throw std::out_of_range("The index is out of range");
        }

        return this->ptr_[pos];
    }

    template<typename T>
    typename vector<T>::reference vector<T> :: operator [](vector<T>::size_type pos){
        if (pos >= size() || pos < 0) {
            throw std::out_of_range("The index is out of range");
        }

        return this->ptr_[pos];
    }

    template<typename T>
    typename vector<T>::const_reference vector<T> :: front() const{
        if(!size_){
            throw std::out_of_range("The vector is empty");
        }
        return ptr_[0];
    }

    template<typename T>
    typename vector<T>::const_reference vector<T> :: back() const{
        if(!size_){
            throw std::out_of_range("The vector is empty");
        }

        return ptr_[size_-1];
    }

    template<typename T>
    typename vector<T>:: value_type* vector<T> :: data() noexcept {
        return ptr_ ;
    }

    // Vector Iterators

    template<typename T>
    typename vector<T>::iterator vector<T> :: begin() {
        return ptr_;    
    }

    template<typename T>
    typename vector<T>::iterator vector<T> :: end() {
        return ptr_ + size_;    
    }

    template<typename T>
    typename vector<T>::const_iterator vector<T> :: cbegin() const {
        return ptr_;    
    }

    template<typename T>
    typename vector<T>::const_iterator vector<T> :: cend() const {
        return ptr_ + size_;    
    }

    // Capacity

    template<typename T>
    bool vector<T> :: empty() const noexcept{
       return size_ == 0; 
    }

    template<typename T>
    typename vector<T> :: size_type vector<T> :: size() const noexcept{
        return size_;
    }

    template<typename T>
    void vector<T> :: reserve(typename vector<T>::size_type new_capacity){
        if(new_capacity > this->max_size()){
            throw std::out_of_range("This is too much");
        }else if(new_capacity > capacity_){
            T* tmp = new T[new_capacity];

            copy_vector_data(ptr_,tmp,size_);
           
            delete[] ptr_;

            ptr_ = tmp;
            tmp = nullptr;
            this->capacity_ = new_capacity;
        }

    }

    template<typename T>
    void vector<T>::shrink_to_fit(){
        
        if(size_ != capacity_){
            T* tmp = new T[size_];

            copy_vector_data(ptr_,tmp,size_);

            delete[] ptr_;

            ptr_ = tmp;
            tmp = nullptr;
            this->capacity_ = size_;    

        }
    }

    template<typename T>
    typename vector<T> :: size_type vector<T> :: capacity() const noexcept{
        return capacity_;
    }

    /// @brief 
    /// @tparam T 
    /// @details numeric_limits<size_type>::max() returns UINT_MAX depends on 32 or 64-bit system
    /// @details pow(2,bits)/sizeof(value_type), bits = 31 or 63  
    template<typename T>
    typename vector<T> :: size_type vector<T> :: max_size() const noexcept{
        return std::numeric_limits<size_type>::max() / (2 * sizeof(T));
    }

    // Vector Modifiers

    template<typename T>
    void vector<T> :: clear() noexcept{
        this->remove();    
    }

    template<typename T>
    typename vector<T>::iterator vector<T> :: insert(vector<T>::iterator pos, vector<T>::const_reference value){
        int index = pos - begin();
        size_t new_size = size_+1;
        if(index >= new_size || index < 0){
            throw std::out_of_range("Pos is a reference to a non-existent member");
        }

        T* tmp = new T[new_size];
        copy_vector_data(ptr_,tmp,size_);
        shift_array_right(tmp,index,size_);
        tmp[index] = value;
        delete[] ptr_;

        this->ptr_ = tmp;
        tmp = nullptr;

        this->size_++;
        
        if(size_ - 1 == capacity_){ 
            uint size = capacity_? capacity_*2 : 1;
            this->reserve(size);
        }

        return this->ptr_+index;

    }

    template<typename T>
    void vector<T>::erase(typename vector<T>::iterator pos){

        int index = pos - begin();

        if(!size_ || index < 0 || index == size_){
            throw std::out_of_range("Nothing to erase");
        }

        shift_array_left(ptr_,index,size_);
        size_--;    
    }

    template<typename T>
    void vector<T> :: push_back(typename vector<T>::const_reference value){
        this->insert(this->end(),value);        
    }
    
    template<typename T>
    void vector<T> :: pop_back(){
        this->erase(this->end()-1);
    }
    

    template<typename T>
    void vector<T> :: swap(vector<T>& other) noexcept{
        std::swap(ptr_,other.ptr_);
        std::swap(size_,other.size_);
        std::swap(capacity_,other.capacity_);    
    }

    // ADDITIONAL

    template<typename T>
    template<typename... Args>
    typename vector<T>::iterator vector<T> :: insert_many(const_iterator pos, Args&&... args){
        auto current = this->begin() + std::distance(this->cbegin(), pos);

        int count = 0;

        for(const auto& arg : {args...}){
            current  = this->insert(current,arg) + 1;
            count++;
        }

       auto res = current - count;

       return res;
    }

    template<typename T>
    template<typename... Args>
    void vector<T> :: insert_many_back(Args&&... args){
        this->insert_many(cend(),args...);    
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
    void vector<T> :: replace(const vector& other){
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
        this->ptr_ = other.ptr_;
    }


