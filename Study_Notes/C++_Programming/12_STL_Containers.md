# Containers in C++ STL

Containers are **data structures** used to **store objects and data** according to the requirement.

- Each container is implemented as a template class that also contains the methods to perform basic operations on it
- Every STL container is defined inside its own header file

<br>

Containers can be further **classified into 4 types**:

- `Sequence Containers`
- `Container Adaptors`
- `Associative Containers`
- `Unordered Associated Containers`

<br>

**Why use Containers?**

- Instead of writing your own data structures (like linked lists or stacks), STL provides ready-made containers that are **fast, reliable, easy-to-use and type-safe (work with any data type using templates)**

<br>

## `Sequence Containers`

Sequence containers implement **linear data structures** in which the elements can be **accessed sequentially**.

| Container name | Description |
|:---:|---|
| [`std::array`](#array-class-in-c-stdarray) | Container that wraps over fixed size static array |
| `std::vector` | Automatically resizable dynamic array |
| `std::deque` | Dynamic array of fixed-size arrays that allows fast insertions and deletions at both ends |
| `std::list` | Implementation of Doubly Linked List data structure |
| `std::forward_list` | Implementation of Singly Linked List data structure |

<br>

### Array class in C++ (`std::array`)

The introduction of array class from C++11 has ordered a **better alternative for C-style arrays**.

**Advantages of array class over C-style array:**

- Array classes knows its own size, whereas C-style arrays lack this property. So when passing to functions, we do not need to pass size of Array as a separate parameter.

- With C-style array, there is more risk of <a href="https://www.geeksforgeeks.org/cpp/what-is-array-decay-in-c-how-can-it-be-prevented/">array being decayed into a pointer</a>. Array classes don't decay into pointers.

- Array classes are generally more efficient, light-weight and reliable than C-style arrays.

<br>

To use `std::array`, you need to include `<array>` header.

**Signature for `std::array`:**

```c++
std::array<type_name, array_size>
```

**Simple implementation with `std::array`:**

```c++
#include <iostream>
#include <array> // Header for std::array

int main()
{
    std::array<int, 5> arr = {1,2,3,4,5}; // Initializing all 5 array elements with data type int

    for (auto el : arr) // Explanation ==> for (declaration : range_of_expression)
    {
        std::cout << el << " ";
    } // Output ==> 1 2 3 4 5
}
```

<br>

#### Operations on `std::array`

1) `at()`

    - This function is used to **access the elements of array**

    - **Bounds checking is performed at runtime**. If the index is out of the array's bounds, a `std::out_of_range` exception is thrown. This allows for runtime error handling and graceful recovery in cases where the index might be dynamic or user-provided. 

    - Syntax:

    ```c++
    array_name.at(index)
    ```

2) `std::get`

    - Same as `at()` function, it is also used to **access the elements of array**

    - However, this function is not the member of array class, but overload function from class tuple. Therefore, **`<tuple>` header is needed** for `std::get` function

    - Unlike `at()` function, **bounds checking is performed at compile time**. If the index is out of bounds or not a constexpr, a compile-time error will occur. This ensures type safety and prevents runtime errors related to out-of-bounds access at the earliest possible stage. 

    - Syntax:

    ```c++
    std::get<index>(array_name)

    // NOTE: '#include <tuple>' is needed to be provided in the script
    ```

3) `operator[]`

    - This is **similar to C-style arrays**, to **access array elements**

    - Syntax:

    ```c++
    array_name[index]
    ```

4) `front()`

    - This **returns reference to the first element of array**

    - Precondition: array must not be empty

    - Syntax:

    ```c++
    array_name.front()
    ```

5) `back()`

    - This **returns reference to the last element of array**

    - Precondition: array must not be empty

    - Syntax:

    ```c++
    array_name.back()
    ```

6) `size()`

    - It **returns the number of elements in array**

    - This is a property that C-style arrays lack

    - Syntax:

    ```c++
    array_name.size()
    ```

7) `max_size()`

    - It **returns the maximum number of elements array can hold** i.e, the size with which array is declared

    - `size()` and `max_size()` return the same value for `std::array`

    - Syntax:

    ```c++
    array_name.max_size()
    ```

8) `swap()`

- **Swaps all elements of one array with other**

- Syntax:

```c++
array1.swap(array2)

// From the sample syntax, all elements in array1 swapping with array2
```

- Besides the syntax above, you can use another method to swap, which is by using `std::swap` algorithm with `<utility>` header included. 

- Syntax with `std::swap`:

```c++
std::swap(array1, array2)

// NOTE: #include <utility> is needed

// This syntax above will internally call array1.swap(array2) to perform swapping
```

9) `empty()`

    - This function **return true when the array size is zero, else returns false**

    - Syntax:

    ```c++
    array_name.empty()
    ```

10) `fill()`

    - This function is used to **fill the entire array with a particular value**

    - Syntax:

    ```c++
    array_name.fill(value);

    // E.g.
    // arr.fill(3);
    // This statement above means all elements in arr will be fill in as 3
    ```

<br>

### Vector in C++ (`std::vector`)

Vector is a sequence container in the Standard Template Library (STL) that **stores elements dynamically**.

- Think of it like a **dynamic array** that **can grow or shrink automatically when you add or remove elements**.

- `<vector>` header file is needed to be included for `std::vector`

<br>

#### Declare and Initialize a Vector

- **Syntax to declare a vector:**

```c++
std::vector<data_type> varName;
```

- **Syntax to initialize a vector:**

```c++
// Initialize the size of elements in vector, where all elements having a common value
std::vector<data_type> varName(size, common_value);

// Initialize the size of elements in vector, where all elements having a common value
// If data type is int, double, or any numeric data type, all elements are zero
// If data type is char or std::string, all elements are empty character or strings
std::vector<data_type> varName(size);

// Initialize the vector by listing all elements accordingly
std::vector<data_type> varName = {...};
```

<br>

#### Operations in `std::vector`

Vectors in C++ support various useful operations that allow you to add, remove, access, and modify elements dynamically.

1) **Insert Elements**

    - `push_back()` function

        - **Inserts element at the end of the vector** efficiently

        - Takes constant time O(1) on average, so it's very fast

        - Syntax:

        ```c++
        vector_name.push_back(value);
        ```

    - `insert()` function

        - **Inserts element at any position** (beginning, middle or end)

        - Takes linear time O(n), as it shifts elements to make space

        - Syntax:

        ```c++
        vector_name.insert(index, value);
        ```

2) **Access Elements**

    - You can access elements in a vector using either **`operator[]` for direct access** or **`at()` function for bounds-checked access**

    - Syntax of accessing element in vector using `operator[]`:

    ```c++
    vector_name[index]
    ```

    - Syntax of accessing element in vector using `at()` function:

    ```c++
    vector_name.at(index)
    ```

    - Both return the element at the mentioned index position, but `at()` throws an exception if the index position given is out of range

    - It takes constant time O(1) on average, so it's very fast

3) **Update Elements**

    - Syntax to update element of vector in particular index position:

    ```c++
    vector_name[index] = new_value;
    ```

4) **Find Vector Size**

    - Syntax to find the vector size:

    ```c++
    vector_name.size()

    // Here it prints the total number of elements in the vector
    ```

5) **Traverse Vector**

    - Traversing a vector means **going through each element one by one, usually using a loop**

    - It takes linear time O(n)

    - Sample pseudocode of traversing a vector:

    ```c++
    std::vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Traversing vector using range based for loop
  	for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    } // Output ==> a c f d z  
    ```

6) **Delete Elements**

    - `erase()` function

        - **Requires an [iterator](./14_STL_Iterators.md) pointing to the element to remove** the element from the vector

        - It takes linear time O(n) because all elements after the erased one need to be shifted

        - Syntax:

        ```c++
        // Remove single element
        vector_name.erase(position);

        // Erase range of elements
        vector_name.erase(first_position, last_position);
        ```

    - `pop_back()` function

        - **Remove the last element** in a vector efficiently

        - It takes constant time O(1) on average, so it's very fast

        - Syntax:

        ```c++
        vector_name.pop_back();
        ```
    
    - `clear()` function

        - **Remove all elements from a vector, making it empty**

        - Syntax:

        ```c++
        vector_name.clear();
        ```

        - Once `clear()` function is used, `size()` function will show value zero, because all elements in the vector are cleared

        - However, it will not change the value of `capacity()` function of the vector. More information on `capacity()`, can refer to this <a href="https://www.geeksforgeeks.org/cpp/vector-capacity-function-in-c-stl/">link</a>

7) **Check if vector is empty**

    - Syntax to check if vector is empty:

    ```c++
    vector_name.empty()

    // Returns true if the vector has no elements ,and false otherwise

    // Useful before accessing or modifying the vector to avoid errors
    ```

<br>

#### Multidimensional Vector

Multidimensional vectors are dynamic arrays that can store data in more than one dimension, like tables or grids.

They are implemented using vector inside another vector, allowing flexible row-column (2D), or even higher-dimensional structures.

Below only demonstrate on declaring, initializing and accessing element of 2D vector:

```c++
// Declare a 2D vector
std::vector<std::vector<data_type>> varName;

// Initialiation of 2D vector

// Initialize all elements by listing all their respective values
std::vector<std::vector<data_type>> varName = {
    {...}, 
    {...}, 
    {...}
}; 

// Initialize all elements to a common value in a given number of rows and columns
<std::vector<std::vector><data_type>> varName(rowNum, std::vector<data_type>(columnNum, common_value));

// Syntax to access element in 2D vector
vector_name[row_index][column_index]
```

For more information on implementation of multidimensional vector, please refer to this <a href="https://www.geeksforgeeks.org/cpp/multidimensional-vectors-in-cpp/">link</a>.

<br>

## Appendix

Reference links:

- <a href="https://www.geeksforgeeks.org/cpp/containers-cpp-stl/">Containers in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/array-class-c/">`Array` class in C++</a>
- <a href="https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/">`Vector` in C++ STL</a>