#pragma once

#include <cstddef>
#include <string>
#include <initializer_list>

class CharArray {
private:
    size_t size_ = 0;
    unsigned char* data_ = nullptr;

public: 
    CharArray() = default;

    CharArray(const size_t & size, const unsigned char& value = 0);

    CharArray(const std::initializer_list<unsigned char> &list);

    CharArray(const CharArray& other);

    CharArray(CharArray&& other) noexcept;

    virtual ~CharArray() noexcept;

    size_t size() const;

    unsigned char* data() const;

    unsigned char get(size_t index) const;


};