
#pragma once

#include "../carray1.hpp"
#include <cstddef>

template<typename T>
T CArray::Array1<T>::sum() const {
    std::size_t size = this->_array.size();

    T sum = T();
    for (int i = 0; i < size; i++) {
        sum += this->_array[i];
    }

    return sum;
}