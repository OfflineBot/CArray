
#pragma once

#include "../carray2.hpp"

template<typename T>
CArray::Array2<T> CArray::Array2<T>::t() const {
    std::size_t row = this->size()[0];
    std::size_t col = this->size()[1];
    CArray::Array2<T> out(col, row);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            out[j][i] = this->_array[i][j];

    return out;
}

