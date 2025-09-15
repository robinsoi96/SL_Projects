# Enumerations

`Enumeration`, or `enum` for short, is a type whose values are symbolic, user-defined, named constants called `enumerators`.

- Consists of a set of named integer constants
- Helps in assigning meaningful names to integer values to improve code readability and maintainability

There are 2 types of enumerations:

- `Unscoped enum` [Available for C and C++]
- `Scoped enum` [Available for C++ only]

<br>

## `Unscoped Enum` [Applicable to C and C++]

### Similarities in both C and C++

- Syntax to define unscoped enum with default values:

```c
enum enum_name
{
    name1,
    name2,
    ...,
    nameN
};

// By default, name1 = 0, name2 = 1, ... accordingly
```

- Syntax to define value manually in unscoped enum:

```c
enum enum_name
{
    name1 = v1,
    name2,
    name3,
    name4 = v2,
    name5,
    ...,
    nameN
};

// For this case,
// name1 = v1, name2 = v1 + 1, name3= v1 + 2
// name4 = v2, name5 = v2 + 1, ....

// In short, the next name will be automatically assigned a value by incrementing the previous name's value by 1

// NOTE: value assigned manually must integers only
```

- `name` in different `enum` cannot be the same

```c
enum enum_name1
{
    name1,
    name2
}

enum enum_name2
{
    name3,
    name1 // Error, because name1 already available in enum_name1
}
```

- All `name` in `enum` are integers

### Differences in C vs C++

- In C++, you can straight away use enum_name without the need to add `enum` keyword for initialization in main function

```c++
enum_name varName = name1;
```

- In C, you need to add `enum` for initialization

```c
enum enum_name varName = name1;
```

- In C, use `typedef` keyword when declaring `enum` if do not want to add `enum` for initialization

```c
#include <stdio.h>

// Defining enum with typedef
typedef enum direction
{
    EAST, NORTH, WEST, SOUTH
}DIR; // NOTE: Nickname "DIR" (example) is must to be provided

int main()
{
    DIR dir = NORTH; // Initialization, here, can see no enum keyword needed

    printf("%d", d); // Returns 1

    return 0;
}
```

<br>

## `Scoped Enum` [Applicable to C++ only]

- Also known as `enum class`

- Generic syntax to declare scoped enum:

```c++
enum class enum_name : data_type
{
    name1 = value1;
    name2 = value2;
    ...,
    nameN = valueN
};
```

- If only for integer types, you can do as below for declaration syntax:

```c++
enum class enum_name
{
    name1,
    name2,
    ...,
    nameN
};

// By default, name1 = 0, name2 = 1, ... accordingly
```

- For enum class with integer values, you can randomly assign manually for some values in it

```c++
enum class enum_name
{
    name1 = v1,
    name2,
    name3,
    name4 = v2,
    name5,
    ...,
    nameN
};

// For this case,
// name1 = v1, name2 = v1 + 1, name3= v1 + 2
// name4 = v2, name5 = v2 + 1, ....

// In short, the next name will be automatically assigned a value by incrementing the previous name's value by 1

// NOTE: value assigned manually must integers only
```

- **NOTE:** same `name` cannot redeclare within the same `enum class`

```c++
enum class enum_name
{
    name1,
    name2,
    name1 // ERROR, cannot redeclare in the same enum class
};
```

- It is ok to have same `name` from different `enum class`

```c++
enum class A
{
    a,
    b,
    c
};

enum class B
{
    c, // OK, to use the same variable name from different enum class
    d,
    e
};
```

- Initialization syntax in main function:

```c++
enum_name obj1 = enum_name::name;
```

- You need `manual typecasting` to get the value

```
static_cast<data_type>(obj1)
```