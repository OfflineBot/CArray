
#pragma once

#include "../carray2.hpp" 
#include "../../carray.hpp" 
#include <cstddef> 
#include <stdexcept>

template<typename T>
CArray::Array2<T> CArray::Array2<T>::operator*(CArray::Array2<T> &other) const {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];
    std::size_t row2 = other.size()[0];
    std::size_t col2 = other.size()[1];

    if(row1 != row2 || col1 == col2) throw std::out_of_range("Matricies dont match");

    CArray::Array2<T> out = *this;
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            out[i][j] *= other[i][j];

    return out;
}

template<typename T>
CArray::Array2<T> CArray::Array2<T>::operator*(Array2<float> other) const {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];
    std::size_t size = other.size();

    if(col1 != size) throw std::out_of_range("Matricies dont match");

    CArray::Array2<T> out = *this;
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            out[i][j] *= other[j];

    return out;
}

template<typename T>
CArray::Array2<T> CArray::Array2<T>::operator*(T other) const {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];

    CArray::Array2<T> out = *this;
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            out[i][j] *= other;

    return out;
}


template<typename T>
void CArray::Array2<T>::operator*=(CArray::Array2<T> &other) {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];
    std::size_t row2 = other.size()[0];
    std::size_t col2 = other.size()[1];

    if(row1 != row2 || col1 != col2) throw std::out_of_range("Matricies dont match");

    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            this->_array[i][j] *= other[i][j];
}

template<typename T>
void CArray::Array2<T>::operator*=(CArray::Array1<T> &other) {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];
    std::size_t size = other.size();

    if(col1 != size) throw std::out_of_range("Matricies dont match");

    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            this->_array[i][j] *= other[j];
}

template<typename T>
void CArray::Array2<T>::operator*=(T other) {
    std::size_t row1 = this->size()[0];
    std::size_t col1 = this->size()[1];

    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            this->_array[i][j] *= other;
}
