# Templates in C++

Templates are **mechanisms to support the *`so-called generic programming`***

- Generic broadly means we can define a function or a class without worrying about what types it accepts

- Syntax to define template:

```c++
template <typename key_var_name>
// entity_definition here [either in terms of class or function]

// NOTE: you can replace "typename" with "class"

// If multiple key_var_names, it will be:
// template <typename key_var_name_1, typename key_var_name_2, ..., typename key_var_name_N>
```

- The syntax given above can define templates for 3 components (entities) of C++ language:

    - `Function Templates`
    - `Class Templates`
    - `Variable Templates` (**Since C++14**)

- Syntax to call or create template instance:

```c++
entity_name<data_type_of_key_var_name> 

// If multiple key_var_names, it will be:
// template <data_type_of_key_var_name_1, data_type_of_key_var_name_2, ..., data_type_of_key_var_name_N>
```

## Function Templates

```c++
// Sample Implementation of Function Template

#include <iostream>

template <typename T>
T showMax(T x, T y) // Function Template
{
    return (x > y) ? x : y;
}

int main()
{
    // call showMax for int
    std::cout << showMax<int>(3,7) << std::endl; // Print 7

    // call showMax for double
    std::cout << showMax<double>(3.0,7.5) << std::endl; // Print 7.5

    // call showMax for char
    std::cout << showMax<char>('a','z') << std::endl; // Print z

    return 0;
}
```

## Class Templates

```c++
// Sample Implementation of Class Template

#include <iostream>

template <typename T>
class Geek // Class Template
{
    private:
        T x;

    public:
        Geek(T xx) : x {xx} // Constructor
        {
        }

        T getvalue()
        {
            return x;
        }
};

int main()
{
    // Creating objects of Geek class with different data types
    Geek<int> obj1{ 10 };
    Geek<double> obj2{ 20.54 };

    // Access the templates values
    std::cout << obj1.getvalue() << std::endl; // Print 10
    std::cout << obj2.getvalue() << std::endl; // Print 20.54

    return 0;
}
```

## Template Specialization

If we want our **template to behave differently, only for a specific type**, we provide the so-called `template specialization`

```c++
// Sample Implementation of Template Specialization
// Below demo is for function template
// Of course, you can do the same for class template

#include <iostream>

template <typename T>
void myFunction(T arg) // Declare a normal generic template
{
    std::cout << "The value of arg: " << arg << '\n';
}

template <> // Template Specialization
void myFunction(int arg) // Here, if arg is int, specialization is done here
{
    std::cout << "This is a specification for int. Value of arg: " << arg << '\n';
}

int main()
{
    myFunction<char>('A'); // Invoke generic template
    // Output:
    // The value of arg: A

    myFunction<double>(2.3); // Invoke generic template
    // Output:
    // The value of arg: 2.3

    myFunction<int>(10); // Invoke specialization
    // Output:
    // This is a specification for int. Value of arg: 10

    return 0;
}
```

## Template Variables (Since C++14)

Syntax to define variable templates:

```c++
template <typename T> variable-declaration
```

For more information on the implementation, may refer to this <a href="https://www.geeksforgeeks.org/cpp/variable-templates-in-cpp/">link</a>

## Default Template Arguments

Like normal parameters, we can also specify default type arguments to templates

```c++
// Sample code in setting default template argument(s)

#include <iostream>

template <typename T1, typename T2 = double, typename T3 = std::string> // T1 is default type, while T2 and T3 here set to double and string respectively by default
class Geek
{
    public:
        T1 x;
        T2 y; // y is double by default
        T3 z; // z is string by default

        Geek(T1 xx, T2 yy, T3 zz) : x {xx}, y {yy}, z {zz}
        {
        }

        void printMsg()
        {
            std::cout << x << ", " << y << ", " << z << '\n';
        }
};

int main()
{
    // T1 set to int, T2 set to float, T3 set to string
    Geek<int, float, std::string> obj1(10, 5.67f, "HI");

    // T1 set to char, T2 and T3 leave as per set by default in generic template
    Geek<char> obj2('A', 3.14, "OK");

    obj1.printMsg(); // Output ==> 10, 5.67, HI
    obj2.printMsg(); // Output ==> A, 3.14, OK

    return 0;
}
```

## Other Implementation with Templates

There are other methods to implement templates, such as:

- **Template Non-Type Arguments**

- **Template Argument Deduction**

    - Function Template Arguments Deduction (since C++98 standard) [**Only having difference in calling instances compared to [Function Templates mentioned above](#function-templates)**]
    - Class Template Arguments Deduction (C++17 onwards) [**Only having difference in calling instances compared to [Class Templates mentioned above](#class-templates)**]

- **Template Metaprogramming**

The above topics, can refer to this <a href="https://www.geeksforgeeks.org/cpp/templates-cpp/">link</a>

## Appendix

Reference link:

- <a href="https://www.geeksforgeeks.org/cpp/templates-cpp/">Templates in C++</a>