//
// Created by Flint on 02.04.2024.
//

#ifndef CORRECT_CARRAY_MSE_LOSS_HPP
#define CORRECT_CARRAY_MSE_LOSS_HPP

#include "../functions.hpp"

template<typename T>
T mse_loss(CArray::Array2<T> &output, CArray::Array2<T> &truth) {
    CArray::Array2<T> error = output - truth;
    error *= error;
    CArray::Array1<T> arr1_mean = error.mean();
    return arr1_mean.mean();
}

#endif //CORRECT_CARRAY_MSE_LOSS_HPP
