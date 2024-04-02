
#pragma once

#include "../carray1.hpp"

template<typename T>
T CArray::Array1<T>::mean() const {

    T out = T();
    for (int i = 0; i < this->size(); i++) {
        out += this->_array[i];
    }
    out /= this->size();

    return out;
}