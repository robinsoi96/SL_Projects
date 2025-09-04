# Structure (`struct`)

- In C++, `struct` is similar to [`class`](./07_Classes.md), except its default access specifier for all its data members and member functions are public

```c++
// struct sample in C++
struct A
{
    int y; // data member
    float z;
    void display(){}; // member function
};

// You can even set access specifiers (public, private, protected) jsut like classes in C++

//struct in C++ can directly initialize in it, unlike C
```

- In C, only data members are allowed in `struct`
```c
// struct sample in C
struct A
{
    int y; // only allow to declare data members
    float z;
    double x;
};
```

For more details on comparison of `struct` in C and C++, may refer to this <a href="https://www.geeksforgeeks.org/cpp/difference-c-structures-c-structures/">link</a>