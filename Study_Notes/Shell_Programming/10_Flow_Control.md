# Flow Control

## `if` Statement

```bash
if [ condition_#1 ]; then
    # code if condition #1 is True
elif [ condition_#2 ]; then
    # code if condition #2 is True
else
    # code if no conditions are True
fi
```

### Using `test`

`test` command(s) can be given to an `if` statement or condition, and its syntax is as below:

```
test <expression>
```

The `test` command returns either **0 [for True]** or **1 [for False]**

You can also use shorthand of `test` command as below:

```
[ <expression> ]
```

There are 3 types of expressions understood by `test` command:

- [File tests](#file-tests)
- [String comparisons](#string-comparisons)
- [Numerical comparisions](#numerical-comparisons)

### File Tests

File test options for the `test` command:

| Option | Description |
|:---:|---|
| `-b` *file* | True if file exists and is a **block special file** |
| `-c` *file* | True if file exists and is a **character special file** |
| `-d` *file* | True if file exists and is a **directory** |
| `-e` *file* | True if file **exists** |
| `-f` *file* | True if file exists and is  a **regular file** |
| `-g` *file* | True if file exists and **has its SGID bit set** |
| `-h` *file* | True if file exists and is a **symbolic link** |
| `-k` *file* | True if file exists and **has its "sticky" bit set** |
| `-p` *file* | True if file exists and is a **named pipe** |
| `-r` *file* | True if file exists and is **readable** |
| `-s` *file* | True if file exists and **has a size greater than zero** |
| `-u` *file* | True if file exists and **has its SUID bit set** |
| `-w` *file* | True if file exists and is **writable** |
| `-x` *file* | True if file exists and is **executable** |
| `-O` *file* | True if file exists and is **owned by the effective user ID** |

### String Comparisons

String comparison options for `test` command:

| Option | Description |
|:---:|---|
| `-z` *string* | True if *string* has zero length **(*string* is empty)** |
| `-n` *string* | True if *string* has nonzero length **(*string* is not empty)** |
| *string_#1* `=` *string_#2* | True if the strings are **equal** |
| *string_#1* `!=` *string_#2* | True if the strings are **not equal** |

### Numerical Comparisons

Numerical comparison operators for `test` command:

| Operator | Description |
|:---:|---|
| *int1* `-eq` *int2* | True if *int1* **equal to** *int2* |
| *int1* `-ne` *int2* | True if *int1* **not equal to** *int2* |
| *int1* `-lt` *int2* | True if *int1* **less than** *int2* |
| *int1* `-le` *int2* | True if *int1* **less than or equal to** *int2* |
| *int1* `-gt` *int2* | True if *int1* **greater than** *int2* |
| *int1* `-ge` *int2* | True if *int1* **greater than or equal to** *int2* |

### Compound Expressions

Operators for creating compound expressions:

| Operator | Description |
|:---:|---|
| `!` *expr* | True if *expr* is **False [`NOT`]**|
| *expr1* `-a` *expr2* <br> or <br> *expr1* `&&` *expr2* | True if **both *expr1* and *expr2* are True [`AND`]**|
| *expr1* `-o` *expr2* <br> or <br> *expr1* `\|\|` *expr2* | True if **either *expr1* or *expr2* is True [`OR`]**|

**NOTE:**

For NOT operators, the sample syntax as below:

```
test ! expr

or

[ ! expr ]
```

For AND and OR operators, the sample syntax could be as below:

- If using built-in operators [e.g. `-a`, `-o`]

```
test expr1 <operator> expr2

or

[ expr1 <operator> expr2 ]
```

- If using conditional operators [e.g. `||`, `&&`]

```
test expr1 <operator> expr2

or

[ expr1 ] <operator> [ expr2 ]
```

## `case` Statement

```bash
case $variable in
    "value1")
        # code for value1
        ;;
    "value2")
        # code for value2
        ;;
    *)
        # default code
        ;;
esac
```