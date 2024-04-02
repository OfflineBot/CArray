
#pragma once

#include "../carray2.hpp"
#include <cmath>

/// @brief Calculating the Standard Deviation at axis 0
/// @tparam T 
/// @return 
template<typename T>
CArray::Array1<T> CArray::Array2<T>::std() const {

    CArray::Array2<T> mean_squared = *this;
    CArray::Array1<T> mean = this->mean();

    for (int i = 0; i < this->size()[0]; i++) {
        for (int j = 0; j < this->size()[1]; j++) {
            mean_squared[i][j] -= mean[j];
            mean_squared[i][j] *= mean_squared[i][j];
        }
    }
        

    CArray::Array1<T> out = mean_squared.mean();
    for (int i = 0; i < out.size(); i++) {
        out[i] = std::sqrt(out[i]);
    }

    return out;
}