# Implicit type conversion(Coercion)

The proecess of producing a new value of some type from a value of a different type is called a **conversion**

Type conversion can be invoked in one to two ways:
1. implicitly(by the compiler)
1. explicitly(by the programmer)


## Implicit type conversion
Implicit type conversion(also called as automatic type conversion or coercion) is performed automatically by the compiler when one data type is required, but a different data type is supplied.

for example
```cpp
double d{ 3 }; // int value 3 implicitly converted to type double
float f{ 3.0 } // double value 3.0 implicitly converted to type float
double division{4.0/3}; // int value 3 implicitly converted to type double.
```

## What happens ehen a type conversion is invoked
When a type conversion is invoked(whether implicitly or explicitly), the compiler will determine wheteher it can convert the value from the current type to the desired type. If a valid conversion can be found, then the compiler will produce a new value of the desired type. If the compiler can't find an acceptable conversion, the compilatiion will fail with a compiler error.

Note: Type conversion can fail for any number of reasons, for example the compiler is not able to convert a value between the original type and the desired type, or is disallowed by the language(for example narrowing conversion in brace initialization).

## The standard conversions
The C++ language standard defines how different fundamental types(and in some cases, compound types) can be converted to other types. These conversion rules are called the standard conversions.

the standard conversion can be broadly divided into 4 categories, each covering different type of conversions:
- Numeric promotions
- Numeric conversion
- Atithmetic conversions
- Other conversion


When a type conversion is needed, the compiler will see if there are standard conversions that it can use to convert the value to the desired type. The compiler may apply zero, one, or more than one standard conversions in the conversion process.