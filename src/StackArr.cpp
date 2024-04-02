//#include "StackArr/StackArr.hpp"
//#include <algorithm>
//#include <stdexcept>
//
//template <typename T>
//bool StackArr<T>::empty() const noexcept{
//    return 0 > i_top_;
//}
//
//template <typename T>
//StackArr<T>::StackArr(StackArr&& rhs) noexcept : size_(rhs.size_), i_top_(rhs.i_top_), data_(rhs.data_) {
//    rhs.size_ = 0;
//    rhs.i_top_ = -1;
//    rhs.data_ = nullptr;
//}
//
//template <typename T>
//StackArr<T>& StackArr<T>::operator=(StackArr<T>&& rhs) noexcept {
//    if (this != &rhs) {
//        std::swap(size_, rhs.size_);
//        std::swap(i_top_, rhs.i_top_);
//        std::swap(data_, rhs.data_);
//    }
//    return *this;
//}
//
//template <typename T>
//void StackArr<T>::pop() {
//    if (!empty()) {
//        i_top_ -= 1;
//    }
//    else {
//        throw std::logic_error("ERROR: pop operation is performed on empty stack");
//    }
//}
//
//template <typename T>
//void StackArr<T>::push(const T& val) {
//    if (nullptr == data_) {
//        size_ = 8;
//        data_ = new T[size_];
//    }
//    else if (size_ == i_top_ + 1) {
//        auto buf = new T[size_ * 2];
//        std::copy(data_, data_ + size_, buf);
//        std::swap(data_, buf);
//        delete[] buf;
//        size_ *= 2;
//    }
//    data_[++i_top_] = val;
//}
//
//template <typename T>
//T& StackArr<T>::top() {
//    if (i_top_ < 0) {
//        throw std::logic_error("ERROR: top operation is performed on empty stack");
//    }
//    return data_[i_top_];
//}
//
//template <typename T>
//const T& StackArr<T>::top() const {
//    if (i_top_ < 0) {
//        throw std::logic_error("ERROR: top operation is performed on empty stack");
//    }
//    return data_[i_top_];
//}
//
//template <typename T>
//void StackArr<T>::clear() noexcept {
//    i_top_ = -1;
//}