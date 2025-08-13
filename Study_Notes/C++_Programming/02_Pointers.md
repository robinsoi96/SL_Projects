# Pointers

**NOTE:**

Pointers for C and C++ are having the same core concepts.

## Introduction

`Pointer` is a special `variable that holds the memory address of another variable`, rather than strong a direct value itself.

Pointers allows programs to access and manipulate data in memeory efficiently, making them a key feature for system-level programming and dynamic memory management.

When we access a pointer directly, we get the address it holds, not the actual data stored at that location.

## Declare Pointer

```c
int* ptr;
```

From the example above, pointer `ptr` is declared.

**NOTE:**

Syntax to declare a new pointer:

```
<data_type>* <ptr_variable_name>;
```

## Assign Address to Pointer

```c
int val = 22;
int* ptr = &val; // '&' indicates get memory address of val
```

From the example above, pointer `ptr` stores the address of variable `val` using **addressof operator(`&`)**

**IMPORTANT NOTE:**

- `Both pointer and variable should be of the same type`. Else, type mismatch error occurs.

## Dereferencing

```c
int va1 = 22;
int* ptr = &val; // Declare a pointer and then assign address to the pointer in 1 line

printf("%d\n", *ptr); // Get value of val using * operator --> Deferencing

printf("%d\n", ptr); // Get the memory address value of val
```

or

```c
int* ptr; // Declare pointer first
int va1 = 22;
ptr = &val; // Then, assign address to pointer

printf("%d\n", *ptr); // Get value of val using * operator --> Deferencing

printf("%d\n", ptr); // Get the memory address value of val
```

From the examples, you can see **`*`** operator is used to dereference to **get the value present at the memory address pointed by pointer**.

## Void Pointer

`Void pointer` (**void***) is a special type of pointer that has **no associated data type**.

It can hold the address of any data type, making it useful for generic programming.

However, since the type is unknown, the compiler doesn't know how many bytes to read or how to interpret the data.

Therefore, **a void pointer cannot be directly dereferenced**. It must first be explicilty typecast to the appropriate pointer type.

**Sample Codes:**

- C

```c
#include <stdio.h>

int main()
{
    int x = 42;

    void* ptr = &x; // Declare void pointer

    printf("%d\n", ptr); // Get void pointer holding address value

    // To derefence, you need to typecast accordingly as example below
    printf("%d\n", *(int*)ptr); // Get dereferenced value

    return 0;
}
```

- C++

```c++
#include <iostream>

using namespace std;

int main()
{
    int x = 42;

    void* ptr = &x; // Declare void pointer

    cout << ptr << endl; // Get void pointer holding address value

    // To derefence, you need to typecast accordingly as example below
    cout << *(static_cast<int*>(ptr)) << endl; // Get dereferenced value

    return 0;
}
```

## Changing Pointer Type

You can change the pointer type as the sample pseudocode below. However, if data type of pointer changed has different number of bytes, you will see the dereference value differ as sample below.

**Pseudocode sample in C:**

```c
int a = 1025;
int* ptr;
ptr = &a;

printf("%d\n", ptr) // Here, you get address of a

printf("%d\n", *ptr) // Here, you get 1025

// Changing pointer type
char* p0;
p0 = (char*)ptr; // Typecasting

printf("%d\n", p0) // Here, still print address of a, because still pointing at the same starting address

printf("%d\n", *p0) // Here, you only get 1
/*
Because... 
1025 => 00000000 00000000 00000100 00000001 (in binary)
Since char only holds 1 byte (8 bits), therefore, *p0 = 1 [00000001, 1 byte starting from LSB]
*/
```

## Pointer Arithmetic

### Incrementing a Pointer

**Pseudocode sample in C:**

```c
int a = 22;
int* ptr = &a; // Let's say address of a is 1000

printf("%d\n", ptr); // Here, print 1000

ptr++; // Pointer increment

printf("%d\n", ptr); // Here, print 1004
// Because int has 4 bytes
// Therefore, 1000 + 4 = 1004
```

### Decrementing a Pointer

**Pseudocode sample in C:**

```c
int a = 22;
int* ptr = &a; // Let's say address of a is 1000

printf("%d\n", ptr); // Here, print 1000

ptr--; // Pointer decrement

printf("%d\n", ptr); // Here, print 996
// Because int has 4 bytes
// Therefore, 1000 - 4 = 996
```

### Addition of Constant from Pointer

**Pseudocode sample in C:**

```c
int a = 22;
int* ptr = &a; // Let's say address of a is 1000

printf("%d\n", ptr); // Here, print 1000

ptr = ptr + 5; // Addition by 5

printf("%d\n", ptr); // Here, print 1020
// Because int has 4 bytes
// Therefore, 1000 + 5(4) = 1020
```

### Subtraction of Constant from Pointer

**Pseudocode sample in C:**

```c
int a = 22;
int* ptr = &a; // Let's say address of a is 1000

printf("%d\n", ptr); // Here, print 1000

ptr = ptr - 5; // Subtract by 5

printf("%d\n", ptr); // Here, print 980
// Because int has 4 bytes
// Therefore, 1000 - 5(4) = 980
```

## Pointer to Pointer

We can have **multi-level pointers**, such as \*\*\*ptr3, \*\*\*\*ptr4 and so on.

The most popular of them is **double pointer** (`pointer to pointer`). 

It stores the memory address of another pointer. Instead of pointing to a data value, they point to another pointer.

Pseucode below shows implementation of pointer to pointer.

**Pseudocode sample in C:**

```c
int val = 22;
int* ptr = &val;
int** ptr2 = &ptr; // pointer to pointer

printf("%d\n", ptr2); // Get address of ptr
printf("%d\n", *ptr2); // Get address of val
printf("%d\n", **ptr2); // Get value of val
```

## Appendix

Reference link as below:

- <a href="https://youtu.be/zuegQmMdy8M?si=GNMiiWYbrbt3_Ben">Pointers in C/C++ [Full Course]</a>