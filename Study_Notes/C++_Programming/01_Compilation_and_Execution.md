# Compiling and Executing C++ file

First of all, make sure G++ compiler is installed in your host machine be it Linux or Windows. G++ installation methods for different OS are available on the Internet for reference.

Once G++ is installed, run this command below to verify:
```
    g++ -v
```

<br>

## Basic Steps to Compile and Execute C++ file

1) Create and edit C++ file with extension .cpp

2) Run the command below to compile the C++ file:
    ```
        g++ -o <output_file> <input_C++_file>
    ```

**EXTRAS:**

- `-Wall` flag to **enable warnings**
- `-std=c++<version>` flag to tell which C++ version to use. E.g. if need to use C++11, the flag will be "-std=c++11"

3) Execute the output compiled file from Step 2, and you will be able to see the results.