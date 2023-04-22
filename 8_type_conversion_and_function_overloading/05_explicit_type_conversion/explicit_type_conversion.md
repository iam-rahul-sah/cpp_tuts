# Explicit type conversion (casting) and static_case

C++ comes with a number of different **type casting operators** that can be used by programmer to request that the compiler perfrom a type conversion. Because casts are explicit requests by the programmer, this form of type conversion is oftern called and **explicit type conversion**.

### Type casting
C++ supports 5 different types of casts:
1. C-style casts,
1. static casts,
1. const casts, (should be avoided)
1. dynamic casts,
1. reinterpret casts. (should be avoided)
The latter four are somtimes referred to as named casts.

### C-style casts
In standard C programming, casts are done via the `()` operator, with the name of the type to convert the value placed inside the parentheses. Usually find in code converted from C to C++.

**Example**
```cpp
    int x { 10 };
    int y { 4 };


    double d { (double)x / y }; // convert x to double before division for a floating point result.

// we can also do the above in the following form
    double d{ double(x)/y}
```

Note: C-style casts are not type safe. as it perform a variety of different conversion depending on context. 

### static_cast

C++ introudces a casting operator called `static_cast`, which can be used to convert a value of one type to a value of another type. The syntax for `static_cast` is as follows:
```cpp
    static_cast<type>(expression)
```

Note: `static_cast` is also less powerful than C-style casts, so you can't inadvertently convert a pointer to a reference, or vice-versa.

### Using static_cast to make narrowing conversion explicit

Compiler will ofter issue warnings when a potentially unsafe(narrowing) implicit type conversion is performed. for example, casting an int(4 bytes) to a char(1 byte) will result in a warning(as the compiler can't tell whether the integer value will overflow the rnage of the char or not). To avoid this warning, we can use `static_cast` to make the narrowing conversion explicit.