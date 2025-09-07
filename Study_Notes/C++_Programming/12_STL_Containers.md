# Containers in C++ STL

Containers are **data structures** used to **store objects and data** according to the requirement.

- Each container is implemented as a template class that also contains the methods to perform basic operations on it
- Every STL container is defined inside its own header file

<br>

Containers can be further **classified into 4 types**:

- [`Sequence Containers`](#sequence-containers)
- [`Associative Containers`](#associative-containers)
- [`Unordered Associative Containers`](#unordered-associative-containers)
- [`Container Adapters`](#container-adapters)

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

### Deque in C++ (`std::deque`)

Deque stands for `Double-Ended Queue`.

It is a sequence container that allows you to **add or remove elements efficiently from both the front and the back**.

- Deque can **act as both `stack` and `Queue`**

- It is useful in many problems where we need to have a subset of all operations also like insert / remove at front and insert / remove at the end

- It is typically implemented either using a doubly linked list or circular array

- `<deque>` header is needed to be included

<br>

#### Declaration and Initialization of `std::deque`

```c++
// Declare deque
std::deque<data_type> varName;

// Initialize deque
std::deque<data_type> varName = {...};
```

<br>

#### Basic Operations with `std::deque`

1) **Inserting Elements**

    - `push_back()` function

        - **Add an element at the end of the deque**

        - Useful for appending values

        - Syntax:

        ```c++
        deque_name.push_back(new_value);
        ```

    - `push_front()` function

        - **Adds and element at the front of the deque**

        - Help insert values at the beginning efficiently

        - Syntax:

        ```c++
        deque_name.push_front(new_value);
        ```

2) **Deletion**

    - `pop_back()` function

        - **Removes the last element from the deque**

        - Used when you want to delete from the back

        - Syntax:

        ```c++
        deque_name.pop_back();
        ```

    - `pop_front()` function

        - **Removes the first element from the deque**

        - Efficient way to remove from the front

        - Syntax:

        ```c++
        deque_name.pop_front();
        ```

3) **Accessing Elements**

    - `front()` function

        - **Returns the first element**

        - Does not remove it

        - Syntax:

        ```c++
        deque_name.front()
        ```

    - `back()` function

        - **Returns the last element**

        - Useful to check the end value

        - Syntax:

        ```c++
        deque_name.back()
        ```
    
    - Besides the above, you can access elements in a vector using either **`operator[]` for direct access** or **`at()` function for bounds-checked access**

    - Syntax of accessing element in vector using `operator[]`:

    ```c++
    deque_name[index]
    ```

    - Syntax of accessing element in vector using `at()` function:

    ```c++
    deque_name.at(index)
    ```

    - Both return the element at the mentioned index position, but `at()` throws an exception if the index position given is out of range

    - It takes constant time O(1) on average, so it's very fast

4) **Check size of deque**

    - `size()` function

        - **Returns the number of elements**

        - Helps in loops or checking length

        - Syntax:

        ```c++
        deque_name.size()
        ```

5) **Check if deque is empty**

    - `empty()`

        - **Returns true if deque is empty**

        - Useful for errors before accessing

        - Syntax:

        ```c++
        deque_name.empty()
        ```

6) **Clear**

    - `clear()`

        - **Removes all elements from deque**

        - Deque becomes empty after this

        - Syntax:

        ```c++
        deque_name.clear();
        ```

**Time Complexity for Operations:**

| Operation | Time Complexity |
|:---:|:---:|
| `push_back()` | O(1) amortized |
| `push_front()` | O(1) amortized |
| Insert at arbitary position | O(n) |
| `pop_back()` | O(1) amortized |
| `pop_front()` | O(1) amortized |
| Remove from arbitary position | O(n) |
| Access elements at any position using index | O(n) |
| Update elements at any position using index | O(n) |
| Iterate the deque | O(n) |

**NOTE:**

- For other operations in `std::deque` which are not mentioned, may refer to this <a href="https://www.studyplan.dev/pro-cpp/deque#doubleended-queues-using-stddeque">link</a>

<br>

### List in C++ (`std::list`)

List container **implements a doubly linked list** in which each element contains the address of next and previous element in the list.

- It **stores data in non-contiguous memory**, hence providing fast insertion and deletion once the position of element is known

- `<list>` header is needed to be included

<br>

#### Declaration and Initialization of `std::list`

```c++
// Declare a list
std::list<data_type> varName;

// Initialize list where all elements with assigned values
std::list<data_type> varName = {...};

// Initialize all elements in the list, where mentioning the size and the common value
std::list<data_type> varName(size, common_value);
```

<br>

#### Basic Operations in `std::list`

1) **Inserting Elements**

    - `insert()` function

        - **Used to insert the elements at any position of list**

        - Syntax:

        ```c++
        // Insert number of new values starting from the mentioned index position
        list_name.insert(index_position, number_of_new_value, new_value);

        // Insert 1 new value starting from the mentioned index position
        list_name.insert(index_position, new_value);
        ```

        - Time Complexity - Linear O(N)
    
    - `push_front()` function

        - **Insertion at beginning**

        - Syntax:

        ```c++
        list_name.push_front(new_value);
        ```

    - `push_back()` function

        - **Insertion at the end**

        - Syntax:

        ```c++
        list_name.push_back(new_value);
        ```

2) **Accessing Elements**

    - Unlike vectors, lists **do not support random access**

    - However, first and last elements can be quickly accessed using `front()` and `back()` methods respectively

        - `front()` function

            - **Access first element**

            - Syntax:

            ```c++
            list_name.front()
            ```

        - `back()` function

            - **Access last element**

            - Syntax:

            ```c++
            list_name.back()
            ```
        
        - If you want to access other element besides first and last element, you need to use `std::next()` function to move the `begin()` iterator as sample code shown below

        ```c++
        #include <iostream>
        #include<list>

        int main() 
        {
            std::list<int> l = {1, 3, 4, 2, 5};

            // Accessing first and last elements
            std::cout << l.front() << std::endl; // Print 1
            std::cout << l.back() << std::endl; // Print 5
    
            // Access third element
            std::cout << *std::next(l.begin(), 2); // Print 4

            return 0;
        }
        ```

3) **Updating Elements**

    - If you are using `front()` or `back()` function to access the element, you can straight away update directly using reference as below

    ```c++
    // For example, if using front() or back() to access list
    // You can update the new value as below
    list_name.front() = new_value; 
    // First element of list is updated with new value directly
    ```

    - However, if you are using iterator to access other element which is not first or last element, you need to dereference the iterator to update the value, because iterator is a pointer as per mentioned in [iterators chapter](./14_STL_Iterators.md)

    ```c++
    #include <iostream>
    #include <list>

    int main()
    {
        std::list<int> l = {1,2,3,4,5};

        // Move iterator from the first position by two steps
        auto it = l.begin();
        std::advance(it, 2);

        *it = 10; // Update l[2] = 10
        // Dereference is needed for iterator, because it is a pointer

        for (auto i : l)
        {
            std::cout << i << " ";
        } // Output ==> 1 2 10 4 5

        return 0;
    }
    ```

4) **Finding Elements**

    - To find any particular element in the list, the `std::find()` function from `<algorithm>` header can be used

    - Sample code to implement `std::find()` function:

    ```c++
    #include <iostream>
    #include <algorithm>
    #include <list>

    int main() 
    {
        std::list<int> l = {1, 3, 4, 2, 5};

        // Finding 4
        auto it = std::find(l.begin(), l.end(), 4);

        if (it != l.end()){
            std::cout << *it;
        } else {
            std::cout << "Element Not Found!";
        } // Print 4

        return 0;
    }
    ```

5) **Traversing**

    - A list can be **easily traversed using `begin()` and `end()` iterators** with any loop
    
    - Just move the begin() iterator till it is not equal to the end() iterator and access elements in each iteration

    - Sample code as below:

    ```c++
    #include <iostream>
    #include<list>

    int main()
    {
        std::list<int> l = {1, 3, 4, 2, 5};

        // Traversing using iterators
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            std::cout << *it << " ";
        } // Output ==> 1 3 4 2 5
        
        return 0;
    }
    ```

    - Other method to traverse is to **use the range based for loop** like we have done in previous examples

6) **Deleting Elements**

    - `pop_back()` function

        - **Quickly delete the last element**

        - Syntax:

        ```c++
        list_name.pop_back();
        ```

    - `pop_front()` function

        - **Quickly delete the first element**

        - Syntax:

        ```c++
        list_name.pop_front();
        ```

    - `erase()` function

        - **NOTE:** you need to use iterator to assist to delete specific position of element in list using `erase()` function

        - Syntax:

        ```c++
        // Remove single element which the iterator is pointing to
        vector_name.erase(iterator);

        // Erase range of elements starting one iterator to another iterator
        vector_name.erase(iterator1, iterator2);
        ```

<br>

**Time Complexity based on Operations above:**

| Operation | Time Complexity |
|:---:|:---:|
| `push_back()` | O(1) |
| `push_front()` | O(1) |
| `pop_back()` | O(1) |
| `pop_front()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| Access element at any position | O(n) |
| Find element by value | O(n) |
| Traversing the list | O(n) |

<br>

#### Other Member Functions of `std::list`

1) `size()` function

    - **Returns the number of element in the list**

    - Syntax:

    ```c++
    list_name.size()
    ```

2) `empty()` function

    - **Checks if the list is empty**

    - Syntax:

    ```c++
    list_name.empty()
    ```

    - Time Complexity: O(1)

    - Auxiliary Space: O(1)

3) `rbegin()` function

    - **Returns a reverse iterator pointing to the last element of the list**

    - Syntax:

    ```c++
    list_name.rbegin()
    // Pointing to list_name[n]
    ```

    - Sample pseudocode implementation:

    ```c++
    std::list<int> l = {1,2,3,4,5};

    auto it = l.rbegin();

    std::cout << *it; // Print 5
    ```

4) `rend()` function

    - **Returns a reverse iterator pointing to the element before the first element of the list**

    - Syntax:

    ```c++
    list_name.rend()
    // Pointing to list_name[-1]
    ```

    - Sample pseudocode implementation:

    ```c++
    std::list<int> l = {1,2,3,4,5};

    auto it = l.rend();

    std::cout << *it; // Print 5
    ```

5) `clear()` fucntion

    - **Removes all elements from the list**

    - Syntax:

    ```c++
    list_name.clear();
    ```

    - Time Complexity: O(n)
    
    - Auxiliary Space: O(1)

<br>

### Forward List in C++ (`std::forward_list`)

Forward_list container provides the **implementation of singly linked list** data structure.

- It **stores data in non-contiguous memory** where each element points to the next element in the sequence

- This makes insertion and deletion faster once the position of element is known

- `<forward_list>` header is needed to be included

<br>

#### Declaration and Initialization of `std::forward_list`

```c++
// Declare forward list
std::forward_list<data_type> varName;

// Initialize all elements in forward list, given the size and common value
std::forward_list<data_type> varName(size, common_value);

// Initialize forward list where all elements values are assigned accordingly
std::forward_list<data_type> varName = {...};
```

<br>

#### Basic Operations in `std::forward_list`

1) **Accessing Elements**

    - Forward list's elements **cannot be accessed using indices like arrays or vectors**

    - We **have to go through the list sequentially from the start to the desired position** to access it
    
    - This can be done by incrementing `begin()` iterator, but it is better to use `std::next()` or `std::advance()` function, as sample below

    ```c++
    #include <iostream>
    #include <forward_list>

    int main()
    {
        std::forward_list<int> fl = {1,2,3,4};

        // Access 3rd element
        auto it = std::next(fl.begin(), 2);
        std::cout << *it; // Print 3

        return 0;
    }
    ```

    - However, first element of the list can be easily accessed by using `front()` function as the syntax below

    ```c++
    forward_list_name.front()
    ```

2) **Inserting Elements**

    - `insert_after()` function

        - **Requires iterator after which the element is to be inserted**

        ```c++
        // Sample implementation of insert_after()

        #include <iostream>
        #include <forward_list>

        int main()
        {
            std::forward_list<int> fl = {1,2,3,4};

            // For example, insert value 6 after the second element
            auto it = fl.begin();
            std::advance(it, 1);
            fl.insert_after(it, 5);

            // Syntax of insert_after():
            // forward_list_name.insert_after(iterator, new_value)
            // Explanation: new value is inserted after the index position of the forward list where iterator is pointing to

            for (auto x : fl)
            {
                std::cout << x << " ";
            } // Output ==> 1 2 5 3 4

            return 0;
        }
        ```

        - More information on syntax of `insert_after()`, may refer to this <a href="https://www.geeksforgeeks.org/cpp/forward_list-insert_after-function-in-c-stl/">link</a>

    - `push_front()` function

        - **Fast insertion at the front**

        - Syntax:

        ```c++
        forward_list_name.push_front(new_value)
        ```

3) **Updating Elements**

    - Sample code to update element

    ```c++
    #include <iostream>
    #include <forward_list>

    int main()
    {
        std::forward_list<int> fl = {1,2,3,4};

        // Use front() to update first element value
        fl.front() = 7;

        // Use iterator to update other element's value
        // Below is the example, update 3rd element value
        auto it = std::next(fl.begin(), 2);
        *it = 9;

        for (auto x : fl)
        {
            std::cout << x << " ";
        } // Output ==> 7 2 9 4

        return 0;
    }
    ```

4) **Finding Elements**

    - The forward list **does not provide any member function to search for an element**, but we **can use the `find()` algorithm** to find any given value, as sample code below

    ```c++
    #include <iostream>
    #include <forward_list>
    #include <algorithm> // for std::find()

    int main()
    {
        forward_list<int> fl = {1,2,3,4};

        // Finding 3
        auto it = std::find(fl.begin(), fl.end(), 3);

        // EXTRAS on std::find()
        // Syntax:
        // std::find(starting_iterator, ending_iterator, value_to_find)
        // If found, return the value to find
        // If not found, return the end iterator

        if (it != fl.end())
        {
            std::cout << *it;
        } else{
            std::cout << "Element not found";
        } // Output ==> 3

        return 0;
    }
    ```

5) **Traversing**

    - A forward list can be traversed using `begin()` and `end()` iterators with a loop, but we **can only move forward and not backward**

6) **Deleting Elements**

    - `erase_after()` function

        - **Requires iterator before which the element is to be deleted**

        ```c++
        // Sample implementation of erase_after()

        #include <iostream>
        #include <forward_list>

        int main()
        {
            std::forward_list<int> fl = {1,2,3,4};

            // For example, delete value of the third element
            auto it = fl.begin();
            std::advance(it, 1);
            fl.erase_after(it);

            // Syntax of erase_after():
            // forward_list_name.erase_after(iterator)
            // Explanation: The value after the element where iterator is pointing to the forward list is deleted

            for (auto x : fl)
            {
                std::cout << x << " ";
            } // Output ==> 1 2 4

            return 0;
        }
        ```

        - More information on syntax of `erase_after()`, may refer to this <a href="https://www.geeksforgeeks.org/cpp/forward_listclear-forward_listerase_after-c-stl/">link</a>
    
    - `pop_front()` function

        - **Fast deletion from the front**

        - Syntax:

        ```c++
        forward_list_name.pop_front();
        ```

7) **Size of Forward List**

    - Forward_list **does not have a built-in `size()` function**. 
    
    - To find its size, we **need to manually count the elements by traversing it with a loop or using `std:: distance`** as the sample code below

    ```c++
    #include <iostream>
    #include <forward_list>
    #include <iterator> // For std::distance

    int main()
    {
        std::forward_list<int> fl = {1,2,3,4};

        // Use std::distance to calculate size by counting the elements
        int size = std::distance(fl.begin(), fl.end());
        std::cout << size; // Returns 4

        return 0;
    }
    ```

8) **Check if forward list is empty**

    - `empty()` function

        - **Returns true if the list is empty and false otherwise**, allowing to quickly verifying if the container has no data

        - Syntax:

        ```c++
        forward_list_name.empty()
        ```

**Time Complexity based on Operations above:**

| Operation | Time Complexity |
|:---:|:---:|
| `front()` | O(1) |
| Access n<sup>th</sup> element | O(n) |
| `push_front()` | O(1) |
| `insert_after()` | O(n) |
| `pop_front()` | O(1) |
| `erase_after()` | O(n) |
| Traversal | O(n) |

<br>

#### `std::forward_list` VS `std::list`

| Feature | `std::forward_list` | `std::list` |
|:---:|---|---|
| Type of linked list | Singly linked list | Doubly linked list |
| Traversal | Can only traverse forward | Can traverse both forward and backward |
| Memory usage | Uses less memory (only one pointer per node) | Uses more memory (two pointers per node) |
| Insertion / Deletion | Fast insertion and deletion, but only at or after a given position | Fast insertion and deletion anywhere (before or after a position) |
| Functions supported | Limited compared to list (no size(), no reverse iterators) | More complete interface including size(), reverse(), bidirectional iterators. |

<br>

## `Associative Containers`

Associative containers **store data in some sorted order**

- It provides fast search, insert and delete in O(log n) time by using balanced trees like <a href="https://www.geeksforgeeks.org/dsa/introduction-to-red-black-tree/">Red Black Trees</a>

| Container Name | Description |
|:---:|---|
| `std::set` | Collection of unique elements sorted on the basis of their values |
| `std::map` | Collection of key-value pairs sorted on the basis of the keys where no two pairs have same keys |
| `std::multiset` | Collection of elements sorted on the basis of their values but allows multiple copies of values |
| `std::multimap` | Collection of key-value pairs sorted on the basis of the keys where multiple pairs can have same keys |

<br>

### Set in C++ (`std::set`)

Set is assciative container which **stores unique elements in some sorted order**.

- By default, it is sorted ascending order of the keys, but this can be changed as per requirement

    ```c++
    // Declare with default setting (sort in ascending order)
    std::set<data_type> varName;
    // Equivalent to below, but redundant to state for below sample line:
    // std::set<data_type, std::less<data_type>> varName;

    // If want sort the set in descending order
    std::set<data_type, std::greater<data_type>> varName;
    ```

- Method to initialize `std::set`:

```c++
std::set<data_type> varName = {...};

// NOTE: you can write repeated values in set while initialize, but the repeat values initialize will only have 1 unit in the set

// Example
std::set<int> varName = {1,2,2,3,4,6,5};
// From example above, varName will only hold "1,2,3,4,5,6" in order
```

- `<set>` header is needed to be included

<br>

#### Basic Operations in `std::set`

1) **Inserting Elements**

    - In set, elements are added **using `insert()` or `emplace()` function**

    - Syntax:

    ```c++
    set_name.insert(new_value);

    set_name.emplace(new_value);
    ```

    - **If the element already exists in the set, it will not be added again in the set**

2) **Accessing Elements**

    - We **cannot access elements using an index like in arrays or vectors**

    - Instead, we use an iterator starting from `begin()` and move it using ++ or functions like `std::next()` or `std::advance()` to reach a specific position.
    
    - This is because sets store elements in sorted order without direct indexing

    - Sample code to access specific element in set:

    ```c++
    #include <iostream>
    #include <set>

    int main()
    {
        std::set<int> s = {1,2,3,4,5};

        auto it1 = s.begin(); // Access first element

        auto it2 = std::next(it1, 2); // Access third element

        auto it3 = s.rbegin(); // Access last element
        // end() not recommended, to avoid fragmentation error

        std::cout << *it1 << ", " << *it2 << ", " << *it3; // Prints 1,3,5

        return 0;
    }
    ```

3) **Updating Elements**

    - We **cannot change the value of elements** once they are stored in the set

4) **Finding Elements**

    - `find()` function

        - Provide **fast search of the value in set**

        - Returns iterator the element if found, else returns `end()` iterator

        - Sample code implementation:

        ```c++
        #include <iostream>
        #include <set>

        int main()
        {
            std::set<int> s = {1,2,3,4,5};

            // Finding 3
            auto it = s.find(3);
            
            // Syntax of find() function for set:
            // set_name.find(value_to_find)

            if (it != s.end())
            {
                std::cout << *it;
            } else {
                std::cout << "Element not found";
            } // Print 3

            return 0;
        }
        ```

5) **Traversing**

    - Just like other containers, sets can be easily traversed using range-based for loop or using `begin()` and `end()` iterators

    - Sample implementation:

    ```c++
    #include <iostream>
    #include <set>

    int main()
    {
        std::set<int> s = {5,3,4,1,2};

        // Traversing
        for(auto it = s.begin(); it != s.end(); ++it)
        {
            std::cout << *it << " ";
        } // Print 1 2 3 4 5

        return 0;
    }
    ```

6) **Deleting Elements**

    - In set, elements are removed from a set **using the `erase()` function**
    
    - We can erase elements either **by value or by position**

    - Syntax:

    ```c++
    set_name.erase(value); // Remove by value

    set_name.erase(iterator); // Remove by position
    // iterator can be i.e. set_name.begin()
    // To remove 1st element in set (for example)
    ```

7) **Check if set is empty**

    - `empty()` function

        - Checks whether the set has any elements

        - **Returns true if the set is empty, otherwise false**

        - Syntax:

        ```c++
        set_name.empty()
        ```

8) **Check size of set**

    - `size()` function

        - **Check the size of set**, but only **reflects the count of distinct unique values**

        - Syntax:

        ```c++
        set_name.size()
        ```

**Time Complexity of the Operations above:**

| Operation | Time Complexity |
|:---:|:---:|
| `insert()` / `emplace()`| O(log n) |
| `erase()` | O(log n) |
| Find the largest element <br><br> For more information on the method, can search from internet | O(1) |
| Find the smallest element <br><br> For more information on the method, can search from internet | O(1) |
| `find()` | O(log n) |
| Traverse the set | O(n) |

<br>

### Map in C++ (`std::map`)

Maps are associative containers that **store data as pairs of keys and values**.

- **Each key is unique**

- **Data is automatically sorted by keys in ascending order**

- `<map>` header is needed to be included

- Syntax:

```c++
// Declare with default setting (sort data according to keys in ascending order)
std::map<key_data_type, value_data_type> varName;
// Equivalent to below, but redundant to state for below sample line:
// std::map<key_data_type, value_data_type, std::less<key_data_type>> varName;

// If want sort the map in descending order according to keys
std::map<key_data_type, value_data_type, std::greater<key_data_type>> varName;
```

<br>

#### Declaration and Initialization of `std::map`

```c++
#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> m1; // Declaration of map m1 or creating empty map m1

    // Initializing map with list
    std::map<int, std::string> m2 = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Similar method as above method will be:
    /*
    std::map<int, std::string> m2;
    m2[1] = "Geeks";
    m2[2] = "For";
    m2[3] = "Geeks";
    */

   for (auto el : m2)
   {
        std::cout << el.first << " " << el.second << std::endl;
   } 
   // NOTE:
   // .first to access the key of the map
   // .second to access the value of the map

   // Output:
   /*
   1 Geeks
   2 For
   3 Geeks
   */

  return 0;
}
```

<br>

#### Basic Operations in `std::map`

1) **Inserting Elements**

    - `[] operator`

        - Syntax:

        ```c++
        map_name[new_key] = new_value;
        // NOTE:
        // If new_key exists, it will act as updating the value on that key
        ```

    - `insert()` function

        - Syntax:

        ```c++
        map_name.insert({new_key, new_value});
        // NOTE:
        // If new_key exists, nothing will be done, because the key already exists.
        // In short, inserting value is not done
        ```

2) **Accessing Elements**

    - `[] operator` (**Not recommended**)

        - Not recommended, because **if the key doesn't exist, it adds a new entry with a default value**

        - Syntax:

        ```c++
        map_name[key_to_find]
        // If exist, show the value at the key
        // Else, it will create a new default value at the key, and show default value
        ```

    - `at()` fucntion (**Recommended**)

        - **Check or get a value without creating a new element**

        - Syntax:

        ```c++
        map_name.at(key_to_find)
        // If exist, show the value at the key
        // Else, throw exception of std::out_of_range
        ```

3) **Updating Elements**

    - The **key of an already present elements cannot be modified in the map**
    
    - But the **associated value can be changed** by first accessing the element and then **using assignment operator to change the value**

    - Syntax to update value:

    ```
    // Method 1: use [] operator
    map_name[key] = update_value;

    // Method 2: use at() function
    map_name.at(key) = update_value;
    ```

4) **Finding Elements**

    - Map provides **fast element search by key using the `find()`** member function
    
    - This function **returns iterator the element if found, otherwise returns `end()` iterator**

    - Sample code implementation:

    ```c++
    #include <iostream>
    #include <map>

    int main()
    {
        std::map<int, std::string> m1 = {
            {1, "Geeks"},
            {2, "For"},
            {3, "Geeks"}
        };

        // Use iterator to find element with key 2
        auto it = m1.find(2);

        if (it != m1.end()){
            std::cout << it->first << " " << it->second;
        } else {
            std::cout << "Key not found";
        } // Output ==> 2 For
        // ->first & ->second are used, because iterator is pointer
        // -> to deference

        return 0;
    }
    ```

5) **Traversing**

    - Maps can be easily **traversed by using either range based for loop or using `begin()` and `end()` iterator with traditional loops**

    - Besides the example from [initialization sub-chapter](#declaration-and-initialization-of-stdmap), below sample code uses `begin()` and `end()` to traverse

    ```c++
    #include <iostream>
    #include <map>

    int main()
    {
        std::map<int, std::string> m1 = {
            {1, "Geeks"},
            {2, "For"},
            {3, "Geeks"}
        };

        // Traversing using iterators
        for (auto it = m1.begin(); it != m1.end(); ++it)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
        // Output:
        /*
        1 Geeks
        2 For
        3 Geeks
        */

       return 0;
    }
    ```

6) **Deleting Elements**

    - `erase()` function

        - Syntax:

        ```c++
        // Delete by passing the key
        map_name.erase(key);

        // Delete by passing an iterator
        map_name.erase(iterator);
        // Example iterator can be: map_name.begin() [to delete first element]
        ```

**Time Complexity of Operations in `std::map`:**

| Operation | Time Complexity |
|:---:|:---:|
| Insert an element | O(log n) |
| Delete an element by key | O(log n) |
| Access element by key | O(log n) |
| `find()` | O(log n) |
| Update element by key | O(log n) |
| Traverse the map | O(n) |

<br>

### Multiset in C++ (`std::multiset`)

Multiset is an associative container **similar to the set**, but it **can store multiple elements with same value**. 

- It is **sorted in increasing order by default**, but it **can be changed to any desired order**

- `<set>` header is needed to be included

- Syntax:

```c++
// Declare with default setting (sort data in ascending order)
std::multiset<data_type> varName;
// Equivalent to below, but redundant to state for below sample line:
// std::multiset<data_type, std::less<data_type>> varName;

// If want sort the multiset in descending order
std::multiset<data_type, std::greater<key_data_type>> varName;
```

<br>

#### Declaration and Initialization of `std::multiset`

```c++
#include <iostream>
#include <set>

int main()
{
    std::multiset<int> ms1; // Declare a multiset, or create an empty multiset

    std::multiset<int> ms2 = {5,1,2,2}; // Initialize multiset
    // NOTE: unlike set, multiset can have duplicate values into it
    // So, from values in ms2 will be: 1,2,2,5 [sort accordingly]

    for (auto i : ms2)
    {
        std::cout << i << " ";
    } // Output ==> 1 2 2 5

    return 0;
}
```

<br>

#### Basic Operations in `std::multiset`

1) **Inserting Elements**

    - `insert()` function

        - **Insert elements into a multiset**

        - Syntax:

        ```c++
        multiset_name.insert(new_value);
        ```

        - Multiset will automatically keep the elements sorted after inserted

2) **Accessing Elements**

    - We **cannot use an index to get elements like in an array**

    - To reach a certain element, we start from `begin()` and move the iterator forward step by step or use helper functions like `std::next()` or `std::advance()`
    
    - But we can easily get the first element with `begin()` and the last element by moving one step back from `end()`

    - Sample code implementation:

    ```c++
    #include <iostream>
    #include <set>

    int main()
    {
        std::multiset<int> ms = {5,4,3,3,1};
        // ms value arrangement be like: 1,3,3,4,5

        // Access first element
        auto it1 = ms.begin();

        // Acess third element (for example)
        auto it2 = std::next(it1, 2);

        // Access last element
        auto it3 = ms.rbegin(); // end() not recommended, to avoid fragmentation error

        std::cout << *it1 << " " << *it2 << " " << *it3; // Print 1 3 5

        return 0;
    }
    ```

3) **Updating Elements**

    - We **cannot change the value of elements** once they are stored in the set

4) **Finding Elements**

    - `find()` function

        - **Fast search by value**

        - Syntax:

        ```c++
        multiset_name.find(value_to_find)
        ```

        - **Returns iterator the element if found, otherwise returns `end()` iterator**

        - Sample code implementation:

        ```c++
        #include <iostream>
        #include <set>

        int main()
        {
            std::multiset<int> ms = {5,4,3,3,1};

            auto it = ms.find(3)

            if (it != ms.end()){
                std::cout << *it;
            } else {
                std::cout << "Not found";
            } // Print 3

            return 0;
        }
        ```

5) **Traversing**

    - Multisets **can be easily traversed using range-based for loop or using `begin()` and `end()` iterators**
    
    - To traverse all the elements with same value(key), use the `std::equal_range()` function- it gives the start and end positions for the specific value. More information on `std::equal_range()` implementation, can refer to this <a href="https://www.geeksforgeeks.org/cpp/equal_range-in-cpp/">link</a>

    - You may refer to example mentioned in [initialization sub-chapter](#declaration-and-initialization-of-stdmultiset)

6) **Deleting Elements**

    - In multiset, elements are removed from a set **using the `erase()` function**
    
    - We can erase elements either **by value or by position**

    - Syntax:

    ```c++
    multiset_name.erase(value); // Remove by value
    // NOTE: all matched values will be erased as well
    // For example, if multiset has {1,2,3,3,4} and multiset_name.erase(3) is triggered,
    // updated multiset will be: {1,2,4}

    multiset_name.erase(iterator); // Remove by position
    // iterator can be i.e. multiset_name.begin()
    // To remove 1st element in set (for example)
    // Even if there's other same value as per pointer by mentioned by the iterator, that other value will not be erased
    ```

<br>

#### `std::multiset` VS `std::set`

| Feature | `std::set` | `std::multiset` |
|:---:|---|---|
| Duplicates | Not allowed (only unique elements) | Allowed (multiple copies allowed) |
| Order | Elements are sorted | Elements are sorted |
| Use case | When only unique values are needed | When duplicates are needed |
| Insertion | Inserts only if element is not present | Inserts elements regardless of duplicates |

<br>

### Multimap in C++ (`std::multimap`)

Multimap is an associative container **similar to map**, but it **can have multiple elements with same keys**. 

- It **stores all the elements in increasing order based on their keys by default** but **can be changed if required**

- `<map>` header is needed to be included

- Syntax:

```c++
// Declare with default setting (sort data according to keys in ascending order)
std::multimap<key_data_type, value_data_type> varName;
// Equivalent to below, but redundant to state for below sample line:
// std::multimap<key_data_type, value_data_type, std::less<key_data_type>> varName;

// If want sort the map in descending order according to keys
std::multimap<key_data_type, value_data_type, std::greater<key_data_type>> varName;
```

<br>

#### Declaration and Initialization of `std::multimap`

```c++
#include <iostream>
#include <map>

int main()
{
    std::multimap<int, std::string> m1; // Declaration of multimap m1 or creating empty multimap m1

    // Initializing multimap with list
    std::multimap<int, std::string> m2 = {
        {1, "Geeks"},
        {1, "For"},
        {2, "Geeks"}
    };

   for (auto el : m2)
   {
        std::cout << el.first << " " << el.second << std::endl;
   } 
   // NOTE:
   // .first to access the key of the map
   // .second to access the value of the map
   // key value can repeat unlike map

   // Output:
   /*
   1 Geeks
   1 For
   2 Geeks
   */

  return 0;
}
```

<br>

#### Basic Operations in `std::multimap`

1) **Inserting Elements**

    - A key-value pair **can be inserted into multimap using `insert()` method**
    
    - **Insertion using `[] operator` is not valid** because there can be multiple elements with same key

    - Syntax:

    ```c++
    multimap_name.insert({new_key, new_value});
    ```

2) **Accessing Elements**

    - Elements are **accessed only through iterators**, using **`->first` for keys** and **`->second` for values**, since `[]` is not available.
    
    - You can move iterators with `std::next()` or `std::advance()`, and quickly get the first and last elements using `begin()` and `end()`

    - Sample code implementation to access element:

    ```c++
    #include <iostream>
    #include <map>

    int main()
    {
        std::multimap<int, std::string> mm = {
            {1, "Geeks"},
            {1, "For"},
            {2, "Geeks"}
        };

        // Accessing first element
        auto it1 = mm.begin();
        std::cout << it1->first << " " << it1->second << std::endl; // Output ==> 1 Geeks

        // Accessing second element
        auto it2 = std::next(it1,1);
        std::cout << it2->first << " " << it2->second << std::endl; // Output ==> 1 For

        // Accessing last element
        auto it3 = mm.rbegin(); // end() not recommended, will cause fragmentation error
        std::cout << it3->first << " " << it3->second << std::endl; // Output ==> 2 Geeks

        return 0;
    }
    ```

3) **Updating Elements**

    - In multimap, the **key of any element cannot be modified** 
    
    - But we **can modify the value using the iterator** to that element

    - Sample code implementation to update value:

    ```c++
    #include <iostream>
    #include <map>

    int main()
    {
        std::multimap<int, std::string> mm = {
            {1, "Geeks"},
            {1, "For"},
            {2, "Geeks"}
        };

        // Update 2nd element value
        auto it = std::next(mm.begin(), 1);
        it->second = "Java";
        // NOTE: it->first cannot be changed

        for (auto x : mm)
        {
            std::cout << x.first << " " << x.second << std::endl;
        }
        // Output:
        /*
        1 Geeks
        1 Java
        2 Geeks
        */

        return 0;
    }
    ```

4) **Traversing**

    - Multimap can be **traversed by either range-based for loop or using `begin()` and `end()` iterators with a loop**

    - Sample code implemetation to traverse using `begin()` and `end()` with a loop:

    ```c++
    #include <iostream>
    #include <map>

    int main()
    {
        std::multimap<int, std::string> mm = {
            {1, "Geeks"},
            {1, "For"},
            {2, "Geeks"}
        };

        // Traverse multimap
        for (auto it = mm.begin(); it != mm.end(); ++it)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
        // Output:
        /*
        1 Geeks
        1 For
        2 Geeks
        */

        return 0;
    }
    ```

    - For other code example, can refer to sample code mentioned in [initialization sub-chapter](#declaration-and-initialization-of-stdmultimap)

5) **Finding Elements**

    - We can quickly **find the first element with a given key using the `find()` method**

    - **If the key isn't found, it returns the `end()` iterator**

    - Sample code implementation to find element:

    ```
    #include <iostream>
    #include <map>

    int main()
    {
        std::multimap<int, std::string> mm = {
            {1, "Geeks"},
            {1, "For"},
            {2, "Geeks"}
        };

        // Find element with key 2
        auto it = mm.find(2);

        std::cout << it->first << " " << it->second; // Output ==> 2 Geeks

        return 0;
    }
    ```

    - To **find a specific element among duplicates**, **use the range from `std::equal_range()` to search within that group**. More information on `std::equal_range()` implementation, please refer to this <a href="https://www.geeksforgeeks.org/cpp/equal_range-in-cpp/">link</a>

6) **Deleting Elements**

    - In multimap, elements are removed from a set **using the `erase()` function**
    
    - We can erase elements either **by key or by position**

    - Syntax:

    ```c++
    multimap_name.erase(key); // Remove by key
    // NOTE: all values in the matched key will be erased as well

    multimap_name.erase(iterator); // Remove by position
    // iterator can be i.e. multimap_name.begin()
    // To remove 1st element in set (for example)
    // Even if there's other values in the same key as per pointer by mentioned by the iterator, that other value in the same key will not be erased
    ```

**Time Complexity of Operations in `std::multimap`:**

| Operation | Time Complexity |
|:---:|:---:|
| `insert()` | O (log n) |
| `erase()` | O(log n) |
| Access an element at any position | O(n) |
| Find an element by key | O(n) |
| Find the number of elements with a specific key | O(log n) |
| Traverse the multimap | O(n) |

<br>

#### `std::multimap` VS `std::map`

| Feature | `std::map` | `std::multimap` |
|:---:|---|---|
| Key Uniqueness | Keys are unique | Duplicate keys are allowed |
| Access | Supports `[]` and `at()` | Does not support `[]` or `at()`|
| Order | Elements sorted by key | Elements sorted by key |
| Storage | One value per key | Multiple values per key |
| Use Case | When ech key maps to one value | When keys can map to multiple values |

More information between the comparison of both, can refer to this <a href="https://www.geeksforgeeks.org/cpp/multimap-vs-map-in-c-stl-with-examples/">link</a>.

<br>

## `Unordered Associative Containers`

<br>

## `Container Adapters`

<br>

## Appendix

Reference links:

- <a href="https://www.geeksforgeeks.org/cpp/containers-cpp-stl/">Containers in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/array-class-c/">`Array` class in C++</a>
- <a href="https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/">`Vector` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/deque-cpp-stl/">`Deque` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/list-cpp-stl/">`List` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/forward-list-c-set-1-introduction-important-functions/">`Forward List` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/set-in-cpp-stl/">`Set` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/map-associative-containers-the-c-standard-template-library-stl/">`Map` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/multiset-in-cpp-stl/">`Multiset` in C++ STL</a>
- <a href="https://www.geeksforgeeks.org/cpp/multimap-associative-containers-the-c-standard-template-library-stl/">`Multimap` in C++ STL</a>