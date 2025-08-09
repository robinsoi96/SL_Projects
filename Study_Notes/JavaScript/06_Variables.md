# JavaScript Variables

Variables are containers for storing data.

JavaScript variables can be decalred in 4 ways:

- Automatically
- Using `var`
- Using `let`
- Using `const`

## When to use `var`, `let` or `const`?

1) Always decalre variables
2) Always use `const` if the value should not be changed
3) Always use `const` if the type should not be changed (Arrays and Objects)
4) Only use `var` if you must support old browsers
5) Use `let` (preferable most of the time) or `var` if you can't use `const`

**NOTE:** 

- Declare variable without value using `var` or `let` (e.g. let varName; ), the variable is `undefined` and holding value **undefined** as well
- You may declare many variables in a single statement as sample below:
```javascript
let person = "John", car = "Volvo";
```
- You cannot re-declare a variable declared with `let` or `const`, but you can re-declare those declared with `var`
```javascript
// Re-declaration works
var carName = "Volvo";
var carName // Fine to re-declare, and var carName still have value "Volvo"

// Re-declaration fails
let carName = "Volvo";
let carName; // Will not work
```