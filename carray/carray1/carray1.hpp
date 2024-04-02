
#pragma once

#include <vector>
#include <cstddef>

namespace CArray {

    template <typename T>
    class Array1 {
    private:
        std::vector<T> _array;

    public:
        explicit Array1(std::size_t size);
        Array1(std::initializer_list<T> list);
        explicit Array1(std::vector<T> vec);
        ~Array1();

        void print() const;

        void fill_empty();
        void fill(T item);
        void replace(T item, T with);
        void random_uniform(T min, T max);

        T mean() const;
        T std() const;
        T sum() const;

        std::size_t size() const; // NOLINT(*-use-nodiscard)
        
        // --- OPERATOR ---

        bool operator==(Array1<T> &other) const;

        T& operator[](int index);
        T operator[](int index) const;

        Array1<T> operator+(Array1<T> &other) const;
        Array1<T> operator-(Array1<T> &other) const;
        Array1<T> operator*(Array1<T> &other) const;

        void operator+=(Array1<T> &other);
        void operator-=(Array1<T> &other);
        void operator*=(Array1<T> &other);

        Array1<T> operator+(T other) const;
        Array1<T> operator-(T other) const;
        Array1<T> operator*(T other) const;

        void operator+=(T other);
        void operator-=(T other);
        void operator*=(T other);
    };
}

#include "./mutable/mutable.hpp"
#include "./immutable/immutable.hpp"
#include "./operator/operator.hpp"
#include "./property/property.hpp"
#include "./print/print.hpp"