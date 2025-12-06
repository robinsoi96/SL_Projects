import os
import sys
import platform

# Method 1: Using os module
print("Check OS type using os module")
print("Output of os.name:")
print(os.name)
print()

# Method 2: Using sys module
print("Check OS type using sys module")
print("Output of sys.platform:")
print(sys.platform)
print()

# Method 3: Using platform module
print("Check OS type using platform module")
print()
print("Output of platform.uname() to see full details:")
print(platform.uname())
print()
print("Output of platform.uname().system to see OS type:")
print(platform.uname().system)