
#pragma once

#include "../carray2.hpp"
#include <vector>

template<typename T>
void CArray::Array2<T>::set(std::vector<std::vector<T>> vec) {

    for (int i = 0; i < vec.size(); i++) {
        CArray::Array1<T> slice(vec[0].size());
        for (int j = 0; j < slice.size(); j++) {
            slice[j] = vec[i][j];
        }
        this->_array.emplace_back(slice);
    }

}