
#pragma once

#include "../carray2.hpp"
#include <random>
#include <cstddef>

template<typename T>
void CArray::Array2<T>::random_uniform(T min, T max) {

    std::size_t row = this->_array.size();
    std::size_t col = this->_array[0].size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> distr(min, max);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            this->_array[i][j] = distr(gen);
        }
    }
}