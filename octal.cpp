#include "octal.h"
#include <iostream>


Octal::Octal(const unsigned char* a, size_t size) : arr(size) {
    std::copy(a, a + size, arr.data());
}


Octal::Octal(const Octal& other) : arr(other.arr) {}


Octal* Octal::fromstring(const string& t) {
    unsigned char* s = new unsigned char[t.size()];
    for (int i = t.size() - 1; i >= 0; i--) {
        s[i] = t.at(t.size() - 1 - i);
        if (s[i] < '0' || s[i] > '7') throw runtime_error("The string must consist of digits 0-7.");
    }
    int last = t.size() - 1;
    while (last > 0 && s[last] == '0')
        last--;

    Octal* o = new Octal(s, last + 1);
    delete[] s;
    return o;
}


size_t Octal::size() const {
    return this->arr.size();
}


unsigned char Octal::get(size_t index) const {
    return (index < this->size())? this->arr.get(index) : '0';
}


Octal* Octal::add(const Octal& other) const {
    int maxsize = std::max(this->size(), other.size());
    unsigned char* result = new unsigned char[maxsize + 1];
    int remainder = 0;
    for (int i = 0; i < maxsize; i++) {
        int t = remainder + (this->get(i) - '0') + (other.get(i) - '0');
        result[i] = t % 8 + '0';
        remainder = t >= 8;
    }
    if (remainder)
        result[maxsize] = '1';
    Octal* o = new Octal(result, maxsize + remainder);
    delete[] result;
    return o;
}


Octal* Octal::subtract(const Octal& other) const {
    if (this->lt(other)) throw runtime_error("Cannot substract a larger number.");
    else if (this->eq(other)) return fromstring("0");
    unsigned char* result = new unsigned char[this->size()];
    int debt = 0;
    for (int i = 0; i < this->size(); i++) {
        int t = (this->get(i) - '0') - (other.get(i) - '0') - debt;
        result[i] = ((t < 0)? t + 8 : t) + '0';
        debt = t < 0;
    }
    int last = this->size() - 1;
    while (last > 0 && result[last] == '0')
        last--;

    Octal* o = new Octal(result, last + 1); 
    delete[] result;
    return o;
}


int Octal::compare(const Octal& other) const {
    if (this->size() != other.size())
        return (this->size() > other.size())? 1 : -1;
    for (int i = this->size() - 1; i >= 0; i--) {
        if (this->get(i) > other.get(i)) return 1;
        else if (this->get(i) < other.get(i)) return -1;
    }
    return 0;
}


bool Octal::gt(const Octal& other) const {
    return compare(other) == 1;
}


bool Octal::lt(const Octal& other) const {
    return compare(other) == -1;
}


bool Octal::eq(const Octal& other) const {
    return compare(other) == 0;
}


bool Octal::ge(const Octal& other) const {
    return compare(other) == 1 || compare(other) == 0;
}


bool Octal::le(const Octal& other) const {
    return compare(other) == -1 || compare(other) == 0;
}


string Octal::tostring() const {
    string res;
    res.reserve(this->size());
    
    for (int i = this->size() - 1; i >= 0; i--) 
        res.push_back(static_cast<char>(this->get(i)));
    return res;
}

