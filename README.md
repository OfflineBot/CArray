# CArray
## Array library for C++

## Including:
- Array1: one dimensional Array
- Array2: two dimensional Array
- Array3: three dimensional Array
- Functions for AI Development

## How to use:
Exmaple:
```cpp
using namespace CArray;

Array2<float> array2 = {
    {1, 2, 3},
    {4, 5, 6}
};
Array1<float> array1(3);
array1 += 1;
array2 += array1;
array2.print();
```
Output:
```cpp
[
  [ 2, 3, 4 ],
  [ 5, 6, 7 ],
] = Array2(2, 3)
```
