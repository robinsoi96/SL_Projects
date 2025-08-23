# Scope and Lifetime

## Scope

Scope of a variable is the region of code within which a variable is accessible, e.g. `global scope`, `local scope`, `block scope`, `nested scope`, etc

## Lifetime

`Lifetime` of a variable refers to the **time it spends in memory**. Lieftime is **determined by a so-called storage duration**.

### Automatic Storage Duration

- A duration where **memory for an object is automatically allocated at the beginning of a block** and **deallocated when the code block ends**
- This is also called `stack memory`; objects are allocated on the `stack`
- In this case, the object's **lifetime is determined by its scope**
- All local objects have this storage duration

### Dynamic Storage Duration

- A duration where **memory for an object is manually allocated and manually deallocated**
- This kind of storage is often referred to as `heap memory` (also known as `free store`)
- The **lifetime of an object is not determined by the scope** in which the object was defined
- In C, we use operator like `malloc`, `calloc`, `realloc`, `free`
- In C++, we use operator like `new`, `delete`, and also use `smart pointers`
- For more information on dynamic memory allocation, may refer to [C/C++ Pointer Chapter](./02_Pointers.md)

### Static Storage Duration

- When an objet declaration is prepended with `static` specifier, the storage for a static object is **allocated when the program starts** and **deallocated when the program ends**
- They are stored in `data segment of memory`
- The types of variable include:
    - `global variables`
    - variables declared with `static` keyword
    - variables with external or internal linkage
