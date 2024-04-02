
#pragma once

#include "../carray1.hpp"
#include <cstddef>

/// @brief Fill Array with default values
template<typename T>
void CArray::Array1<T>::fill_empty() {
    std::size_t size = this->_array.size();

    for (int i = 0; i < size; i++) {
        this->_array[i] = T();
    }
}

/// @brief Fill Array with given item
/// @param item 
template<typename T>
void CArray::Array1<T>::fill(T item) {
    std::size_t size = this->_array.size();

    for (int i = 0; i < size; i++) {
        this->_array[i] = item;
    }
}

/// @brief Replace values with new values
/// @param item select value
/// @param with new value
template<typename T>
void CArray::Array1<T>::replace(T item, T with) {
    std::size_t size = this->size();

    for (int i = 0; i < size; i++)
        this->_array = this->_array[i] == item ? with : this->_array[i];
}