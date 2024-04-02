
#pragma once

#include <cstddef>
#include <vector>
#include "../carray2.hpp"

template<typename T>
CArray::Array2<T>::~Array2() { }

template<typename T>
CArray::Array2<T>::Array2(std::size_t rows, std::size_t cols) { 

    for (int i = 0; i < rows; i++) {
        CArray::Array1<T> slice = CArray::Array1<T>(cols);
        this->_array.emplace_back(slice);
    }
}

template<typename T>
CArray::Array2<T>::Array2(std::initializer_list<std::initializer_list<T>> list) {
    std::vector<std::vector<T>> out_vec;
    for (const auto &sublist : list) {
        out_vec.emplace_back(sublist);
    }

    this->set(out_vec);
}

template<typename T>
CArray::Array2<T>::Array2(std::vector<std::vector<T>> vec) {
    this->set(vec);
}