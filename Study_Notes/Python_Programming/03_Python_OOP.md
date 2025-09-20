# Python OOP (Object Oriented Programming) Concepts

## Class

Generic syntax to declare a class in Python:

```python
class ClassName:
    classVar = "XXX" # Class variable; can straight away called by ClassName.classVar

    def __init__(self, instVar1, instVar2):
        self.instVar1 = instVar1 # Instance variable; can be called by ClassName.instVar1
        self.instVar2 = instVar2 # Instance variable; can be called by ClassName.instVar2
```

**Class Variables:**

- These are variables that are shared across all instances of a class
- It is defined at class level, outside any methods
- All objects of class share same value for a class variable unless explicitly overridden in an object

**Instance Variables:**

- Variables that are unique to each instance (object) of a class
- These are defined within `__init__()` method or other instance methods
- Each object maintains its own copy of instance variables, independent of other objects

<br>

Above is the basic of OOP concepts for Python.

For more information, please refer to the links in [Appendix](#appendix)

<br>

## Appendix

Reference links:

- <a href="https://www.geeksforgeeks.org/python/python-oops-concepts/">Python OOP Concepts</a>
- <a href="https://www.geeksforgeeks.org/python/python-classes-and-objects/">Python Classes and Objects</a>