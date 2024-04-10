
#pragma once

#include "../../carray.hpp"

template<typename T>
std::size_t argmax(CArray::Array1<T> &data) {
    std::size_t size = data.size();

    T high_value = data[0];
    std::size_t index = 0;

    for (int i = 1; i < size; i++) {
        if (data[i] > high_value)  {
            high_value = data[i];
            index = i;
        }
    }

    return index;
}
