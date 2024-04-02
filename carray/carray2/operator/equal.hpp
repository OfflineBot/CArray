
#pragma once

#include "../carray2.hpp"
#include <cstddef>

template<typename T>
bool CArray::Array2<T>::operator==(CArray::Array2<T> &other) const {
    std::size_t row = this->_array.size();
    std::size_t col = this->_array[0].size();

    if (row != other.size()[0] || col != other.size()[1]) return false;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (this->_array[i][j] != other[i][j]) return false;
        }
    }

    return true;
}