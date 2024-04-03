
#pragma once

#include "../carray2.hpp"
#include "../../carray.hpp"
#include <stdexcept>

template<typename T>
CArray::Array1<T>& CArray::Array2<T>::operator[](int index) {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");
    return this->_array[index];
}

template<typename T>
const CArray::Array1<T>& CArray::Array2<T>::operator[](int index) const {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");
    return this->_array[index];
}