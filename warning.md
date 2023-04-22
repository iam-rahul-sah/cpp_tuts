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
