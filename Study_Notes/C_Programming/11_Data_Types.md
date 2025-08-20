# Data Types in C

| Data Type | Size (bytes) | Range | Format Specifier |
|:---:|:---:|:---:|:---:|
| `short int` | 2 | -(2<sup>15</sup>) to (2<sup>15</sup> - 1) | `%hd` |
| `unsigned short int` | 2 | 0 to (2<sup>16</sup> - 1) | `%hu` |
 `unsigned int` | 4 | 0 to (2<sup>32</sup> - 1) | `%u` |
| `int` | 4 | -(2<sup>31</sup>) to (2<sup>31</sup> - 1) | `%d` |
| `long int` | 4 | -(2<sup>31</sup>) to (2<sup>31</sup> - 1) | `%ld` |
| `unsigned long int` | 4 | 0 to (2<sup>32</sup> - 1) | `%lu` |
| `long long int` | 8 | -(2<sup>63</sup>) to (2<sup>63</sup> - 1) | `%lld` |
| `unsigned long long int` | 8 | 0 to (2<sup>64</sup> - 1) | `%llu` |
| `signed char` | 1 | -(2<sup>7</sup>) to (2<sup>7</sup> - 1) | `%c` |
| `unsigned char` | 1 | 0 to (2<sup>8</sup> - 1) | `%c` |
| `float` | 4 | 1.2E-38 to 3.4E+38 | `%f` |
| `double` | 8 | 1.7E-308 to 1.7E+308 | `%lf` |
| `long double` | 16 | 3.4E-4932 to 1.1E+4932 | `%Lf` |

**NOTE:**

- 1 byte = 8 bits
- HINT: 2<sup>n</sup>/2 = 2<sup>n-1</sup>
- HINT: yE+n = y * 10<sup>n<sup>

**EXTRAS:**
To declare binary, octal and hexademical:

```c
int bin_val = 0b1010; // bin_val has binary value of 1010

int oct_val = 0457; // oct_val has octal value of 457

int hex_val = 0x1A; // hex_val has hexa value of 1A
```