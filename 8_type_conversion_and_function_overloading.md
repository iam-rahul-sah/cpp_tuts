# 1. Implicit type conversion(Coercion)

The process of producing a new value of some type from a value of a different type is called a **conversion**

Type conversion can be invoked in one to two ways:
1. implicitly(by the compiler)
1. explicitly(by the programmer)


## Implicit type conversion
Implicit type conversion(also called as automatic type conversion or 
coercion) is performed automatically by the compiler when one data type is required, but a different data type is supplied.

for example
```cpp
double d{ 3 }; // int value 3 implicitly converted to type double
float f{ 3.0 } // double value 3.0 implicitly converted to type float
double division{4.0/3}; // int value 3 implicitly converted to type double.
```

## What happens when a type conversion is invoked
When a type conversion is invoked(whether implicitly or explicitly), the compiler will determine whether it can convert the value from the current type to the desired type. If a valid conversion can be found, then the compiler will produce a new value of the desired type. If the compiler can't find an acceptable conversion, the compilatiion will fail with a compiler error.

**Note**: Type conversion can fail for number of reasons, for example the compiler is not able to convert a value between the original type and the desired type, or is disallowed by the language(for example narrowing conversion in brace initialization).

## The standard conversions
The C++ language standard defines how different fundamental types(and in some cases, compound types) can be converted to other types. These conversion rules are called the standard conversions.

The standard conversion can be broadly divided into 4 categories, each covering different type of conversions:
- Numeric promotions
- Numeric conversion
- Arithmetic conversions
- Other conversion


When a type conversion is needed, the compiler will see if there are standard conversions that it can use to convert the value to the desired type. The compiler may apply zero, one, or more than one standard conversions in the conversion process.

# 2. Conversion

## Numeric promotion

A **Numeric promotion** is the type conversion of a narrower numeric type(such as a char) to a wider numeric type typically `int` or `double` that can be processed efficiently and is less likely to overflow.

All numeric promotion are value-preserving, meaning that the value of the original type is preserved in the converted type.

Numeric promotion also solves redundancy. 
for e.g. if we had a function that prints a int value, and we want to print a char value or short value, we would have to write a function that prints a char value. But if we have a function that prints a int value, we can pass a char value to it, and the char value will be promoted to int value, and the function will print the int value.

### Numeric promotion categories
The numeric promotion rules are divided into 2 subcategories:
`integral promotions` and `floating point promotions`.

### Floating point promotions

Using the `floating point promotion` rules, a value of type `float` can be converted to a value of type `double`. This means we can a write a function that takes a double and then call it with a either a double or a float value.

### Integral promotions:

Using the integral promotion rules, the following conversions can be made:
- signed char or signed short can be converted to int
- unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type or unsingned int otherwise.
- If char is signed by default, it follows the same rules as signed char. If char is unsigned by default, it follows the same rules as unsigned char.
- bool can be converted to int, with false becoming 0 and true becoming 1.

**Note**: While integral promotion is value-preserving, it does not necessarily preserve the sign(signed/unsigned) of the type. For example, a signed char can be converted to an unsigned int.

### Not all value-preserving conversions are numeric promotions
some value-preserving type conversion (such as `char` to `short`, `int` to `long`, `float` to `double`) are not numeric promotions. These conversions are called **numeric conversions**. This is because such conversions do not assist in the goal of converting smaller types to larger types that can be **processed more efficiently**.

## 3. Numeric conversion

Numeric conversion is the conversion of a value of one numeric type to another numeric type. Numeric conversion cover additional type conversions that are not covered by `numeric promotion`.

There are 5 basic types of numeric conversion

1. Converting an integral type to any other integral type(excluding integral promotion)
```cpp
short s = 3;   // int to short
long l = 3;    // int to long
char ch = 3;  // int to char
```
2. Converting a floating point type to any other floating point type(excluding floating point promotion)
```cpp
float f = 3.0; // double to float
long double ld = 3.0; // double to long double
```
3. converting a floating point type to any integral type
```cpp
int i = 3.5; // double to int
```
4. converting a integral type to any floating point type
```cpp
double d = 3; // int to double
```
5. converting an integral type or a floating point type to a bool
```cpp
bool b1 = 3;   // int to bool
bool b2 = 3.0; // double to bool
```

## Narrowing conversions

A numeric conversion may or may not result in loss of data or precision. some numeric conversion are always safe(int to long, int to double, etc). But some numeric conversion may result in loss of data or precision. For example, converting a double to an int may result in loss of data or precision. Such conversions are called **narrowing conversions**.

Narrowing conversion can occur in the following cases:
1. floating point type to integral type
1. from wider floating point type(double) to narrower floating point type(float)
1. from an integral type to a narrower integral type


Note: The compiler usually warns about narrowing conversions(except when converting from a signed int to an unsigned int).

## Brace initialization disallows narrowing conversions
Narrowing conversion are strictly disallowed when using brace initialization(therfore we should use brace initialization)


## Some basic rule of narrowing conversion
1. In all cases, converting a value into a type whose range doesn’t support that value will lead to results that are probably unexpected. 
2. Converting from a larger integral or floating point type to a smaller type from the same family will generally work so long as the value fits in the range of the smaller type.
3. In the case of floating point values, some rounding may occur due to a loss of precision in the smaller type(float).
4. Converting from an integer to a floating point number generally works as long as the value fits within the range of the floating point type.
5. Converting from a floating point to an integer works as long as the value fits within the range of the integer, but any fractional values are lost.


## Arithmetic conversions

In C++, certain operators requires that their operands be of the same type. If one of these operators is invoked with operands of differeent types, one or both of the operands will be implicitly converted to matching types using a set of rules called the **'usual arithmetic conversions'**.

### The operators that require operands of the same type
- The binary arithmetic operators(`+`, `-`, `*`, `/`, `%`)
- The binary relational operators(`==`, `!=`, `<`, `>`, `<=`, `>=`)
- The binary bitwise operators(`&`, `|`, `^`)
- The conditional operator(`?:`)(the condition must be a bool, and the two operands must be of the same type)


### The usual airthmetic conversions rules.
The usual arithmetic conversion rules are pretty simple. The compiler has a priority list of types, something like this:
- long double(highest)
- double
- float
- unsigned long long
- long long
- unsigned long
- long
- unsigned int
- int(lowest)

### There are only two rules:
1. If the type of at least one of the operand is on the priority list, the operand with lower prority is converted to the type of the operand with higher priority.
e.g. if we have a `int` and a `long`, the `int` will be converted to `long`.
2. Otherwise, if the type of both operands are not on the priority list, both operand are numerically promoted.
e.g. if we have two `short`, both will be converted to `int`.


### signed and unsigned issues
The prioritization hierarchy can cause some problematic issues when mixing signed and unsigned values.

for example subtracting (5u - 10) gives 4294967291, which is not what we expect. This is because the int value of 10 is converted to unsigned int(as it has higher priority then int) and substracting the 5 - 10 gives -5 but unsigned int cannot hold this value so it wraps around and gives 4294967291.

[Program](practice/singed_unsigned_issue.cpp)

# 5. Explicit type conversion (casting) and static_case

C++ comes with a number of different **'type casting operators'** that can be used by programmer to request the compiler to perform a type conversion. Because casts are explicit requests by the programmer, this form of type conversion is often called and **explicit type conversion**.

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

Compiler will ofter issue warnings when a potentially unsafe(narrowing) implicit type conversion is performed. for example, casting an int(4 bytes) to a char(1 byte) will result in a warning(as the compiler can't tell whether the integer value will overflow the range of the char or not). To avoid this warning, we can use `static_cast` to make the narrowing conversion explicit.

# 6. Typedefs and type aliases

**using** is a keyword that creates an alias for an existing data type. 


**Syntax:**
```cpp
using alias_name = type;
using Distance = double; // defines Distance as an alias for type double.

// once defined we can use the type alias as if it were the original type
Distance milesToDestination{3.4};
```
The compiler automatically substitutes the type alias for the original type when it sees it. This is called **type substitution**.

## Common Naming convention for type aliases
- Type aliases that end in a "_t" suffix. Used for the standard library types for globally scoped type names(e.g. size_t, ptrdiff_t, etc)
Note: the `POSIX` reserves the "_t" suffix for globally scoped type name, so using it for type aliases type naming confilict on POSIX systems.

- Type aliases that end in a "_type" suffix. Used for user-defined types.
- Type aliases that use no suffix.

In modern C++, the convention is to name type aliases(or any other type) that you define yourself starting with a capital letter, and using no suffix.
e.g.(Distance)

## Type aliases are not distinct types
An alias does not actually define a new, distinct type. It is just and alternative name for an existing type.

Hence care must be taken not to mix values of aliases that are intended to be semantically distinct.

## The scope of a type alias
Because type aliases are 'identifiers/name' for existing data types. Type alias identifier follow the same scoping rules as variable identifiers: A type alias defined inside a block has a block scope and is usable only within that block, whereas a type alias defined in the global namespace has file scope and is usable to the end of the file.


Note: It is also common to define type aliases in header file, if the type aliases are used in mulitple files in your project.

# Typedefs
A **typedef**(which is short for type definition) is an older way of creating an alias for a type.

**syntax:**
```cpp
typdef type alias_name;
typedef long Distance; // defines Distance as an alias for type long.
```

## Situations when we should use type aliases?

1. Using type aliases for platform independent coding.
We can define a consistent alias for a type that is different on different platforms. e.g. `long` is 4 bytes on 32-bit platforms and 8 bytes on 64-bit platforms. We can define a type alias for `long` that is always 8 bytes long, regardless of the platform.
2. Using type aliases to make complex type easier to read.
In advance C++, types can be complicated and lengthy to manually enter on your keyboard. So we can use type aliases to make the code easier to read.
3. Using type aliases to make code more self-documenting.
for e.g. if we have multiple functions passing or returning a value of same time(ex. total Distance), creating a type alias might be wortwhile.

## Using type aliases for easier code maintenance
for e.g we can use type aliases to make it easier to change the type of a variable or function parameter in the future. By just changing the type in one place.

# 7. Type deduction for object using the auto keyword

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
If we want our automatically deduced variable to be const qualified, we need to explicitly specify the const qualifier again:
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

# 8. Type-deduction for functions

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
```
# 9. Introduction to function overloading

**Function overloading** allows us to create multiple functions with the same name, so long as each identically named function has different parameter types(or the function can be otherwise differentiated). Each function sharing a name(in the same scope) is called an **overloaded function** or **overload**.


Note: Similar named functions will not cause naming conflict. As long as the compiler is able to differentiate by the compiler. If an overloaded function cannot be differentiated by the compiler, a compile error will be generated.

[Example of simple overloaded function](practice/overload.cpp)

## Introduction to overload resolution
When a function call is made to an overloaded function, the compiler must determine which function to call. This process is called **overload resolution**. 


## Making it compile
For a program using overloaded functions to compile,two things have to be true:
1. Each overloaded function has to be differentiated from other.
1. Each call to an overloaded function has to resolve to an overloaded function.


# 10. How overload function are differentiated

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

# 11. Function overload resolution during function call

Having a set of differentiated overloaded function is only half of the picture. When a function call is made, the compiler must also ensure that the correct function is called. This is called function *overload resolution*.

Note: With a non-overloaded function, there is only one function that can match a function call(either directly, or after type conversion) or it doesn't(compiler error.).But with overloaded functions, there may be more than one function that can match a function call. In this case, the compiler must determine which function is the best match.

**[Example of differentiated and unambiguous function call](practice/function_overload_resolution_1.cpp)**


## Resolving overloaded function calls
The compiler steps through a sequence of rule to determine which of the overloaded functions is the best match for the function call. At each step the compiler applies a bunch of type conversion to the argument(s) in the function calls. For each conversion applied, the compiler checks if any of the overloaded function is now a match. After all the different type conversion have been applied and checked for matches, the step is done. The result will be one of the three possible outcomes.

- No matching function were found. The compiler moves to the next step in the sequence.
- A single matching function was found. The Function is considered to be the best match.
- More than one matching function was found. The function call is ambiguous and the compiler will generate an error.

If the compiler reaches the end of the entire sequence without finding a match, It will generate a compiler error that no matching overloaded function can be found for the function call.

## Argument matching sequence
**Step 1**: Exact match. This happens in two phase.
        First: The compiler looks for a function that exactly matches the argument type(s) in the function call. If it finds one, it is considered the best match and the search stops.(like `int` type arguement to an `int` type parameter)
        Second: The compiler may apply `trivial` conversion to the argument in the function call.
        `Trivial` conversion are set of specific conversion rule that will modify type(without modifying the values) for the purpose of matching overloaded function. These include: `const` and `volatile` qualifiers, `signed` and `unsigned` qualifiers

**Note**: Match made via trivial conversion are considered to be an exact match.

**Step 2**: If no exact match is found, the compiler tries to apply numeric promotion to the argument(s). Ex. from char to int, float to double, etc.  
**Step 3**: If no match is found via numeric promotion the compiler tries to find match via numeric conversion. Ex. from int to char, double to int, char to double.  
**Step 4**: If no match is found via numeric conversion, the compiler tries to find match via user-defined conversion. Ex. from user-defined type to another user-defined type.

```cpp
class X
{
    public:
        operator int() {return 0;}
};

void print(int)
{
}

void print(double)
{
}

int main()
{
    X x;
    print(x);  // The function will be resolved int he fourth step as we have user-defined conversion from X to int. A we have a function call with int type argument.

    return 0;
}
```
**Step 5**: If no match is found via user-defined conversion, the compiler will look for matching function that use ellipsis.  
**Step 6**: If no match is found by this point, the compiler give us an error.

## Ambigious match

**Ambigious match** occurs with overloaded function. It occurs when the compiler find two or more function that can be made to match in the same step. When an ambigious match is encountered the compiler gives us an error stating it has found an ambigious function call.

**[Example of numeric conversion from Long to int or long to double](practice/ambiguous_function_call.cpp)**

## Ways for resolving ambigous matches
1. The best way is to simply define a new overloaded function that takes parameter of the type you are trying to call the function with. 
1. Explicitly cast the argument to the type of the parameter you want to call.
1. Using literal suffixes(u for unsigned int, l for long, ll for long long, f for float, etc.) only if we are using literal arguments.

## Matching for function with multiple arguments.
If there are multiple argument, the compiler applies the matching rules to each argument in turn. The function choosen must provide *a better match than all the other candidate function for at least one parameter, and no worse for all of the other parameter*.

```cpp
# include <isotream>

void print(char c, int x)
{
    std::cout << 'a' << '\n';
}

void print(char c, float x)
{
    std::cout << 'b' << '\n';
}

void print(char c, double x)
{
    std::cout << 'c' << '\n';
}
int main()
{
    print('a', 'b')        // This function resolve to print(char c, int x) as it is a better match for the second argument(i.e. numeric converison from char to int) and no worse for the first argument(i.e. exact match for char to char).
}

# 12. Default arguments

A *default argument* is a default value provided for a function parameter. If the caller does not provide an argument for that parameter, the default value will be used instead.

```cpp

void add(int x, int y = 0)   // second parameter has a default argument of 10
{
    return x + y;
}
```

**Note**: We must use an equal sign to specify a default argument, parantheses and brace initialization are not allowed.

A parameter with a default value provided is sometimes know as an *optional parameter*.

## When to use default arguments
Default arguments are an excellent option when a function needs a value that has a reasonable default value, but for which you want the caller to override if they wish.

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
Once declared, a default argument cannot be redeclared(in the same file). *That means for a function with forward declaration and a function definition, the default argument can only be declared in either the forward declaration or the function definition, but not both.*

Best Practice: Declare default arguments in the function declaration, not the function definition.

## Default arguments and function overloading
Function with default arguments may be overloaded. 

**Example**
[Overloaded function with default argument](practice/overload_function_with_default_argument.cpp)

Note: Parameter with default values will differentiate a function overload.


**Example**
```cpp
void print(int x);
void print(int x, int y = 4);   // Both of the following function are valid and differentiated.
```

But such function can lead to potentially ambigious function calls.  

**Example**
```cpp
print(1);   // which function is called? ambigious function call error
```


# 12. Function template

Consider we have written a function max(int, int), this function take integer argument and return the max, now we want to pass two integer value. We can overload the function like max(double, double). Now we can calcuate the max among two double type argument. What if the user want to calculate a value that we didn't anticipated and haven't provided any overloaded function for.

Overloading a function is a maintenance headache, error prone and a viloation of DRY(Don't Repeat Yourself) principle.

## C++ template
In C++, the template system was designed to simplify the process of creating functions(or classes) that are able to work with different data types.

A *template* describe what a function or class look like. Unlike a normal function definition(where all the types must be specified), in a template we can use one or more placeholder type. A placeholder type represent some type that is not know at the time the template is written, but that will be provided later.

Once a template is defined, the compiler can use the template to generate as many overloaded functions(or classes) as needed. Each using different actual types.

## Function template
A *function template* is a function like definition that is used to generate one or more overloaded functions, each with a different set of acutal types, from a single definition.

When we create our function template, we use placeholder types(also called *type template parameter* or *template parameter*) for any parameter type, return type or other types used in the function body that we want to be specified later.

## C++ support 3 different types of template parameter
- Type template parameter(template parameter represent a type)
- Non-type template parameter(template parameter represent a constexpr value)
- Template template parameter(template parameter represent a template)


```
Best practice

Use a single capital letter(starting from T) to name your type template parameters(e.g. T, U, V, etc..)
```

## Creating a template max function
It consist of two steps
1. Define the template with typename replaced by the placeholder type(like T, U, V, etc..) for each distinct type in the function.
1. Telling the compiler that this is a function template, and that `<T>` is a type template parameter. This is done using a *template parameter declaration*

```cpp
template <typename T>   // This is a template parameter declaration
T max(T x, T y)   // This is template definition
{
    return (x > y) ? x : y;
}  // We can also use `class` keyword instead of typename
```

## Function template instantiation
Function template are not actually function. Instead, function templates have one job: to generate functions.

*Syntax*
```cpp
max<actual_dataType>(arg1, arg2);

Example
max<int>(5,6)
```

The type in the angel bracket is called a *template argument*, which specifies the actual type that will be used in place of the template type T.

The process of creating function(with specific types) from function templates(with template types) is called *function template instantiation*. When this process happens due to function call, it's called *implicit instantiation*.

An instantiated function is called a *template function* or *function instance*. Function instance are normal functions in all regards.


So when we call `max<int>(1,2)`, the function that gets instantiated looks something like this:

```cpp
template<>
int max<int>(int x, int y)
{
    return (x > y) ? x : y;
}
```

[Function template example program](/8_type_conversion_and_function_overloading/practice/function_template.cpp)

## Template argument deduction(data inside the angled bracket)

In case where the type of the argument match the actual type we want, we do not need to specify the actual type -- instead, we can use *template argument deduction* to have the compiler deduce the actual that should be used from the argument type in the function call.

### Difference between `max<>()` and `max()`
In the first case(with empty angled brackets), the compiler will only consider `max` function template overloads when determining which overload function to call. In the second case the compiler will consider both `max<>` function template and `max()` non-template function overloads.

```
Best practice
Favour the normal function call syntax when using function teemplates
```

## Function template with non-template parameter
It is possible to create function template that have both template parameter and non-template parameters.  The type template can be matched to any type, and non-template type parameter works like normal function parameter.

## Instantiated functions may not always compile
For e.g. if we call a template function that can only work with numeric data types, and we pass a non-numeric data type(like std::string), the function instance will be created but will not compile.

```cpp
template <>
std::string addOne<std::string>(std::string x)
{
    return x + 1; // This function is instantiated but will not compile
}
```


## Using function template in mulitple files
Function template cannot be used in multiple files like normal function.   

*How is template function not applicable in multiple files?*  
In a file when we call a function template like `addOne<int>` or `addOne<double>` which is only forward declared and no definition is provided, the compiler cannot instantiate those function as it does not know the definition of those function. It does see the forward declaration for `addOne` and assume that function exist elsewhere are will be linked in later.

When the compiler goes to compile the file that contains the definition of `addOne`. It sees the definition but as there is no use of function template in this file the function `addOne<int>` and `addOne<double>` are never instantiated(as in CPP the compiler only know about the file it is compiling). This give a linker error.

## Solution
The most conventioanl way to address this issues is to put all the template code in a header file(.h) instead of a source (.cpp) file.

This does not violate ODR principle as Type, templates, inline function and inline variable are allowed to have identical definintion in different files.

Also multiple instiation of function template does not violate ODR. As these function is inline function.

```
Best practice

Template that are needed in muliplt files should be defined in a header file, and then #included wherever needed. This allows the compiler to see full template definition and instantiate the function as needed.
```

## Generic programming
Because template types can be replaced with an actual type, template type are somtimes called *generic type*. And because template can be written agnostically of specific types, the programming with template is somtimes called *generic programming*.

*Pros of Functional template:*
Functional template can significantly reduce code maintenance and error by minimizing the amount of code that needs to be written and maintained.

*Cons of Function template:*
1. When function template are intiated and large number of instantiation can bloat the code and increase the compile time.
1. The error message are often difficult to understand.

```
Best practice

Use function templates to write generic code that can work with a wide variety of types whenever you have the need.
```

# 15. Function template with multiple template types.

Suppose we have declared a template function with one template type `T` and we want to use that function with two different types `int` and `double`.

```cpp
template <typename T>
T max(T x, T y)
{
    return x > y ? x : y;
}

// Calling the function without any template argument
max(1, 2);  // This will only as both the argument can be decuded to int
max<double>(1, 5.0); // This will also compile as 1 will be implicitly converted to double
max(5,2.8); // This wont compile as both the argument cannot be deduced to same type and no non-template(normal) function is present.
```

Note: Type conversion is done only when resolving function overload, not when performing template argument deduction.

Reasons whey type conversion is intentional.
1. It keeps thing simple, we either find an exact match between the function call argument and template type parameter, or we don't.
1. It allows us to create function template for cases where we want to ensure two or more parameters have the same type.


**Solutions for the above problem**  
1. Use static_cast to convert the argument to one matching type
```cpp
max(static_cast<double>(2), 2.8);
```
2. Writing a non-template function for that type
```cpp
double max(double x, double y);   // though this is of type double, the fucntion call of max(int, double) 
                                  // will be implicitly converted to max(double, double) via numeric conversion.
```
3. Providing explicit type template argument
```cpp
max<double>(2,2.8)
// This will instantiate a function max<double>(double, double) and the function call will be implicitly converted to max(double, double)
```

## Function template with multiple template type parameters
All the above mentioned problems could be solved easily if we have multiple template type parameters.

*Example*
```cpp
template <typename T, typename U> // Here we have use to template type parameter to specify to different types
T max(T x, U y)
{
    return x > y ? x : y;
}
```

Though this program will compile but it has a syntatic error. Consider a function call like `max(10, 2.8)`.

As the logical operator requires both operands of same type and double has precedence over int, the compiler will convert int to double. But the return type is of `int` so the returned value(of type double) will be implicitly converted to int. This will result in loss of data.


*Here we can make use of `auto` keyword to let the function deduce the type based on the return value of the function`

```cpp
template <typename T, typename U>
auto max(T x, U y)
{
    return x > y ? x : y;  // Now this will compile 
}
```
[Program_for_muliple_type_template argument](/practice/function_template_multiple_type.cpp)

## Abbreviated function templates
C++20 introduced a new use of the auto keyword. When the auto keyword is used as a parameter type in a normal function, the compiler will automatically convert the function into a functiono template with each auto parameter becoming an independent template type parameter. This method of creating a function template is called as *abbreviated function template*.

**Example**
```cpp
auto max(auto x, auto y)
{
    return x > y ? x : y;
}
// is equivalent to in C++20
template <typename T, typename U>
{
    return x > y ? x : y;
}
```

```
Best practice

Feel free to use abbreviated function template with a single auto parameter, or where each auto parameter should be an independent type(when language standard is set to 20 or newer)
```

# Non-template type parameter
// Later to be studied