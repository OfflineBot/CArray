//
// Created by Flint on 02.04.2024.
//

#ifndef CORRECT_CARRAY_LINEAR_HPP
#define CORRECT_CARRAY_LINEAR_HPP

#include "../functions.hpp"

template<typename  T>
CArray::Array2<T> linear(CArray::Array2<T> &data, CArray::Array2<T> &weight, CArray::Array1<T> &bias) {
    CArray::Array2<T> out = data.dot(weight);
    out += bias;
    return out;
}

#endif //CORRECT_CARRAY_LINEAR_HPP
