
#include "./carray/carray.hpp"

using namespace CArray;

int main() {



    Array2<float> array2 = {
            {1, 2, 3},
            {4, 5, 6}
    };
    Array1<float> array1(3);
    array1 += 1;
    array2 += array1;
    array2.print();

    return 0;
}
