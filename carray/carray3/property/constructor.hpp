
#pragma once

#include "../carray3.hpp"
#include <cstddef>
#include <vector>
#include <utility>

template<typename T>
CArray::Array3<T>::Array3(std::size_t depth, std::size_t row, std::size_t col) {
    this->_array.resize(depth);

    for (int i = 0; i < depth; i++) {
        this->_array[i].resize(row);
        for (int j = 0; j < row; j++) {
            this->_array[i][j].resize(col);
            for (int k = 0; k < col; k++) {
                this->_array[i][j][k] = T();
            }
        }
    }
}

template<typename T>
CArray::Array3<T>::Array3(std::initializer_list<std::initializer_list<std::initializer_list<T>>> list) {

    for (const auto &sublist : list) {
        std::vector<std::vector<T>> temp;
        for (const auto &subsublist : sublist) {
            std::vector<T> temp2;
            for (const auto &element : subsublist) {
                temp2.emplace_back(element);
            } 
            temp.emplace_back(std::move(temp2));
        }
        this->_array.emplace_back(std::move(temp));
    }

}