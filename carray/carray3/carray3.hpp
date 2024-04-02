
#pragma once

#include <cstddef>
#include <vector>

namespace CArray
{
    template <typename T>
    class Array3 {
    private:
        std::vector<CArray::Array2<T>> _array;

    public:
        Array3(std::size_t depths, std::size_t rows, std::size_t cols);
        Array3(std::initializer_list<std::initializer_list<std::initializer_list<T>>> list);

        void print();

        Array2<T>& operator[](int index);
        Array2<T>& operator[](int index) const;

    };
}

#include "./operator/operator.hpp"
#include "./property/constructor.hpp"
#include "./print/print.hpp"