#include "chararray.h"
#include <string>
#include <initializer_list>

CharArray::CharArray(const size_t & size, const unsigned char& value) : size_(size), data_(new unsigned char[size]) {
    for (int i = 0; i < size; i++)
        data_[i] = value;
}

CharArray::CharArray(const std::initializer_list<unsigned char> &list) : size_(list.size()), data_(new unsigned char[size_]) {
    int i = 0;
    for (const auto& element : list)
        data_[i++] = element;
}

CharArray::CharArray(const CharArray& other) : size_(other.size_), data_(new unsigned char[other.size_]) {
    std::copy(other.data_, other.data_ + other.size_, data_);
}

CharArray::CharArray(CharArray&& other) noexcept : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}

CharArray::~CharArray() noexcept {
    delete[] data_;
}

size_t CharArray::size() const {
    return size_;
}

unsigned char*  CharArray::data() const {
    return data_;
}

unsigned char CharArray::get(size_t index) const {
    return data_[index];
}


