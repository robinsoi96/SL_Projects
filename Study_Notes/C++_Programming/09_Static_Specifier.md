# `static` Specifier

The `static` specifier in C and C++ largely shares its core functionalities, primarily related to storage duration and linkage. 

However, C++ introduces an additional significant use within the context of classes, which is absent in C.

## Static Variables in a Function

- Applicable for both C and C++

- In a function, when a variable is declared as `static`, space for **it gets allocated for the lifetime of the program**

    - Even if the function is called multiple times, space for `static` variable is allocated only once and the value of the variable in the previous call gets carried through the next function call

```c++
// Sample implementation of static variable in a function

#include <iostream>

void increment()
{
    static int count = 0; // static variable
    // Will not be initialized every time the function is called
    // The value of int count is carried through the function call

    ++count;
    std::cout << count << " ";
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        increment();
    }
    //Output ==> 1 2 3 4 5

    return 0;
}
```

**Applications:**

- Return local variable address from the function
- Useful for implementing **coroutines** or any other application where the previous state of function needs to be stored
- Memoization in recursive calls

## Global Static Variable

- Applicable for both C and C++

- `Global static variable` is a static variable **declared outside of any class or function**

- Unlike regular global variables, a global static variable **has internal linkage**, meaning it is **accessible only within the file where it is defined**

    - This ensures that its scope is limited to current translation unit, preventing conflicts with variables in other files that may have the same name

```c++
// Sample implementation of global static variable

#include <iostream>

static int count = 0; // Global static variable
// Only applicable in the same file

void increment()
{
    count++;
    std::cout << count << " ";
}

int main()
{
    increment();
    increment();
    // Output ==> 1 2

    return 0;
}
```

**Applications:**

- Limiting variable scope to a file to prevent conflicts by ensuring the variable is accessible only within the file
- Global counters or flags
- Store settings or values that are specific to the functionality implemented in a single file
- Use for shared resources in scenarios where frequent initialization and destruction can be avoided
- Shared state access functions in a file

## Static Functions

- Applicable for both C and C++

- `Static function` is a function where its name having `static` keyword before it

- Behaviour acts very similar to [global static variable](#global-static-variable)

    - Unlike global functions, **access to static functions is restricted to the file (or translation unit)** where they are declared (**internal linkage**)

**Syntax of static function:**

```c++
static return_type function_name(args)
{
    // Static function body
}
```

**Applications:**

- Data hiding as we can hide the function from other translation units or files
- Avoiding function name clashes in multi-file programs

## Static Data Member in a Class

- Only applicable to C++

- `Static data members` are class members that are declared using `static` keywords

    - Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created
    - It is initialized before any object of this class is created, even before the main starts outside the class itself
    - It is visible and can be controlled with class access specifiers
    - Its lifetime is the entire program
    - Cannot be initialized using constructors

```c++
// Sample implementation of static data member in C++ class

#include <iostream>

class A
{
    public:
        static int x; // Declare static member here

        A(){}; // Constructor, just to tell cannot initialize static data member here
};

int A::x = 10; // Initialize static data member, as we cannot initialize it inside the class due to class rules

int main()
{
    // Method 1 to get static data member
    // Using class name and scope resolution operator (::)
    std::cout << A::x << std::endl;

    // Method 2 to get static data member
    // Access via object
    A obj1; // Declare object
    std::cout << obj1.x << std::endl;

    // Both methods above will give the same results, which is 10

    //EXTRAS:
    //For example, declare another new object and then change the value of static data member
    A obj2; // Declare new object
    obj2.x = 3; // Change the value to 3
    std::cout << obj1.x << std::endl;
    std::cout << A::x << std::endl;
    // Both statements above will give the same results, which is 3 [updated]
    
    return 0;
}
```

**Applications:**

- Counting objects of a class
- Store and share configuration or settings globally
- Tracking shared resources
- Regulate or limit operations performed by multiple objects
- Ensure a class has only one instance by using static members

## Static Member Function in a Class

- Only applicable to C++

- `Static member function` in C++ is a function that **belongs to the class rather than any specific object of the class**

    - Declared using `static` keyword inside the class definition
    - Can be called without creating an object
    - `Only has access to static data members or other static functions`
    - Useful when a function's logic is independent of object state

```c++
// Sample implementation of static member function in C++ class

#include <iostream>

class A
{
    public:
        static int length;
        static int height;

        static void print(); // Declaration
        // EXTRAS:
        // You can also initialize static member function in class as sample below
        /*
        static void print()
        {
           // Body of static function member            
        }
        */
       // But the declaration line above is not needed if initialization is done in the class
};

int A::length = 10;
int A::height = 20;

void A::print() // Initialize static member function outside the class
{
    std::cout << "Length: " << A::length << std::endl;
    // Same as std::cout << "Length: " << length << std::endl;

    std::cout << "Height: " << A::height << std::endl;
    // Same as std::cout << "Height: " << height << std::endl;
}

int main()
{
    // Method 1 to invoke static member function
    A::print(); 

    // Method 2 to invoke static member function
    A obj1;
    obj1.print();

    // Both methods will give the same output as below:
    /*
    Length: 10
    Height: 20
    */

    return 0;
}

// EXTRAS: 
// Static member function only can access to static data member or other static member function
```

**Applications:**

- Accessing static member variables
- Implement helper functions that do not depend on specific instances
- Singleton pattern implementation
- Factory methods to create and return objects without requiring an instance of the class
- Logging and debugging

<br>

There are some interesting facts about `static member functions` in C++, please refer to this <a href="https://www.geeksforgeeks.org/cpp/some-interesting-facts-about-static-member-functions-in-c/">link</a>

- Static member function cannot be `virtual`

```c++
class A
{
    public:
        virtual static void print(){} // This is invalid
}
```

## Static Objects

- Only applicable to C++

- An object becomes static when `static` keyword is used in its declaration

    - Static objects are initialized only once and live until the program terminates
    - They are allocated storage in the data segment or BSS segment of the memory
    - To understand more on memory segment, may refer to this [link](./02_Pointers.md#memory-management-in-programming)

- There are 2 types of `static objects`:

    - `Local Static Objects`
    - `Global Static Objects`

- Syntax of static object

```c++
static className objectName;
```

- For more information on static objects in C++, please refer to this <a href="https://www.geeksforgeeks.org/cpp/static-objects-in-cpp/">link</a>

## `static` Implementation with `struct`

The term **"static struct"** has different implications and capabilities in C and C++

**In C:**

- `static` is used with a variable of a `struct` type
- **Structure in C cannot have static member variables**

```c
// Example of static implementation with struct in C

struct MyData
{
    int x; // Here, cannot have static struct member
    float y;
};

static struct MyData globalStaticData; // Global static struct variable

int main()
{
    static struct MyData localStaticData; // Local static struct variable
    return 0;
}
```

**In C++:**

- C++ **can perform like C** as in the sample code above
- What C++ can do which C cannot is that it can have [static member variables](#static-data-member-in-a-class) and [static member functions](#static-member-function-in-a-class)

## Appendix

Reference links:

- <a href="https://www.geeksforgeeks.org/cpp/static-keyword-cpp/">Static Keyword in C++</a>
- <a href="https://www.geeksforgeeks.org/c/what-are-static-functions-in-c/">Static Functions in C</a>