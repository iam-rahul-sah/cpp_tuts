# Compound types Enum and Structs

## Table of Content
1. Introduction to user-defined types



## Introduction to user-defined types.  
Fundamental types are defined as the part of core C++ language and thus they are available for immediate use(like int, double) we need not to import anything. This is also true for the compound types that are simple extension of fundamental types like arrays, pointers, references, functions.

But what happens when we need a type that is not provided by C++ or not understood by C++ by default(like fraction). C++ provides a way to define our own types. These types are called user-defined types(or better know as program-defined types).
C++ has two categories of compound types that allows for this:
1. Enumerated types(including scoped and unscoped enums)
2. Class types(including structs and unions)

**Defining program-defined types in C++**  
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

**Type definition are partially extempt from the one definition rule.**  
Each function and global variable can only have one definition per program. As to use a function or global variable the compiler can use the forward declaration of the function and later link the function definition. However, for program defined types the compiler need to know the type definition to solve these problem program defined types are partially extempted from the one definition rule.

Still there are some rules that need to be followed:
1. We can have only one definition per code file(header guards help with this).
2. All of the definition for a given type must be identical or else the behaviour is undefined.

**What would happen if program-defined types were not partially exempt from the one definition rule?**  
In case of function we needs to follow a strict one definition rule within a program. The function declaration are placed in the header file which are then included per code file and the definition to this function is placed at one place inside another code file(thus following the ODR rule). Then the linker can link the function definition to the function declaration. But in case of program-defined types the compiler needs to know the size of the type in order to allocate memory for it. Therefore to propograte the type definition in any code file that need them the type definition are typically placed in a header file and the header file is included in every code file that needs it. If the program-defined types were not partially exempt from the ODR rule then the compiler would have to see the definition of the type in every code file that uses it. This would be very cumbersome and error prone.

**Difference between user-defined types and program-defined types**  
User-defined: A class type or enum type defined by the programmer(including those defined in the standard library or implementation-defined library).
Program-defined: A class type or enum type defined by the programmer.(excluding those defined in the standard library or implementation-defined library).

---