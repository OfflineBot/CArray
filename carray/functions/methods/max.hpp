
#pragma once

#include "../../carray.hpp"

template<typename T>
T max(CArray::Array1<T> &data) {
    std::size_t size = data.size();

    T high_value = data[0];
    for (int i = 1; i < size; i++) {
        if (high_value < data[i]) {
            high_value = data[i];
        }
    }

    return high_value;
}