#pragma once

#include "array.h"
#include <cstddef>
#include <string>
#include <initializer_list>
using namespace std;

template <typename T>
class Array {
private:
    size_t size_ = 0;
    T* data_ = nullptr;

public: 
    Array() = default;

    Array(const size_t & size, const T& value = T()) : size_(size), data_(new T[size]) {
        for (int i = 0; i < size; i++) {
            data_[i] = value;
        }
    }

    Array(const std::initializer_list<unsigned char> &list) : size_(list.size()), data_(new T[list.size()]) {
        int i = 0;
        for (const auto& element : list) {
            data_[i++] = element;
        }
    }

    Array(const Array& other) : size_(other.size_), data_(new T[other.size_]) {
        copy(other.data_, other.data_ + other.size_, data_);
    }

    Array(Array&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    virtual ~Array() noexcept {
        delete[] data_;
    }

    size_t size() const {
        return size_;
    }

    T* data() const {
        return data_;
    }

    T get(size_t index) const {
        return data_[index];
    }


};