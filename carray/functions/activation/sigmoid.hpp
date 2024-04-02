//
// Created by Flint on 02.04.2024.
//

#ifndef CORRECT_CARRAY_SIGMOID_HPP
#define CORRECT_CARRAY_SIGMOID_HPP

#include "../functions.hpp"
#include <cmath>

template<typename T>
CArray::Array2<T> sigmoid(CArray::Array2<T> &data) {

    std::size_t row = data.size()[0];
    std::size_t col = data.size()[1];
    CArray::Array2<T> out(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            out[i][j] = 1 / (1 + std::exp(-data[i][j]));

    return out;

}

template<typename T>
CArray::Array2<T> deriv_sigmoid(CArray::Array2<T> &data) {

    std::size_t row = data.size()[0];
    std::size_t col = data.size()[1];
    CArray::Array2<T> out(row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            CArray::Array2<T> sig = sigmoid(data);

            out[i][j] = sig[i][j] * (1 - sig[i][j]);
        }
    }

    return out;
}

#endif //CORRECT_CARRAY_SIGMOID_HPP
