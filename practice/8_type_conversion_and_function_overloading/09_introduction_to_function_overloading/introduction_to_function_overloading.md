# Introduction to function overloading

**Function overloading** allows us to create multiple functions with the same name, so long as each identically named function has different parameter types(or the function can be otherwise differentiated). Each function sharing a name(in the same scope) is called an **overloaded function** or **overload**.


Note: Similar named functions will not cause naming conflict. As long as the compiler is able to differentiate by the compiler. If an overloaded function cannot be differentiated by the compiler, a compile error will be generated.

[Example of simple overloaded function](practice/overload.cpp)

## Introduction to overload resolution
When a function call is made to an overloaded function, the compiler must determine which function to call. This process is called **overload resolution**. 


## Making it compile
For a program using overloaded functions to compile,tow things have to be true:
1. Each overloaded function has to be differentiated from other.
1. Each call to an overloaded function has to resolve to an overloaded function.