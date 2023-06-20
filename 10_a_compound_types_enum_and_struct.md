# Compound types Enum

## Table of Content
1. Introduction to user-defined types



## Introduction to user-defined types.  
Fundamental types are defined as the part of core C++ language and thus they are available for immediate use(like int, double), we need not to import anything. This is also true for the compound types that are simple extension of fundamental types like arrays, pointers, references, functions.

But what happens when we need a type that is not provided by C++ or not understood by C++ by default(like fraction). C++ provides a way to define our own types. These types are called user-defined types(or better know as programmer-defined types).
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

**Unscoped enum input and output**

Enumerators are integers symbolic constants(i.e. enum type actually holds an integer value). Similar to how `char` datatypes is actually an integer type that holds a character value. 

When an enumeration is defined the enumerator are automatically assigned integer values starting with 0. The value of each subsequent enumerator is one greater than the previous enumerator. 

We can also assign number to the enumerator explicitly. These integeral values can be *positive, negative or can share same number*(in which case the enumerator are indistinguishable and can be used intercangeably). Any non-defined enumerator will be assigned the value of the previous enumerator plus one.

```cpp
// Example

// Enumerators are automatically assigned integer values starting with 0
enum Color
{
    red,   // 0
    blue,  // 1
    black, //2
    white, // 3
    green, // 4
};

// Enumeratos with explicit assignment
enum Feeling
{
    happy = 1,
    mounrful, // assigned 2
    sad = -1,
    tired = 5,
    restless = 5,  // same as tired as both have same value, can be used intercangeably
    energetic = 6,
    enraged,  // 7(previous enumerator + 1)
};


// Enumeratos are implicitly converted to integers
int main()
{
    Color shirt{red};
    Color pant{5}; // This is valid, but not recommended

    std::cout << shirt;  // return 0;
    std::cout << pant;   // return 5;
}

```

*Best practice*: Avoid explicitly assigning values to enumerators unless you have a good reason to do so.

**Why are enumerator outputed as integers?**
When an enumerator type is used with a function or operator(output operator), the compiler first try to find a function or operator that matches the enumerator type. If the compiler can't find a match, the compiler will then implicitly convert the unscoped enumeration to its corresponding integer value. Which is then again matched against the function and the operators.

**Printing enumerator names**
1. Using if-else chain
2. Using switch statement
```cpp
// Example
#include <iostream>

enum Color
{
    red,
    blue,
    green,
};

// using if-else chain
void printColorUsingIfElse(Color color)
{
    if (color == red)
    {
        std::cout << "red";
    }
    else if (color == blue)
    {
        std::cout << "blue";
    }
    else if (color == green)
    {
        std::cout << "green";
    }
    else
    {
        std::cout << "who knows";
    }
}

// using switch statement
void printColorUsingSwitch(Color color)
{
    switch (color)
    {
    case red:
        std::cout << "red";
        break;
    case blue:
        std::cout << "blue";
        break;
    case green:
        std::cout << "green";
        break;
    }
}

// Returning the color as string_view(inexpensive to return) to provide more flexibility and optimization
std::string_view getColorUsingSwitch(Color color)
{
    switch (color)
    {
    case red:
        return "red";
    case blue:
        return "blue";
    case green:
        return "green";
    default:
        return "No one knows";
    }
}
int main()
{
    Color shirt{red};
    printColorUsingIfElse(shirt); // prints red
    std::cout << '\n';
    printColorUsingSwitch(shirt); // prints red
    std::cout << '\n';

    std::cout << "The color of your shirt is " << getColorUsingSwitch(shirt) << '\n';
}
```

**Overloading operators<< for enumerators(program-defined type)**

```cpp
// Solution

enum Color
{
    red,
    blue,
    green,
};

// overloading operator<< for Color enum type
// operator<< returns std::ostream& type so that we can chain multiple operator<< calls
// the return type and parameter type are references(to prevent copies from being made)
std::ostream& operator<<(std::ostream& out, Color color)
{
    switch(color)
    {
        case red: return out << "red";
        case blue: return out << "blue";
        case green: return out << "green";
    }
}

int main()
{
    Color shirt{red};
    std::cout << shirt; // prints red
}
```

**Enumeration size and underlying type(base)**
Enumeration type are integral constant. The specific integral type used to represent the enumerator is called the *underlying type* or *base*. C++ does not specify the base for unscoped enumerations, but it is usually `int`. It is possible to specify different underlying type for enumerations like.

```cpp

enum Color : std::int8_t // in cstdint header file
{
    red,
    blue,
    green,
};
```  

*Best practice*: Specify the base type of an enumeration only when necessary.
*Warning*: Do not use std::int8_t or std::uint8_t as they are type aliases for char, which can case undefined behaviour.

**Integer to unscoped enumerator conversion(Example for taking input)**
A compiler does not implicitly convert an integer to its corresponding enumerator. This can be done in two ways.

1. Using static_cast.
2. By specifying base and brace initialization: From C++17, if a unscoped enumeration has a specified base, then the compiler will allow you to list(brace) initialize an unscoped enumeration using integral value.


```cpp
// Example

enum Color
{
    red, // assigned 0
    blue, // assigned 1
    green, // assgined 2
}

enum Pet: int
{
    dog,
    cat,
    fish
}
int main()
{
    Color shirt{2};   // Error as implicit conversion from int to enum type is not possible
    shirt = 0;        // Error

    // using static_cast for conversion
    Color shirt{static_cast<Color>(2)};
    shirt = static_cast<Color>(1);

    Pet myPet{1};  // okay as we have specified the base for the enum type
    Pet hisPet(0); // error: cannot direct initialize with integer
    Pet yourPet{2}; // error: cannot copy initialize with integer

    return 0;
}
```

**Unscoped enumerator input**

*Because pet is a program-defined type, the language doen't know how to input a Pet using std::cin*

```cpp

Pet myPet{pig};
std::cin >> myPet; // compile time error, C++ doen't know how to input Pet enum
```

*Work around this*
1. Taking an integer as input and then static_cast it to assign.
```cpp

enum Pet
{
    dog,
    cat,
    elephant
};

int main()
{
    std::cout << "Enter your pet(0=Dog, 1=Cat, 2=Elephant): ";

    int input{};
    std::cin >> input;

    Pet myPet{static_cast<Pet>(input)};

}
```

**Overloading input operator>> for accepting Pet enum input**

```cpp
//Example
#include <iostream>

enum Pet
{
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
};

// We pass pet by reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Pet& pet)
{
    int input{};
    in >> input; // input an integer

    pet = static_cast<Pet>(input);
    return in;
}

int main()
{
    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    Pet pet{};
    std::cin >> pet; // input our pet using std::cin

    std::cout << pet << '\n'; // prove that it worked

    return 0;
}
```

**Scoped enumeration(enum classes)**

Unscoped enumeration are distinct types in C++, but they are not type safe.

```cpp
// Example

enum Color
{
    red,  // assigned 0
    blue, // assigned 1
};

enum Fruit
{
    banana, // assigned 0
    mango,  // assigned 1
}

int main()
{
    Color someColor{red};
    Fruit somFruit{banana};
    
    if(someColor == someFruit)
    {
        // this evaluates to true as enum is converted to 0 == 0
    }
    else
    {
        // do something
    }

    std::cout << someColor << '\n'; // also this will give us an error as scoped enums are not implictly converted and std::cout doen't not know how to handle this data type.
}
```

Thus, because of this problem and namespace pollution problem scoped enumerator were introduced.

*Scoped enumerator*
Scoped enumerator are almost similar to unscoped enumerator with only two difference.
1. They are strongly typed that is they are not implicitly converted to integer values.
2. Strongly scoped(the enumerator are only placed in the scope regions of the enumeration).

We use the `enum class` keyword for defining a scoped enumerator. Enumerator can only be accessed using enum class type as their namespace and enum is not implicitly converted to int.

```cpp
// Example
enum class Color
{
    red,  // assigned 0
    blue, // assigned 1
};

enum class Fruit
{
    banana, // assigned 0
    mango,  // assigned 1
}

int main()
{
    Color someColor{Color::red};  // enumerator is accessible only using the enum class name
    Fruit somFruit{Fruit::banana};
    
    if(someColor == someFruit)  // here the variable are not implicitly converted and as the compiler doesn't know how to compare Color and Fruit enum type it gives us an error
    {
        // do something
    }
    else
    {
        // do something
    }

    return 0;
}
```

**Scoped enumerations don't implicitly converts to integers**  
Scoped enumeration do not implicitly convert to integers which is useful as it avoid us from making syntactic error by comparing different enum type. But we can still compare variable of one enum type. But some times it is necessary to make the conversion so we can use "static_cast", C++23 onwards we can also make use of "std::to_underlying()"(defined in the utility header), this converts enumerator to the value of the underlying type of enumeration.

```cpp
// Example

#include <utility>

int main()
{
    enum class Color
    {
        red, 
        blue,
    };

    Color shirt{Color::red};

    std::cout << shirt << '\n';  // This gives us an error
    std::cout << static_cast<int>(shirt) << '\n'; // Explicit conversion of int 1
    std::cout << std::to_underlying(shirt) << '\n'; // convert to the underlying type print 1
}
```

**Note**: As of C++17 we can initialize scoped enumeration variable using integral value(unlike unscoped enumeration , we do not need to specify the base.)
```cpp
//Example
int main()
{
    enum class Color
    {
        red, 
        blue,
    };

    Color shirt{1};

    std::cout << std::boolalpha << '\n';
    std::cout << (shirt == Color::blue) << '\n';

    std::cout << static_cast<int>(shirt) << '\n';
}
```

**Best Practice**: Favor scoped enumeration over unscoped enumeration unless there's a compelling reason to do so.

**Easing the conversion of scoped enumeration to integers(advance)**

1. Overloading Unary addition operator to do so.
```cpp
// Example
#include <iostream>

enum class Animals
{
    chicken, // 0
    dog, // 1
    cat, // 2
    elephant, // 3
    duck, // 4
    snake, // 5

    maxAnimals,
};

// Overload the unary + operator to convert Animals to the underlying type
constexpr auto operator+(Animals a) noexcept
{
    return static_cast<std::underlying_type_t<Animals>>(a);
}

int main()
{
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an integer using unary operator+

    return 0;
}
```

**`using enum` statement(C++20) to avoid perfixing every enumerator with the enum class name**  
`using enum enumName` import all the enumerator from an enum into the current scope. So that we can access enum class enumerator without prefix each with the name of enum class.

**Exercise solution**
Printing the number of legs given the enumarator on animal class
```cpp
#include<iostream>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal animal)
{
    using enum Animal;
    switch(animal)
    {
        case pig:
            return "pig";
        case chicken:
            return "chicken";
        case goat:
            return "goat";
        case cat:
            return "cat";
        case dog:
            return "dog";
        case duck:
            return "duck";
        default:
            return "Unspecified animal species";
    }
}

void printNumberOfLegs(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
    case pig:
    case goat:
    case cat:
    case dog:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs\n";
        break;
    case chicken:
    case duck:
        std::cout << "A " << getAnimalName(animal) << " has 2 legs\n";
        break;
    default:
        std::cout << "unspecified animal specifies" << '\n';
        break;
    }
}

int main()
{

    Animal myAnimal{Animal::cat};
    Animal myPollutryAnimal{Animal::chicken};

    printNumberOfLegs(myAnimal);
    printNumberOfLegs(myPollutryAnimal);
    
    return 0;
}
```
