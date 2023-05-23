# Warnings

### Switch

Once the statement underneath a case or default label have started executing, they will overflow(fallthrough) into subsequent cases. `Break` and `return` statements are used to prevent this.

### Halt

The `std::exit` function does not clean up local variables in the current function or up the call stack.

### Narrowing Conversion
Compilers will often not warn when converting a signed int to an unsigned int, or vice-versa, even though these are narrowing conversions. Be extra careful of inadvertent conversions between these types (particularly when passing an argument to a function taking a parameter of the opposite sign).

### Explicit type conversion
Avoid `const casts` and `reinterpret casts` unless you have a very good reasons to use them.

### Typedefs and type aliases
care must be taken not to mix values of aliases that are intended to be semantically distinct.

### Pointer
- Although we generally should not declare multiple variable on the same line, if you do so, the astrisk(*) should be placed next to each variable name, not the type.
```cpp
int* a, b; // a is a pointer to an int, b is an int
int *a, *b; // a and b are both pointers to ints
```
- Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling pointers, as this will cause undefined behavior (probably an application crash).
- Conditionals can only be used to differentiate null pointers from non-null pointers. There is no convenient way to determine whether a non-null pointer is pointing to a valid object or dangling (pointing to an invalid object).
- When an object is destroyed, any pointers to the destroyed object will be left dangling (they will not be automatically set to nullptr). It is your responsibility to detect these cases and ensure those pointers are subsequently set to nullptr.