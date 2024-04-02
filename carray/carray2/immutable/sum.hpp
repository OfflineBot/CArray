
#pragma once

#include "../carray2.hpp"
#include <cstddef>

/// @brief Sum Array2 at axis 0
/// @tparam T 
/// @return 
template<typename T>
CArray::Array1<T> CArray::Array2<T>::sum() const {

    std::size_t row = this->size()[0];
    std::size_t col = this->size()[1];

    CArray::Array1<T> out(col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            out[j] += this->_array[i][j];
        }
    }

    return out;
}
