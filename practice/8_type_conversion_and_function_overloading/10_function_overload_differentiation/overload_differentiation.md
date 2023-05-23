# How overload function are differentiated

| Function property | used for differentiation | notes
|-------------------|--------------------------|------
| Number of parameters | Yes |            |
| Type of parameters | Yes |   Excludes typedefs, type aliases, and const qualifier   |
| Order of parameters | yes |      |
| Return type | No |            |

Note: Function's return type is not used for differentiation.

[Program to check if order of parameter is differentiable](practice/parameter_order.cpp)

## Overloading based on number of parameters
An overloaded function is differentiated so as long as each overloaded function has a different number of parameters.

**Example**
```cpp
int add(int x, int y)
{
    return x + y;
}
int add(int x, int y, int z)
{
    return x + y + z;
}
int main()
{
    add(8,9);
    add(10,2,3);
}
// This program will compile as compiler is able to differentiate the overloaded function based on the number of parameter.
```

## overloading based on type of parameters

**Example**
```cpp
int add(int x, int y);
int add(double x, double y);
int add(int x, double y);
int add(double x, int y);  // all this function are differentiable

using Num = int;     // type alias for type int
int add(Num x, int y); // This is not differentiable it is same as int add(int, int) will cause a compiler error.
```
## The return type of a function is not considered for differentiation
```cpp
int getRandomValue();
double getRandomValue();
// This two function are not differentiable by the compiler, since the calling for both the function is exact
std::cout << getRandomValue();
```
## Type signature
A function's **type signature** also know as **signature** is defined as the part of the function header that are used for differentiation of the function. In C++, this includes the *function name*, *number of parameter*, *parameter type* and *function-level qualifiers*. It does not include the return type