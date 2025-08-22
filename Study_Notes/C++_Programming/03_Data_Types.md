# Data Types in C++

C++ has the same data types as C mentioned in [C Data Types](../C_Programming/11_Data_Types.md), except there are some differences mentioned in the chapters below.


## Boolen

When mentioning boolen is not available in C, it means boolen is not available in the default standard library which used by most beginners, e.g. `<stdio.h>` in C. For C, you need to call another library `<stdbool.h>` to enable boolen.

However, in C++, `<iostream>` most used standary library itself has boolen, just like other data types e.g. int, char, float, double.

`boolen`, need to declare with `true` or `false`. Output will print `1(for true)` and `0(for false)`.

**NOTE:** If boolen is not declared, it will result in undefined behaviour. Actually, applies to all variables as well.

## Strings in C++

We can store string literals inside a `std::string` type, which will need us to **include `<string>` header**.

### Concatenating Strings

We can add a string lieral to our string

```c++
#include <iostream>
#include <string>

int main()
{
    std::string s = "Hello ";
    s += "World";
    std::cout << s; //Print "Hello World"
    return 0;
}
```

We can add a character to our string as well

```c++
#include <iostream>
#include <string>

int main()
{
    std::string s = "Hello";
    char c = '!';
    s += c;
    std::cout << s; //Print "Hello!"
    return 0;
}
```

### Accessing Characters in String

```c++
std::string s = "Hello World.";

// Method 1 to access a character in string
char c1 = s[0]; // c1 = 'H'

// Method 2 to access a character in string
char c2 = s.at(1); // c2 = 'e'
```

### String Input

The preferred way of accepting a string from standard input is via `std::getline` function, which **take `std::cin` and the string as parameters**.

```c++
std::getline(std::cin, s); // Method to enter string with spaces, where s is string
```

### A Pointer to a String

A string has a member function `.c_str()` which returns a pointer to its first element.

It is also said it returns a pointer to a null-erminated character array our string is made of.

This member function is of type `const char*` and is useful when we want to pass our `std::string` variable to a function accepting a `const char*` parameter.

```c++
#include <iostream>
#include <string>

int main()
{
    std::string s = "Hello World.";
    std::cout << s.c_str(); // Prints "Hello World."
    // Because const char* s = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '.' ,'\0'}

    return 0;
}
```

### Substrings

`.substr()` member function is used to return substring from a string.

Format of this function: `.substr(`*`starting_index_position`*`,`*`length`*`)`

```c++
std::string s = "Hello World.";
std::string mySubstring = s.substr(6,5);
std::cout << mySubstring; // Prints "World"
```

### Finding a Substring

To find a substring in a string, we use `.find()` member function, which is of type `std::string::size_type`.

- **If the substring is found**, the function will **return the index position of the first found substring** (or the index position of the first character of the first substring found)
- If **not found**, it **returns a value that is `std::string::npos`**
- `.find()` can also be used to **find a character**

```c++
#include <iostream>
#include <string>

int main()
{
    std::string s = "This is a Hello World string."; // Main String

    std::string stringToFind = "Hello"; // Substring

    std::string::size_type found = s.find(stringToFind); // Function to find the substring
    // This also can be used to find a character

    if (found != std::string::npos){
        std::cout << "Substring found at position: " << found;
    } else {
        std::cout << "The substring is not found.";
    }

    // From the code base above, the output will print as below:
    //"Substring found at position: 10"
}
```

## Automatic Type Deduction in C++

We can use `auto` specifier when the variable data type is hard to deduce manually or cumbersome to type due to its length

```c++
auto c = 'a'; // c is char type

auto x = 123; // x is int type

auto d = 123.456 / 789.10; // d is double

auto& y = x; // y is of int& type (referencing)

const auto z = 23; // z is of const int type
```

## Constants

### `const` (Constant)

To declare a constant variable, we just need to add `const` in front of the data type of the variable.

Constants are **not modifiable** and **must be initialized**.

```c++
const int x = 5;
x++; // Error, because constant is not modifiable

const int y; // Error, because constant must be initialized

const int z = 123; // OK, because constant is initialized

// NOTE: const int x and int x are 2 different types
```

### `constexpr` (Constant Expression) in C++

Constant expression (`constexpr`) is a **constant that can be evaluated at compile time**.

This means that if the compiler has enough information to compute the value during compilation, it can perform the calculation and replace the expression with the result, potentially improving runtime performance.

It is a way to ensure that certain computations happen at compile time, especially when working with constants or functions whose results are known at compile time. 

Initializers for constant expressions can be evaluated at compile time and must themselves be constant expressions.

```c++
constexpr int n = 123; // OK, 123 is a compile-time constant expression

constexpr double d = 456.78; // OK, 456.78 is a compile-time constant expression

constexpr double d2 = d; // OK, d is a constant expression

int x = 123;

constexpr int n2 = x; // Compile-time error, because the value of x is not known during compile-time
```

## Extras

For character types and integer types mentioned in [C Data Types](../C_Programming/11_Data_Types.md), there are other of thier types as well.

For example:

- There are other character types like `whar_t`, `char16_t`, `char32_t`, etc.
- There are also fixed-width integer types like `int64_t`, `uint16_t`, etc.
- All these extra information, can search on internet to study for more.