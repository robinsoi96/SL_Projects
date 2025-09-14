# Iterators in C++ STL

An iterator is an object **like a pointer that points to an element inside the container**. 

We can use iterators to move through the contents of the container. They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them.

- They are one of the most important components that **contributes the most in connecting the STL algorithms with the containers**

- Iterators are **defined inside the `<iterator>` header file**

- Syntax to declare or initialize an iterator:

```c++
// Method #1
cType::iterator varName

//cType ==> container type, e.g. std::vector<int>

// Method #2 [more preferred, easier]
auto varName
```

<br>

## Types of Iterators

There are 5 types of iterators:

1) `Input Iterator`

    - It is a **read only iterator** but **not modified the value using input iterator**

    - For more information, please refer to this <a href="https://www.geeksforgeeks.org/cpp/input-iterators-in-cpp/">link</a>

2) `Output iterator`

    - Output iterator is **used to assign the values**

    - For more information, please refer to this <a href="https://www.geeksforgeeks.org/cpp/output-iterators-cpp/">link</a>

3) `Forward Iterator`

    - It is the **combination of input and output iterator** means for **both access and assigning the values**

    - For more information, please refer to this <a href="https://www.geeksforgeeks.org/cpp/forward-iterators-in-cpp/">link</a>

4) `Bidirectional Iterator`

    - This iterator **can move in both direction either in forward or backward**
    
    - It has all functionalities of forward iterators

    - For more information, please refer to this <a href="https://www.geeksforgeeks.org/cpp/bidirectional-iterators-in-cpp/">link</a>

5) `Random-Access Iterator`

    - Random-access iterators are iterators that can be used to **access the element at the distance from the element they pointed to**
    
    - It has all functionalities of bidirectional iterators

    - For more information, please refer to this <a href="https://www.geeksforgeeks.org/cpp/random-access-iterators-in-cpp/">link</a>

<br>

**NOTE**: Not all [containers in STL](./12_STL_Containers.md) supports iterators

| Container | Types of iterator supported |
|:---:|:---:|
| `std::vector` | Random-Access |
| `std::list` | Bidirectional |
| `std::deque` | Random-Access |
| `std::map` | Bidirectional |
| `std::multimap` | Bidirectional |
| `std::set` | Bidirectional |
| `std::multiset` | Bidirectional |
| `std::stack` | No iterator supported |
| `std::queue` | No iterator supported |
| `std::priority_queue` | No iterator supported |

<br>

**Functionality of iterators w.r.t operations:**

| Iterators | ACCESS | READ | WRITE | ITERATE | COMPARE |
|:---:|:---:|:---:|:---:|:---:|:---:|
| Input | `->` | `=*it` | - | `++` | `==` , `!=` |
| Output | - | - | `*it=` | `++` | - |
| Forward | `->` | `=*it` | `*it=` | `++` | `==` , `!=` |
| Bidirectional | - | `=*it` | `*it=` | `++` , `--` | `==` , `!=` |
| Random-Access | `->` , `[]` | `=*it` | `*it=` | `++` , `--` , `+=` , `-=` , `==` , `+` , `-` | `==` , `!=` , `<` ,  `>`, `<=` , `>=` |

<br>

For more information on iterators, can refer to this <a href="https://www.geeksforgeeks.org/cpp/iterators-c-stl/">link</a>

<br>

## Appendix

Reference link:

- <a href="https://www.geeksforgeeks.org/cpp/introduction-iterators-c/">Introduction to Iterators in C++</a>