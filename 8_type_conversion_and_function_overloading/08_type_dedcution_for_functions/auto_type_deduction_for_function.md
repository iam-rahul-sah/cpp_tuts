# Type-deduction for functions

In C++14, the `auto` keyword was extended to do function return type deduction. This workd by using the `auto` keyword in place of the return type of a function. The compiler will deduce the return type of the function based on the return statement.

```cpp
auto add(int x, int y)
{
    return x + y;
}
```

Note: When using `auto` return type, all return statements withing the function must return values of the same type, otherwise an error will result.

**Example**
```cpp
auto someFunction(bool b)
{
    if(b)
        return 1;   // return type int
    else
        return 2.0; // return type double 
}
// here in this function, the two return statements return values of different types, so the compiler will give an error.
```

Note: A major downside of function that use an `auto` return type is that such functions must be fully defined before they can be used(a forward declration is not sufficient)

```cpp
auto add(int x, int y); // forward declaration

int main()
{
    add(1, 2);  // error: a function that returns 'auto' cannot 
                // be used before it is defined.
    return 0;
}
auto foo(int x, int y) // definition
{
    return x + y;
}
```

This is becuase a forward declaration of a function that returns `auto` does not provide enough information for the compiler to deduce the return type of the function. The compiler needs to see the function body to deduce the return type.


## Trailing return type syntax

The `auto` keyword can also be used to declare function using a `trailing return syntax`, where the return type is specified after function header using the `->` operator.

Note: `auto` keyword in a trailing return type does not perform type deduction -- it is just part of the syntax to use a trailing return type.

```cpp
auto add(int x, int y) -> int
{
    return(x + y);
}
```

1. A trailing header can be used to align our function prototype.
1. The trailing return syntax is also required for some advance features of C++, such as lambdas.


**use  the traditional function return syntax except in situations that require the trailing return syntax.**

## Type deduction can't be used for function parameter types
Prior to C++20 `auto` didn't work for function parameters. 
In C++20, the `auto` was extended to work for function parameters.

Note: the `auto` keyword used for function parameters is not type deduction. Rather, it is triggering a different feature called `function template` that was designed to actually handle such cases.

```cpp

void addAndPrint(auto x, auto y)
{
    std::cout << x + y << '\n';
}

int main()
{
    addAndPrint(2,3);
    addAndPrint(2.0, 3.0);
    return 0;
// prior to C++20 the above code would not compile, but after C++20 it will compile due to function template.
    
}