
#pragma once

#include <iostream>
#include <cstddef>
#include "../carray1.hpp"

template<typename T>
void CArray::Array1<T>::print(void) const {

    std::size_t size = this->_array.size();

    std::cout << "[ ";
    for (int i = 0; i < size - 1; i++) {
        std::cout << this->_array[i] << ", ";
    }
    std::cout << this->_array[size - 1] << " ] = Array1(" << size << ")" << std::endl;
}