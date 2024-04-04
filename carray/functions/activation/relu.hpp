
#pragma once

#include "../functions.hpp"

template<typename T>
CArray::Array2<T> relu(const CArray::Array2<T> &data) {

    std::size_t row = data.size()[0];
    std::size_t col = data.size()[1];
    CArray::Array2<T> out(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            out[i][j] = data[i][j] > 0 ? data[i][j] : 0;

    return out;
}

template<typename T>
CArray::Array2<T> deriv_relu(const CArray::Array2<T> &data) {

    std::size_t row = data.size()[0];
    std::size_t col = data.size()[1];
    CArray::Array2<T> out(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            out[i][j] = data[i][j] > 0 ? 1 : 0;

    return out;
}
