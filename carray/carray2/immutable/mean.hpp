
#pragma once

#include "../carray2.hpp"
#include "../../carray.hpp"
#include <cstddef>

/// @brief Mean the Array2 (on axis 0)
/// @tparam T 
/// @return 
template<typename T>
CArray::Array1<T> CArray::Array2<T>::mean() const {

    std::size_t row = this->size()[0];
    std::size_t col = this->size()[1]; 

    CArray::Array1<T> out(col);

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            out[i] += this->_array[j][i];
        }
        out[i] = out[i] / row;
    }

    return out;
}