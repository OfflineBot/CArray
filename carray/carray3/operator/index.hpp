
#pragma once

#include "../carray3.hpp"
#include "../../carray.hpp"
#include <stdexcept>

template<typename T>
CArray::Array2<T>& CArray::Array3<T>::operator[](int index) {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");
    return this->_array[index];
}

template<typename T>
CArray::Array2<T>& CArray::Array3<T>::operator[](int index) const {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");
    return this->_array[index];
}