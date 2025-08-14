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

**Pseudocode samples in C:**

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

int main()
{
    int x = 42;

    void* ptr = &x; // Declare void pointer

    std::cout << ptr << std::endl; // Get void pointer holding address value

    // To derefence, you need to typecast accordingly as example below
    std::cout << *(static_cast<int*>(ptr)) << std::endl; // Get dereferenced value

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

## Pointers as Function Arguments &mdash; Call by Reference

**Sample code in C:**

```c
#include <stdio.h>

void increment(int* x) // Call by reference
{
    *x += 1; // *x = *x + 1 (Dereference then increment by 1)
    printf("Address in the increment function = %d\n", x); // Address value = 1234
}

int main()
{
    int a = 3;
    // Let's say address of a is 1234

    printf("Value of a before increment = %d\n", a); // a = 3

    increment(&a); 

    printf("Value of a after increment = %d\n", a); // a = 3 + 1 = 4
    printf("Address after increment function = %d\n", x); // Address value = 1234

    return 0;

}
```

## Pointers and Arrays

### Quick Recap on Arrays

- Declare an array

```c
int arr[5]; // Declare an array to store 5 integer values
```

- Initialize an array
```c
// Initialize all values in the array
int arr1[5] = {2, 4, 6, 8, 10};

// Partially initialization
int arr2[5] = {2, 4, 6} // The remaining will be with value 0

// Skipping the size of array
int arr[] = {2, 4, 6}

//Initialize all elements in array to 0
int array[5] = {0}
```

- Accessing array index

**Pseudocode sample in C:**

```c
int arr[5] = {2, 4, 6, 8, 10};
// From the array above, there are 5 elements into it, and the index value will be from 0 to 4
// In short, 0 < index < size-1

printf("%d\n", arr[2]); // Here, prints 6 [3rd element ; at index position 2]
```

- Array also can be multidimensional.

```
<data_type> <array_name>[<size1>][<size2>]...[<sizeN>];
```

### Simple Implementation with Arrays and Pointers

**Pseudocode sample in C:**

```c
int arr[4] = {1, 2, 3, 4}; // Declare array
int* ptr = arr; // Declare pointer

printf("%d\n", arr); // Print address of 1st element of array, eqivalent to &arr[0]

printf("%d\n", *(arr)); // Print value of 1st element of array, eqivalent to arr[0], which is 1

printf("%d\n", arr + 2); // Print address of 3rd element of array, eqivalent to &arr[2]

printf("%d\n", *(arr + 2)); // Print value of 3rd element of array , eqivalent to arr[2], which is 3
```

### Arrays as Function Arguments

**Sample code in C:**

```c
#include <stdio.h>

void sorting(int* ptr, int size) // int* ptr == int ptr[]
{
    for (int i = 0; i < size; i++){
        printf("%d ", *(ptr + i));
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    int size = sizeof(arr) / sizeof(arr[0]); // Get the size of array
    sorting(ptr, size);
    // Output message: 1 2 3 4 5
}
```

## Appendix

Reference link as below:

- <a href="https://youtu.be/zuegQmMdy8M?si=GNMiiWYbrbt3_Ben">Pointers in C/C++ [Full Course]</a>