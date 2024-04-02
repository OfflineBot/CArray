
#pragma once

#include "../carray1.hpp"
#include <cstddef>

template<typename T>
std::size_t CArray::Array1<T>::size() const {
    return this->_array.size();
}
