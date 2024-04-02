
#pragma once

#include "../carray1.hpp"
#include <cmath>
#include <iostream>

template<typename T>
T CArray::Array1<T>::std() const {

    CArray::Array1<T> mean_squared(this->_array);
    T mean = mean_squared.mean();  

    mean_squared = mean_squared - mean;
    for (int i = 0; i < this->_array.size(); i++) {
        mean_squared *= mean_squared;
    }

    T out = mean_squared.sum();
    return std::sqrt(out / mean_squared.size());
}