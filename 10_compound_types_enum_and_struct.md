# Compound types Enum and Structs

## Table of Content
1. Introduction to user-defined types



## Introduction to user-defined types.  
Fundamental types are defined as the part of core C++ language and thus they are available for immediate use. Like int, double we need not to import anything this is also true for the compound types that are simple extension of fundamental types like arrays, pointers, references, functions.

But what happens when we need a type that is not provided by C++ or not understood by C++ by default(like fraction). C++ provides a way to define our own types. These types are called user-defined types(or better know as programmer-defined types).
C++ has two categories of compound types that allows for this:
1. Enumerated types(including scoped and unscoped enums)
2. Class types(including structs and unions)

**Defining programme-defined types in C++**  
Just like type aliases program defined types must also be defined before they can be used. The definition for a program defined types is called a **type definition**.

```cpp
// type definition for a fraction
struct Fraction {
    int numerator;
    int denominator;
};
```

**Warning**: Don't forget to end the type definition with a semicolon, otherwise the compiler will typically error on the next line of code.

**Best practice** : Name your program-defined types starting with a capital letter and do not use a suffix.

**Using a program-defined type througout a multi-file program**  
Every code file that uses a program-defined type need to see the full definition before it is used. A forward declaration is not sufficient. This is needed because the compiler needs to know the size of the type in order to allocate memory for it. Therefore to propograte the type definition in any code file that need them the type definition are typically placed in a header file and the header file is included in every code file that needs it.

**Best practice**: A program defined type used in only one code file should be defined in that code file as close to the first point of use as possible.

**Best practice**: A program-defined type used in multiple code file should be defined in a *header file with the same name as the program-defined type* and included in every code file that needs it.

```cpp
// Fraction.h

struct Fraction {
    int numerator;
    int denominator;
};

// main.cpp
#include "Fraction.h"

int main()
{
    Fraction f1;

    return 0;
}
```

**Type definition are partially extempt from the one definition rule**  
Each function and global variable can only have one definition per program. As to use a function or global variable the compiler can use the forward declaration of the function and later link the function definition. However, for program defined types the compiler need to know the type definition to overcome these problem program defined types are partially extempted from the one definition rule.

Still there are some rules that need to be followed:
1. We can have only one definition per code file(header guards help with this).
2. All of the definition for a given type must be identical or else the behaviour is undefined.

**What would happen if program-defined types were not partially exempt from the one definition rule?**  
In case of function which needs to follow a strict one definition rule within a program. The function declaration are placed in the header file which are then included per code file and the definition to this function is placed at one place inside another code file(thus following the ODR rule). Then the linker can link the function definition to the function declaration. But in case of program-defined types the compiler needs to know the size of the type in order to allocate memory for it. Therefore to propograte the type definition in any code file that need them the type definition are typically placed in a header file and the header file is included in every code file that needs it. If the program-defined types were not partially exempt from the ODR rule then the compiler would have to see the definition of the type in every code file that uses it. This would be very cumbersome and error prone.

**Difference between user-defined types and program-defined types**  
User-defined: A class type or enum type defined by the programmer(including those defined in the standard library or implementation-defined library).
Program-defined: A class type or enum type defined by the programmer.(excluding those defined in the standard library or implementation-defined library).

---

## Unscoped enumerations

An **enumeration**(also called as enum) is a compound data type where every possible value is defined as a symbolic constant called an **enumerator**. Enumerations are program-defined types and hence must be defined before they can be used. C++ has two types of enumerations:
1. Unscoped enumerations
2. Scoped enumerations

**Unscoped enumerations**

Unscoped enumerations are defined via the `enum` keyword. 

```cpp
// Example
// Using constant variables with types alias as alternative to enum
using Color = int;

constexpr Color red = 0;
constexpr Color green = 1;
constexpr Color blue = 2;

int main()
{
    Color apple = red;  // This is almost identical to the use of enum

    // But the problem with this approach is that we can assign any integer value to the variable apple
    Color apple = 5;    // This is valid, though it doesn't make sense
}

// Usage of enum can solve this problem as the enum type can only hold the values defined as enumerator any other value will result in error 
enum Color
{
    // Here are the enumerators
    // The symbolic constant(red, green, blue) defines all the possible values this type can hold.
    // Each enumerator is separated by a comma and not a semicolon.
    red, 
    green,
    blue, // trailing comma is optional, but recommended
}// Don't forget the semicolon

int main()
{
    Color apple = red;
    Color shirt = blue;

    Color house = 8;   // This is invalid, as 8 is not defined as an enumerator
    Color cap = white; // This is also invalid, as white is not defined as an enumerator
}  
```

**Naming enumerations and enumerators**

**Warning**: Enumerators don't have to be named, but unnamed enumerators should be avoided in modern C++.
**Best Practice**: Name your *enumerated types starting with a capital letter*. Name your *enumerators starting with a lowercase letter*.

**Enumerated types are distinct types**  
Each enumerated types you create is considered a distinct types, meaning the compiler can distinguish different enum types(unlike typedefsa and type aliases which are considered non-distinct from the type they are using). 

```cpp
// using Pet2 = int;
// using Color2 = int;

// Enum are distinct types
enum Color
{
    red,
    green,
    blue
};
enum Pet
{
    cat,
    dog,
    bird
};

int main()
{
    Color shirt{pig}; // Error: pig is a enumerator of Pet, not Color
    Pet myPet{red};   // Error: red is a enumerator of Color, not Pet

    Pet2 hisPet{8}; // This is valid, as 8 is an int but it is same as int 
}
```

**Use cases of enumerations**  
Because enumerators are descriptive, they are useful for enhancing code documentation and readability. For smallish set of related constants, e.g. days of week, direction, deck of card. Enumerations can also be used to return the status code of some operation from a function, with the return type of the function as the enum type.

Many language use enum for defining boolean values, but in C++ true and false are keyword.

Enum are small and inexpensive to copy. Hence they can be passed by value and return by value.

**Scope of unscoped enumerations**  

The unscoped numerations put the enumerators in the same scope as the enum type itself. This means that the enumerators are visible outside the enum type. This can lead to name collisions. i.e. if a enumerator has the same name as another variable or enumerator in the same scope(global scope or namespace scope) then the program will not compile.

```cpp
// Example

enum Color  // color is defined in the global namespcae
{
    red,    // the enumerators are also defined in the global namespace
    green,
    blue
};

enum Feelings
{
    happy,
    tired,
    blue   // Error: naming collisions with Color::blue 
}
```

Unscoped enumeratos also provide a named scope region for their enumerators(much like a namespace for the variables declared inside of it). But still the unscoped enumerators with same name in the same scope will cause naming collisions.

```cpp
// Example

enum Color
{
    red,
    green,
    blue
};

enum Feeling
{
    happy,
    tired,
    blue     // naming collision compile time error
}

int main()
{
    Color shirt{Color::red}; // Using enum class as namespace for the enumerator

    return 0;
}
```
Thus, mostly unscoped enumerators are accessed without using the scope resolution operator.

**Avoiding enumeratos naming collisions**
1. Prefix each enumerator with the name of the enum type.

```cpp
enum Color
{
    color_red,
    color_green,
}
```
2. Use a namespace for the enum type.

```cpp
namespace color
{
    enum Color
    {
        red,
        green,
    };
}

int main()
{
    color::Color shirt{color::red};
}
```

3. Using scoped enumrations(next topic).
4. If a enumerator is used only inside a function, then we can define the enum type inside the function closest to the first use to the enumerator. The enum type will also shadow the enumerator from the global namespace.

*Best Practice*: Prefer putting your enumerators inside a named scope region(namespace or class) so the enumerators don't pollute the global namespace.

**Comparing against enumerator**  
We can use the equality(==) and inequality(!=) operators to compare whether an enumeration has the value of a particular enumeration or not.

```cpp
// Example
enum Color
{
    red,
    green,
    blue,
}

int main()
{
    Color shirt{red};

    if(shirt == red) // This is valid
    {
        // Do something
    }
    else
    {
        // Do something else
    }
}
```

