# C++ References

Reference type is `an alias to an existing object in memory`.

- References **must be initialized**
- **Only available in C++**, but not in C
- Described with data type followed by an ampersand `&` as sample below:
```c++
int x = 2;

int& y = x; // Referencing
// Now, y holds the same value as x
```

**NOTE:**

Do not get confused with the use of ampersand `&` in reference type declaration (mentioned in this section), and the use of ampersand `&` as address-of-operator mentioned in [Pointers Chapter](./02_Pointers.md#assign-address-to-pointer).

Clarification as below:

```c++
//In referencing, & is used during initialization as sample line below

int& y = x; // & used for referencing the value x

//For pointer usage, & is never used for initialization as sample line below

int* ptr = &x; // & used to point the address of x
```

## C++ Function &mdash; Pass by Reference

```c++
#include <iostream>

void increment(int& reference) // Pass by reference
{
    reference++;
    std::cout << "Value in increment function: " << reference << std::endl; // x = 123 + 1 = 124
}

int main()
{
    int x = 123;
    std::cout << "Value of x before increment: " << x << std::endl; // x = 123

    increment(x); 

    std::cout << "Value of x after increment: " << x << std::endl; // x = 123 + 1 = 124

    return 0;
}
```