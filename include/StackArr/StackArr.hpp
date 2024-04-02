#ifndef STACKARR_STACKARR_HPP
#define STACKARR_STACKARR_HPP

#include <cstddef>
#include <iostream>

// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template <typename T>
class StackArr {
public:
	[[nodiscard]] StackArr() = default;

	[[nodiscard]] StackArr(const StackArr&) = default;
	[[nodiscard]] StackArr(StackArr&& rhs) noexcept : size_(rhs.size_), i_top_(rhs.i_top_), data_(rhs.data_) {
        rhs.size_ = 0;
        rhs.i_top_ = -1;
        rhs.data_ = nullptr;
    }

	~StackArr() = default;

	[[nodiscard]] StackArr& operator=(const StackArr&) = default;
	[[nodiscard]] StackArr& operator=(StackArr&& rhs) noexcept {
        if (this != &rhs) {
            std::swap(size_, rhs.size_);
            std::swap(i_top_, rhs.i_top_);
            std::swap(data_, rhs.data_);
        }
        return *this;
    };
	[[nodiscard]] bool empty() const noexcept {
        return 0 > i_top_;
    };

	void pop() {
        if (!empty()) {
            i_top_ -= 1;
        }
        else {
            throw std::logic_error("ERROR: pop operation is performed on empty stack");
        }
    }

	void push(const T& val) {
        if (nullptr == data_) {
            size_ = 8;
            data_ = new T[size_];
        }
        else if (size_ == i_top_ + 1) {
            auto buf = new T[size_ * 2];
            std::copy(data_, data_ + size_, buf);
            std::swap(data_, buf);
            delete[] buf;
            size_ *= 2;
        }
        data_[++i_top_] = val;
    }

	[[nodiscard]] T& top() {
        if (i_top_ < 0) {
            throw std::logic_error("ERROR: top operation is performed on empty stack");
        }
        return data_[i_top_];
    }

	[[nodiscard]] const T& top() const {
        if (i_top_ < 0) {
            throw std::logic_error("ERROR: top operation is performed on empty stack");
        }
        return data_[i_top_];
    };

	void clear() noexcept {
        i_top_ = -1;
    };

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t i_top_ = -1;
	T* data_ = nullptr;
};

#endif