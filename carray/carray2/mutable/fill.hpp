
#pragma once

#include "../carray2.hpp"
#include <cstddef>

template<typename T>
void CArray::Array2<T>::fill_empty() {
    std::size_t row = this->_array.size();
    std::size_t col = this->_array[0].size(); 

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            this->_array[i][j] = T();
        }
    }
}

template<typename T>
void CArray::Array2<T>::fill(T item) {
    std::size_t row = this->_array.size();
    std::size_t col = this->_array[0].size(); 

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->_array[i][j] = item;
}

template<typename T>
void CArray::Array2<T>::replace(T item, T with) {
    std::size_t row = this->size()[0];
    std::size_t col = this->size()[1];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->_array[i][j] = this->_array[i][j] == item ? with : this->_array[i][j];
}