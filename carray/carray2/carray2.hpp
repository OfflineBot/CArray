
#pragma once

#include <vector>
#include <cstddef>
#include "../carray.hpp"

namespace CArray {

    template <typename T>
    class Array2 {
    private:
        std::vector<CArray::Array1<T>> _array;

    public:
        explicit Array2(std::vector<std::vector<T>> vec);
        Array2(std::initializer_list<std::initializer_list<T>> list);
        Array2(std::size_t rows, std::size_t cols);
        ~Array2();

        std::vector<int> size() const;
        void set(std::vector<std::vector<T>> vec);

        void print();

        void fill_empty();
        void fill(T item);
        void replace(T item, T with);
        void random_uniform(T min, T max);

        Array1<T> mean() const;
        Array1<T> std() const;
        Array1<T> sum() const;
        Array2<T> dot(Array2<T> &other) const;
        Array2<T> t() const;

        // --- OPERATOR ---

        Array1<T>& operator[](int index);
        Array1<T>& operator[](int index) const;
        bool operator==(Array2<T> &other) const;

        Array2<T> operator+(Array2<T> &other) const; 
        Array2<T> operator-(Array2<T> &other) const; 
        Array2<T> operator*(Array2<T> &other) const;
        Array2<T> operator/(Array2<T> &other) const;

        void operator+=(Array2<T> &other); 
        void operator-=(Array2<T> &other); 
        void operator*=(Array2<T> &other);
        void operator/=(Array2<T> &other);

        Array2<T> operator+(Array1<T> &other) const; 
        Array2<T> operator-(Array1<T> &other) const; 
        Array2<T> operator*(Array1<T> &other) const;
        Array2<T> operator/(Array1<T> &other) const;

        void operator+=(Array1<T> &other); 
        void operator-=(Array1<T> &other); 
        void operator*=(Array1<T> &other);
        void operator/=(Array1<T> &other);

        Array2<T> operator+(T other) const;
        Array2<T> operator-(T other) const;
        Array2<T> operator*(T other) const;
        Array2<T> operator/(T other) const;

        void operator+=(T other); 
        void operator-=(T other); 
        void operator*=(T other);
        void operator/=(T other);
    };
}

#include "./property/property.hpp"
#include "./print/print.hpp"
#include "./operator/operator.hpp"
#include "./mutable/mutable.hpp"
#include "./immutable/immutable.hpp"