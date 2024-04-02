
#pragma once

#include "../carray1.hpp"
#include <cstddef>
#include <stdexcept>

template<typename T>
T& CArray::Array1<T>::operator[](int index) {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");

    return this->_array[index];
}

template<typename T>
T CArray::Array1<T>::operator[](int index) const {
    if (index >= this->_array.size()) throw std::out_of_range("Index out of range");

    return this->_array[index];
}

