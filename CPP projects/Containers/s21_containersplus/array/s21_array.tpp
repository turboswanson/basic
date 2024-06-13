using namespace s21;

// Array Member functions

template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {
  std::fill(arr_, arr_ + N, 0);
}

template <typename T, std::size_t N>
array<T, N>::array(const std::initializer_list<T> &items) {
  size_ = N;

  if (items.size() > N) {
    throw std::out_of_range("The list size is larger than array size");
  }

  std::copy(items.begin(), items.end(), this->arr_);
}
template <typename T, std::size_t N>
array<T, N>::array(const array &a) {
  this->size_ = N;
  std::copy(a.arr_, a.arr_ + N, this->arr_);
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) noexcept {
  this->size_ = N;
  std::move(a.arr_, a.arr_ + N, this->arr_);
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  this->size_ = N;
  std::move(a.arr_, a.arr_ + N, this->arr_);

  return *this;
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  this->size_ = N;
  std::copy(a.arr_, a.arr_ + N, this->arr_);

  return *this;
}

// Array Element access

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(array<T, N>::size_type pos) {
  if (pos >= this->size_) {
    throw std::out_of_range("The index is out of range");
  }

  return this->arr_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](
    array<T, N>::size_type pos) {
  return this->arr_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return this->arr_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return this->arr_[N - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return this->arr_;
}

// Array Iterators

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return this->arr_;
}

template <typename T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const noexcept {
  return this->arr_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return this->arr_ + size_;
}

template <typename T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const noexcept {
  return this->arr_ + size_;
}

// Array Capacity

template <typename T, std::size_t N>
bool array<T, N>::empty() noexcept {
  return (begin() == end());
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() noexcept {
  return (this->size_);
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() noexcept {
  return (this->size_);
}

// Array Modifiers

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap_ranges(arr_, arr_ + N, other.arr_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(array<T, N>::const_reference value) {
  std::fill(arr_, arr_ + N, value);
}
