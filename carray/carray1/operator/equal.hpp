
#pragma once

#include "../carray1.hpp"

#include <cstddef>
#include <stdexcept>

template<typename T>
bool CArray::Array1<T>::operator==(Array1<T> &other) const {
    std::size_t size = this->_array.size();
    if (size != other.size()) return false;

    for (int i = 0; i < size; i++) {
        if (this->_array[i] != other[i]) return false;
    }

    return true;
}