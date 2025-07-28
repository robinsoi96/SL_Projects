# Filtering Text using `awk`

## Syntax of `awk` Command

Perform *`<actions>`* :

```
    awk '{ <actions> ; }'
```

Perform *`<actions>`* based on *`<pattern>`* :

```
    awk '/<pattern>/ { <actions> ; }'
```

Perform *`<actions>`* based on *`<conditions>`* :

```
    awk '<conditions> { <actions> ; }'
```

**NOTE:**
- `print` or/and `printf` commands will be most commonly used in *`<actions>`* to **print required output based on either *`<pattern>`* or *`<conditions>`* given**. <br> For more info on these 2 print commands mentioned, can always use `man` comamnd or use `--help`. <br><br>

- `$` operator is used to access a field.
- E.g., **$1** indicates the **first field of the line of output**.
- For **$0**, variable 0 is used by awk to store the **entire input line** as it was read.
- **$NF** refers to last field.<br><br>


## Field and record in `awk`

### Record
- A `record` represents a unit of input that AWK processes at a time. 
- By default, each line of input is considered a separate record.
- This behavior is controlled by the `RS (Record Separator)` built-in variable.

### Field
- Each record is automatically divided into smaller units called `fields`. 
- By default, fields are separated by whitespace (spaces, tabs, or newlines). 
- This default behavior is controlled by the `FS (Field Separator)` built-in variable. 

## Comparison Operators in `awk`

| Operator | Description |
|:---:|---|
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal to |
| `>=` | Greater than or equal to |
| `==` | Equal to |
| `!=` | Not equal to |
| *`<value>`*` ~ /`*`<pattern>`*`/` | True if *`<value>`* matches *`<pattern>`* |
| *`<value>`*` !~ /`*`<pattern>`*`/` | True if *`<value>`* does not match *`<pattern>`* |

## Compound Expressions in `awk`

| Compound Expressions | Description |
|:---:|---|
| `(`*`<expression_#1>`*`) && (`*`<expression_#2>`*`)` | *`<expression_#1>`* **AND** *`<expression_#2>`*|
| `(`*`<expression_#1>`*`) \|\| (`*`<expression_#2>`*`)` | *`<expression_#1>`* **OR** *`<expression_#2>`*|
| `!(`*`<expression>`*`)` | **NOT** *`<expression>`*|

## `next` Command in `awk`

The `next` command in `awk` **instructs the program to stop processing the current input record** and **immediately move to the next one**. <br> This means that **any subsequent pattern-action pairs in the `awk` script will be skipped for the current line**.

## Numeric Operations in `awk`

| Operator | Description |
|:---:|---|
| `+` | Add |
| `-` | Subtract |
| `*` | Multiply |
| `/` | Divide |
| `%` | Remainder |
| `^` | Exponentiation <br><br> E.g. <br> `2^8` ==> 2 power 8 |

<br>

**NOTE:** <br>
`Assignment Operators` are useful where you can key in `x += 1` (where `+=` is assignment operator) instead of declaring `x = x+1` <br>

| Assignment Operator | Description |
|:---:|---|
| `+=` | Add |
| `-=` | Subtract |
| `*=` | Multiply |
| `/=` | Divide |
| `%=` | Remainder |
| `^=` | Exponentiation |

## The Special Patterns: `BEGIN` and `END`

### `BEGIN` in `awk`
Syntax of `BEGIN` special pattern:

```
    BEGIN { <actions> ; }
```

`BEGIN` pattern is optional, but it **must be first** to be specified in `awk` command if provided. <br>

When `BEGIN` pattern is specified, `awk` **executes its actions before reading any input**. <br>

**NOTE:** <br>
If a program only consists of only a `BEGIN` pattern, `awk` does not read any lines before exiting.

### `END` in `awk`
Syntax of `END` special pattern:

```
    END { <actions> ; }
```

`END` pattern is optional, but it **must be last** to be specified in `awk` command if provided. <br>

When `END` pattern is specified, `awk` **executes its actions before it exits**.

## Built-in Variables in `awk`

| Built-in Variables | Description |
|:---:|---|
| `FILENAME` | The `name of the current input file`. <br> You **should not change the value of this variable**. |
| `NR` | The `number of current input line or record in the input file`. <br> You **should not change the value of this variable**. |
| `NF` | The `number of fields in the current line or record`.  <br> You **should not change the value of this variable**. |
| `OFS` | The `output field separator` <br> **Default is space** <br><br> You can change `OFS` in `BEGIN` special pattern as below: <br> `BEGIN { OFS=":" ; }` <br> The sample above change `OFS` to be `:` |
| `FS` | The `input field separator` <br> **Default is space and tab** <br><br> You can change `FS` in `BEGIN` special pattern as below: <br> `BEGIN { FS=":" ; }` <br> The sample above change `FS` to be `:` <br><br> With the sample above, you can use `-F` option to `awk`. <br> **Example #1:** <br> `awk -F: '{ ... }'` <br> **Example #2:** <br> `MYFS=: ; export MYFS ; awk -F${MYFS} '{ ... }'`|
| `ORS` | The `output record separator` <br> **Default is newline** <br><br> You can change `ORS` in `BEGIN` special pattern as below: <br> `BEGIN { ORS=":" ; }` <br> The sample above change `ORS` to be `:` |
| `RS` | The `input record separator` <br> **Default is newline** <br><br> You can change `RS` in `BEGIN` special pattern as below: <br> `BEGIN { RS=":" ; }` <br> The sample above change `RS` to be `:` |

## Allowing `awk` to Use Shell Variables

Syntax for setting variables to `awk` command:

```
    awk '<script>' <awk_var1>=<value_1> <awk_var2>=<value_2> ... <awk_varN>=<value_N>
```

**NOTE:** <br>
From the above syntax, `<awk_var1>`, `<awk_var2>` until `<awk_varN>` will be declared with respective values before running `<script>` in `awk` command.

## Flow Control in `awk`

There are 3 main forms for flow control in `awk`:
- The `if` statement
- The `while` statement (consists of `while` & `do` statement)
- The `for` statement

**NOTE:**
- The `if` and `while` statements are similar to the versions in the shell
- The `for` statement is much closer to the version found in C language version

### The `if` statement for `awk`

```
    if (<expression1>) {
        <action1> ;
    } else if (<expression2>) {
        <action2> ;
    } else {
        <action3> ;
    }
```

### The `while` statement for `awk`

```
    while (<expression>) {
        <actions> ;
    }
```

### The `do` statement for `awk`

```
    do {
        <actions> ;
    } while (<expression>)
```

### The `for` statement for `awk`

```
    for (<initialize_counter>; <test_counter>; <increment_counter>) {
        <action> ;
    }
```