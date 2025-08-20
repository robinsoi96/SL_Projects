# Loops

## `while` Loop

```bash
while [ condition ]; do
    # code while the condition is true
done
```

## `until` Loop

```bash
until [ condition ]; do
    # code until the condition is true
done
```

## `for` Loop

```bash
for item in item1 item2 ... itemN; do
    # code to execute for each item
done

# Another method
for ((initialization; condition; increment)); do
    # code to execute
done
```

## `select` Loop

```bash
#!/bin/bash

# PS3 is declared so that user-friendly prompt will appear after options
# If not included as below, before running this bash script, need run this command in the terminal:
# $PS3="Please make a selection =>" | export PS3

PS3="Please make a selection =>"

select option in "Option1" "Option2" ... "Exit"; do
    case $option in
        "Option1")
            # Code for "Option1"
            ;;
        "Option2")
            # Code for "Option2"
            ;;
        .
        .
        .
        "Exit")
            # Code for "Exit"
            ;;
        *)
            # Default code
            ;;
    esac
done
```

When the above sample script is executed, the output prompt will look as below:

```
1) Option1
2) Option2
.
.
.
n)Exit
Please make a selection =>
```

## Infinite Loop

```bash
while :
do
    # Code in infinite loop
done
```

## Loop Control

### `break` Command

`break` command is useful to **terminate or exit a loop**.

You can also break nested loop by defining number of loop to break, instead of writing break command in every loop.

**Syntax to define number of loop to exit:**

```bash
break <number_of_loops>

# NOTE: <number_of_loops> = any number greater than 1
```

### `continue` Command

`continue` command is similar to `break` command, except that it causes the **current iteration of the loop to exit only**, rather than the entire loop.