# Data Types in C++

C++ has the same data types as C mentioned in [C Data Types](../C_Programming/11_Data_Types.md), except there are some differences mentioned in the chapters below.


## Boolen

When mentioning boolen is not available in C, it means boolen is not available in the default standard library which used by most beginners, e.g. `<stdio.h>` in C. For C, you need to call another library `<stdbool.h>` to enable boolen.

However, in C++, `<iostream>` most used standary library itself has boolen, just like other data types e.g. int, char, float, double.

`boolen`, need to declare with `true` or `false`. Output will print `1(for true)` and `0(for false)`.

**NOTE:** If boolen is not declared, it will result in undefined behaviour. Actually, applies to all variables as well.

## Extras

For character types and integer types mentioned in [C Data Types](../C_Programming/11_Data_Types.md), there are other of thier types as well.

For example:

- There are other character types like `whar_t`, `char16_t`, `char32_t`, etc.
- There are also fixed-width integer types like `int64_t`, `uint16_t`, etc.
- All these extra information, can search on internet to study for more.