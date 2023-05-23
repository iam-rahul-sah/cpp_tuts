# Default arguments

A *default argument* is a default value provided for a function parameter. If the caller does not provide an argument for that parameter, the default value will be used instead.

```cpp

void add(int x, int y = 0)   // second parameter has a default argument of 10
{
    return x + y;
}
```

**Note**: Default arguments are specified in the function declaration, not the function definition.
**Note**: We must use an equal sign to specify a default argument, parantheses and brace initialization are not allowed.

A parameter with a default value provided is sometimes know as an *optional parameter*.

## When to use default arguments
Default arguments are an excellent option when a function needs a value that has a reasonable default value, but for which you want to the caller override if they wish.

Example
```cpp
int rollDie(side = 6);
void openLogFile(std::string filename = "default.log");
```

## Multiple default arguments
A function can have multiple parameters with default arguments:

*Rule for multiple default argument in CPP*
1. Default parameters can only be supplied to the rightmost parameters in the parameter list.
```cpp
void add(int x = 0, int y = 0); // OK
void add2(int x, int y = 0);    // OK
void add3(int x = 0, int y);    // ERROR
```
2. If more than one default argument exists, the leftmost default arugment should be the one most likely to be explicitly overridden by the caller.
```cpp
int add(int x=0,int y=0,int z=0); // OK

// Function call
int add(1,2); // x=1, y=2, z=0
int add(1);   // x=1, y=0, z=0
int add(,,1); // ERROR not allowed
```

## Default argument can not be redeclared
Once declared, a default argument cannot be redeclared(in the same file). **That means for a function with forward declaration and a function definition, the default argument can only be declared in either the forward declaration or the function definition, but not both.**

Best Practice: Declare default arguments in the function declaration, not the function definition.

## Default arguments and function overloading
Function with default arguments may be overloaded. 

**Example**
[Overloaded function with default argument](practice/overload_function_with_default_argument.cpp)

Note: Parameter with default values will differentiate a function overload
**example**
```cpp
void print(int x);
void print(int x, int y = 4);   // Both of the following function are valid and differentiated.
```

But such function can lead to potentially ambigious function calls.
**example**
```cpp
print(1);   // which function is called? ambigious function call error
```
