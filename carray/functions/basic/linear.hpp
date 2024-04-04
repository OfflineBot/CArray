
#pragma once

#include "../functions.hpp"

template<typename  T>
CArray::Array2<T> linear(CArray::Array2<T> &data, CArray::Array2<T> &weight, CArray::Array1<T> &bias) {
    CArray::Array2<T> out = data.dot(weight);
    out += bias;
    return out;
}
