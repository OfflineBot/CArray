
#pragma once

#include "../carray2.hpp"

#include <vector>

template<typename T>
std::vector<int> CArray::Array2<T>::size() const {
    std::vector<int> out(2);
    out[0] = this->_array.size();
    out[1] = this->_array[0].size();
    return out;
}