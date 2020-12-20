#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cctype>

#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H

class String
{

private:
    size_t size = 0;
    size_t capacity = 0;
    char* str = nullptr;

    friend bool operator==(const String& a, const String& b) {
        return strcmp(a.str, b.str) == 0;
    }

    friend bool operator!=(const String& a, const String& b) {
        return !(a == b);
    }

    void updateCap() {
        size_t newCap = 4;
        while (newCap <= size) {
            newCap *= 2;
        }
        capacity = newCap * 2;
    }

public:
    String() = default;

    String(const char* s) {
        size = strlen(s);   
        updateCap();
        str = new char[capacity];
        std::memcpy(str, s, size);
    }
    
    String(char c) : size(1) {
        updateCap();
        str = new char[capacity];
        str[0] = c;
    }

    String(size_t n, char c) : size(n) {
        updateCap();
        str = new char[capacity];
        memset(str, c, size);
    }

    String(const String& s) : size(s.size) {
        updateCap();
        str = new char[capacity];
        std::memcpy(str, s.str, size);
    }


    void swapString(String& s) {
        std::swap(size, s.size);
        std::swap(capacity, s.capacity);
        std::swap(str, s.str);
    }

    String& operator= (String s) {
        swapString(s);
        return *this;
    }

    String& operator+=(const String& s) {
        for (size_t i = 0; i < s.size; ++i) {
            this->push_back(s[i]);
        }
        return *this;
    }

    void clear() {
        delete[] str;
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = '\0';
    }


    char& operator[](size_t index) {
        return str[index];
    }

    const char& operator[](size_t index) const {
        return str[index];
    }

    ~String() {
        delete[] str;
    }

    size_t length() const {
        return size;
    }

    bool empty() const {
        return (size == 0);
    }

    char front() const {
        return str[0];
    }

    char back() const {
        return str[size - 1];
    }

    char& front() {
        return str[0];
    }

    char& back() {
        return str[size - 1];
    }

    void push_back(char c) {
        if (size == 0) {
            delete[] str;
            size = 1;
            str = new char[capacity];
            str[0] = c;
        } else {
            str[size] = c;
            size++;
            if (size * 2 >= capacity) {
                capacity = capacity * 2;
                char* tmp = new char[capacity];
                std::memcpy(tmp, str, size);
                delete[] str;
                str = tmp;
            }
        }
    }

    void pop_back() {
        size--;
        if (size * 4 <= capacity) {
            capacity /= 2;
            char* tmp = new char[capacity];
            std::memcpy(tmp, str, size);
            delete[] str;
            str = tmp;
        }   
    }
    
    String substr(size_t start, size_t count) const {
        char* sub = new char[count + 1];
        std::memcpy(sub, str + start, count);
        String subStr(sub);
        return subStr;
    }

    size_t find(const String& t) const {
        for (size_t i = 0; i < size - t.length() + 1; ++i) {
            if (memcmp(str + i, t.str, t.length()) == 0) {
                return i;
            }
        }
        return size;
    }
    size_t rfind(const String& t) const {
        for (int i = size - t.length(); i >= 0; --i) {
            if (memcmp(str + i, t.str, t.length()) == 0) {
                return i;
            }
        }
        return size;
    }
};

std::ostream& operator<<(std::ostream& output, const String& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        output << s[i];
    }
    return output;
}

std::istream& operator>>(std::istream& input, String& str) {
    char c;
    str.clear();
    bool flag = true;
    while (flag) {
        c = input.get();
        flag = isspace(c);
    }

    while (!input.eof() && !isspace(c)) {
        str.push_back(c);
        c = input.get();
    }
    return input;
}

const String operator+(const String& a, const String& b) {
    String copy = a;
    copy += b;
    return copy;
}
const String operator+(const String& a, const char& b) {
    String copy(a);
    copy += String(b);
    return copy;
}

const String operator+(const char& a, const String& b) {
    String copy(a);
    copy += b;
    return copy;
}
#endif //STRING_LIBRARY_H
