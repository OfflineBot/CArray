
#pragma once

#include <iostream>
#include <cstddef>
#include "../carray2.hpp"

template<typename T>
void CArray::Array2<T>::print(void) {

    std::size_t rows = this->_array.size();
    std::size_t cols = this->_array[0].size();

    std::cout << "[\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "  [ ";
        for (int j = 0; j < cols - 1; j++) {
            std::cout << this->_array[i][j] << ", ";
        }
        std::cout << this->_array[i][cols - 1] << " ],\n";
    }

    std::cout << "] = Array2(" << rows << ", " << cols << ")" << std::endl;
}