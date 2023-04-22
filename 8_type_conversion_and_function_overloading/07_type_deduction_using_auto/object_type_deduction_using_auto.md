# Type deduction for object using the auto keyword

**Type deduction**(also sometimes called **type inference**) is a feature that allows the compiler to deduce the type of an object from the object's initializer. To use type deduction, the `auto` keyword is used in place of the variable's type:

Note: `auto` is a keyword, not a type. It is used to tell the compiler to deduce the type of the variable from the initializer.
```cpp
    auto x { 5 }; // x is an int
```

Function calls are valid expressions, we can even use type deduction when our initializer is a function call:
```cpp
    auto x { get_value() }; // x is initialize by the value returned from the function call
```

Also, type deduction will not work for object that do not have initializers or empty initializers. For example, the following code will not compile:
```cpp
    auto x; // error: x has no initializer
```

## Type deduction drops const qualifiers

In most cases, type deduction will drop the `const` qualifier for deduced types. 
If want our automatically deduced variable to be const qualified, we need to explicitly specify the const qualifier:
```cpp
    const int x{ 5 }; // x is a const int
    auto y { x }; // y is an int and not a const int

    const auto z{ x }; // z is a const int as we have reapplied const
```

## Type deduction for string literals
As we know a simple string in C++ is of type `const char*`. When we use type deduction for a string literal, the compiler will deduce the type as `const char*`.
If we want the type deduced for a string literal to be `std::string` or `std::string_view`, we will need to use the `s` or `sv` literal suffixes:
```cpp
    auto x { "Hello" }; // x is a const char*
    auto y { "Hello"s }; // y is a std::string
    auto z { "Hello"sv }; // z is a std::string_view
```

## Type deduction benefits and downsides.

### Pros of type deduction
1. If two or more variables are defined on sequential lines, the name of the variables will be lined up, helping increase readability.
```cpp
auto c { 5 }; // c is an int
auto d { 6.7 }; // d is an double
```
2. Type deduction only workd on variables that have initializers, so it is not possible to define a variable without initializing it.(Which is a good practice)
3. Third we are guaranteed that there will be no unintended performance-impacting conversion:
**Example**
```cpp
double x { 5 }; // x is a double, implict conversion from int to double
auto x { 5 }; // x is an int, no conversion
```

### Cons of type deduction
1. Type deduction hides an object's type information in the code.
```cpp
auto y { 5 }; // oops, we wanted a double here but we accidentally provided an int literal
```
2. If the type of an initializer changes, the type of a variable defined with type deduction will also change.
```cpp
    auto sum { add(5, 6) + gravity };
```

**Overall, type deduction is a useful feature that can help make our code more readable and easier to maintain.**