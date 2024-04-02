
#pragma once

#include "../carray1.hpp"
#include <random>
#include <cstddef>

/// @brief Random values from min to max
/// @tparam T 
/// @param min 
/// @param max 
template<typename T>
void CArray::Array1<T>::random_uniform(T min, T max) {

    std::size_t size = this->_array.size();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist(min, max);

    for (int i = 0; i < size; i++) {
        this->_array[i] = dist(gen);
    }

}
