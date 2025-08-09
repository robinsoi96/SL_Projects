# JavaScript Loops

## JavaScript `for` Loop

```javascript
for (initialization; condition; increment) {
    // Code to execute
}
```

## JavaScript `for in` Loop

```javascript
for (key in object) {
    // Code to execute
}
```

**NOTE:**

- Example of an object in JavaScript:
```javascript
const myObject = { a: 1, b: 2, c: 3};
```

## JavaScript `for of` Loop

```javascript
for (variable of iterable) {
    // Code to execute
}
```

**NOTE:**

- Iterable can be arrays, strings, maps, etc

## JavaScript `while` Loop

```javascript
while (condition) {
    // Execute the code while the condition is true
}
```

## JavaScript `do while` Loop

```javascript
do {
    // Execute the code while the condition is true
}
while (condition)
```

**NOTE:**

- The minor difference with [while loop](#javascript-while-loop) is that `do while` loop will execute at least once, even if the condition is false, because the code block is executed before the condition is tested

## JavaScript `break` Statement

`break` statement is useful to **terminate or exit a loop**

## JavaScript `continue` Statement

`continue` statement causes the **current iteration of the loop to exit only**, rather than the entire loop