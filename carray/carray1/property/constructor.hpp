
#pragma once

#include <cstddef>
#include <vector>
#include "../carray1.hpp"

template<typename T>
CArray::Array1<T>::~Array1() { }

template<typename T>
CArray::Array1<T>::Array1(std::size_t size) { 
    this->_array.resize(size);

    for (int i = 0; i < size; i++) {
        this->_array[i] = T();
    }
}

template<typename T>
CArray::Array1<T>::Array1(std::initializer_list<T> list) : _array(list) {}

template<typename T>
CArray::Array1<T>::Array1(std::vector<T> vec) {
    this->_array = vec;
}