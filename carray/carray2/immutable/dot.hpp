
#pragma once

#include "../carray2.hpp"
#include <cstddef>
#include <stdexcept>

template<typename T>
CArray::Array2<T> CArray::Array2<T>::dot(CArray::Array2<T> &other) const {

    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];
    std::size_t row2 = other.size()[0];
    std::size_t col2 = other.size()[1];

    if (col1 != row2) throw std::length_error("Matrix does not match for multiplication");

    CArray::Array2<T> out(row1, col2);

    for (int i = 0; i < row1; i++) 
        for (int j = 0; j < col2; j++) 
            for (int k = 0; k < col1; k++) 
                out[i][j] += this->_array[i][k] * other[k][j];

    return out;

}