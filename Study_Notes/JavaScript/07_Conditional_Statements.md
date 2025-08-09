# JavaScript Conditional Statements

## JavaScript `if` Statement

```javascript
if (condition_#1) {
    // Code for condition_#1
} else if (condition_#2) {
    // Code for condition_#2
} else {
    // Code if not for both condition_#1 and condition_#2
}
```

## JavaScript `switch` Statement

```javascript
switch(expression) {
    case x:
        // Code for case x
        break;
    case y:
        // Code for case y
        break;
    default:
        // Default code
}

// break statement is required if it is not the last case.
// If break statement not included, it will proceed to next case regardless of whether its condition matches.
```