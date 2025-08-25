# C++ Classes

In `Object Oreinted Programming (OOP)`, classes and objects are basic concepts of that are used to represent real-world concepts and entities.

- `Class` is a **template to create objects having similar properties and behaviour**, or in other words, we can say that a class is a **blueprint for objects**.
- `Object` is **an instance of a class**. 

From the sample picture below, the animal type Dog is a class, while a particular dog named Tommy is an object of the Dog class.

<img src="./images/Classes_and_Object_Concept.png" alt="Simple Concept of Classes and Objects"></img>

## Generic Structure of C++ Class

**Generic syntax to define a class in C++:**

```c++
class className {
    access_specifier:
        // data members
        //member functions
};
```

From the generic syntax above, you can see a class in C++ generally having `access specifier` and members (`data members` and `member functions`).

<br>

### `Data Members` in Class

Data members are those **variables defined inside a class**.

```c++
class className {
    int a; // int a is a data member
};
```

<br>

### `Member Functions` in Class

Members functions are **functions declared inside a class**, also referred to as a **member method**.

There are 2 ways to define member function in a class.

**Method #1:** Define member function in a class

```c++
class className{
    void funcName()
    {
        // List actions in the function
    }
};
```

**Method #2:** Define member function outside a class

```c++
class className{
    void funcName();
};

// NOTE:
// If member function is declared outside the class, function name should be:
// <class_Name>::<member_function_name>()
void className::funcName()
{
    // List actions in the function
}
```

<br>

### `Access Specifiers` in Class

In C++, `access specifiers` are keywords that **control the visibility and accessibility of class members** (`data members` and `member functions`).

They define which parts of a program can access specific members of a class, thereby enforcing encapsulation and data hiding.

<br>

#### 3 main access specifiers in C++ class

1) `public`

    - Members declared as `public` are **accessible from anywhere in the program**, both within the class and from outside the class using an object of that class
    - Public members **typically form the interface of a class, allowing interaction** with its functionality

2) `private`

    - Members declared as `private` are **only accessible from within the same class**
    - They **cannot be accessed directly from outside the class**, even by objects of that class
    - Private members are **typically used for internal implementation details** of a class, **promoting data hiding** and **preventing direct manipulation of internal state**


3) `protected`

    - Members declared as `protected` are **accessible within the same class and by derived (child) class**
    - They **cannot be accessed directly from outside the class or by unrelated classes**
    - Protected access is primarily **used in the context of `inheritance`**, allowing derived classes to access specific members of their base class while maintaining a level of encapsulation from external code 

In short, perspective of 3 different actors:

- `Class` itself: 

    - Can see and access any code inside the class itself, regardless of visibility or accessibility level

- `Derived class` (child class):

    - Can see and access only code inside a `public` and `protected` region
    - **More information on derived class, will be discussed in `inheritance` chapter**

- `Object` of a class:

    - Can see and access only code inside `public` area

**NOTE:**

- If no access specifier is given in a `class`, the default visibility or access specifier for the class is `private`.

```c++
class className {
    // everything in here has private access by default
    // since no access specifier is given
};
```

- Another way to write a class is to write a `struct`, which has all members with `public` access specifier by default

```c++
struct className {
    // everything in here has public access by default
    // since struct has public access specifier by default
};
```

<br>

## C++ Objects

Assume class is done defined as mentioned in topic [above](#generic-structure-of-c-class), syntax to create new object as below:

```c++
className objectName;
```

Method to access members in a class:

```c++
objectName.dataMemberName; // To access data member

objectName.memberFunctionName(..); // To access member function

// Dot (.) operator is used to access members in a class
```

## Appendix

Reference link:

- <a href="https://www.geeksforgeeks.org/cpp/c-classes-and-objects/">C++ Classes and Objects</a>