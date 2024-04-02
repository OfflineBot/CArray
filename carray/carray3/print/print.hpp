
#pragma once

#include "../carray3.hpp"
#include <cstddef>
#include <iostream>

template<typename T>
void CArray::Array3<T>::print(void) {

    std::size_t depth = this->_array.size(); 
    std::size_t row = this->_array[0].size()[0];
    std::size_t col = this->_array[0].size()[1];


    std::cout << "[\n";
    for (int i = 0; i < depth; i++) {
        std::cout << "  [\n";
        for (int j = 0; j < row; j++) {
            std::cout << "      [ ";
            for (int k = 0; k < col - 1; k++) {
                std::cout << this->_array[i][j][k] << ", ";
            }
            std::cout << this->_array[i][j][col - 1] << " ],\n";
        }
        std::cout << "  ],\n";
    }

    std::cout << "] = Array3(" << depth << ", " << row << ", " << col << ")" << std::endl; 
}