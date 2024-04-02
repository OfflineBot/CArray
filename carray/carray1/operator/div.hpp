
#pragma once


#include "../carray1.hpp"
#include <cstddef>
#include <stdexcept>

template<typename T>
CArray::Array1<T> CArray::Array1<T>::operator/(Array1<T> &other) const {
    std::size_t size = this->_array.size();
    std::size_t other_size = other.size();
    if (size != other_size) throw std::out_of_range("Sizes dont match for Array1 / Array1");

    Array1<T> out(size);

    for (int i = 0; i < size; i++) {
        out[i] = this->_array[i] / other[i];
    }

    return out;
}

template<typename T>
void CArray::Array1<T>::operator/=(Array1<T> &other) {
    std::size_t size = this->_array.size();
    std::size_t other_size = other.size();
    if (size != other_size) throw std::out_of_range("Sizes dont match for Array1 / Array1");

    for (int i = 0; i < size; i++) {
        this->_array[i] /= other[i];
    }
}

template<typename T>
CArray::Array1<T> CArray::Array1<T>::operator/(T other) const {
    std::size_t size = this->_array.size();

    CArray::Array1<T> out(size);

    for (int i = 0; i < size; i++) {
        out[i] = this->_array[i] / other;
    }

    return out;
}

template<typename T>
void CArray::Array1<T>::operator/=(T other) {
    std::size_t size = this->_array.size();

    for (int i = 0; i < size; i++) {
        this->_array[i] /= other;
    }
}
