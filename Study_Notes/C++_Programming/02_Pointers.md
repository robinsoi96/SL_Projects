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

## Appendix

Reference link as below:

- <a href="https://youtu.be/zuegQmMdy8M?si=GNMiiWYbrbt3_Ben">Pointers in C/C++ [Full Course]</a>