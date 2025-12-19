#pragma once

#include "chararray.h"
#include <string>

class Octal {
private:
    CharArray arr; 

    size_t size() const;

    unsigned char get(size_t index) const;

    int compare(const Octal& other) const;
    
public:
    Octal(const unsigned char* arr, size_t size);

    Octal(const Octal& other);

    static Octal* fromstring(const std::string& t);
    
    Octal* add(const Octal& other) const;

    Octal* subtract(const Octal& other) const;

    bool gt(const Octal& other) const;

    bool lt(const Octal& other) const;

    bool eq(const Octal& other) const;

    bool ge(const Octal& other) const;

    bool le(const Octal& other) const;

    std::string tostring() const;

};
