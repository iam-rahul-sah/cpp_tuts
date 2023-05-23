# Compound Types: Reference and Pointer

# 1. Introduction to compound data types

*Compound Data types*(or composite data types) are data types that are constructed from fundamental data types. Each compound data types has it unique properties.

## Compound Data types in C++
- Functions
- Array
- Pointer types:
    - Pointer to object
    - Pointer to function
- Pointer to member types:
    - Pointer to data member
    - Pointer to member function
- Reference types:
    - L value reference
    - R value reference
- Enumeration types:
    - Unscoped enumeration
    - scoped enumeration
- Class types:
    - structs
    - classes
    - unions

## How is function a compound data type?
The type of a function is `void(int, double)`. It is composed of fundamental types making it a compound data type and a function has a unique property of being called.

---
# 2. Value categories(Lvalue and Rvalue)


## Properties of an expression
To help determine how expression should evaluate and where they can be used, all expression in C++ have two properties: a *type* and a *value category*.

### 1. The Type of an Expression

The type of an expression is equivalent to the type of the value, object or function that reults from the evaluated expression.

Example
```cpp
auto v1 {3/4}; // Here the type of expression is int
auto v2 {3.0/4}; // Here the type of expression is double
```

The type of expression is used by the compiler to check if the expression is valid in a given context or not.

Example.
If a function requires `int` variable or expression and we pass a `string` variable or expression, the compiler will throw an error.

Type of an expression must be determiable at compile time(otherwise type-checking and type-deduction wouldn't be possible).    

The value of expression may be determined at either compile time(in case of a constexpr) or runtime(if the expression is not constexpr).


### 2. The value category of an expression

Example
```cpp
x = 5;  // This is a valid expression
5 = x;  // This is not a valid expression.
```
How does a compiler know that the first expression is valid and the second one is not? The answer is *value category*.

A *value categroy* of an expression indicates whether an expression resolves to a value, a function or an object of some kind.

Prior to C++11, ther were only two value categories: 
`Lvalue` and `Rvalue`.

In C++11 three additional value categories(`glvalue`, `prvalue` and `xvalue`) were added to support `move semantics`.

## Lvalue
An `lvalue`(also know as locater value) is an expression that evaluates to an identifiable object or function(or bit field).

The term "identity" is used in C++ standard, but it not well defined. An entity(such as object or function) that has an identity can be differentiated from other similar entities typically by comparing their addresses.

Entities with identities can be accessed via identifiers, reference, or pointer and typically have a longer lifetime than a single expression or statement.

*Example Of lvalue*
```cpp
int x {5};  // x over here is a lvalue
int y {x};  // here x and y are lvalue
```

### There are two types of lvalue
1. Modifiable lvalue  

*Example*

```cpp
int x {5};
int y {x};   // here x is a modifiable lvalue
```

2. non-modifiable lvalue

*Example*
```cpp
const double pi {3.14};

const double e{pi};  // here pi is a non-modifiable lvalue.
```

## rvalue
An *rvalue* is an expression that is not an lvalue. Commonly seen rvalues are literal(except C-style string, which is an lvalue), temporary object, or result of an expression a return value from a function or an expression who value exists only for the duration of the expression. Rvalues aren't identifiable.

*Example of rvalue*
```cpp
int return5() { return 5; }

int main()
{
    int x{5}; // here x is an lvalue and 5 is an rvalue
    int z{ return5() }; // here return5() is an rvalue
    int a{x + 1}; // here x + 1 is an rvalue
    char c{static_cast<char>(x)}; // here static_cast<char>(x) is an rvalue
}
```

here `return5()`, `x + 1` and `static_cast<char>(x)` are rvalues as all of these value are temporary and aren't identifiable after the expression is evaluated.

Note: An assignment operator(=) requires an lvalue as its left operand and an rvalue as its right operand.

## L-value and R-value conversion

Earlier we said that the assignment operator needs it right operand to be an rvalue. But what if we pass an lvalue as a right operand?
*Example*
```cpp
int x {5};
int y {x}; // here x is an lvalue which is the right operand of assignment operator
```

Here the lvalue is implicitly converted to rvalue, so an lvalue can be used wherever an rvalue is required.

### Rule of thumb to identify lvalue and rvalue
- `Lvalue` expression are those that evaluate to variable or other identifiable objects that persist beyond the end of expression.
- `Rvalue` expression are those that evaluate to literals or value returned by functions/operators that are discarded at the end of expression.

---

# 3. Lvalue reference

A reference is an alias for an existing object. Once a reference has been defined any on the reference is applied to the object being referenced. Reference are widely used

There are two types of references:
1. Lvalue reference
1. Rvalue reference

__To declare an lvalue reference we use an ampersand(&) in the type declaration__
*Example*
```cpp
int& ref {x}; // here ref is an lvalue reference to x
double &ref2 {pi}; // here ref2 is an lvalue reference to pi. This is also valid but not recommended

// Just for fun
int&& ref3 {x}; // here ref3 is an rvalue reference to x
```

Lvalue reference type is used to lvalue reference variable. Lvalue reference variable can only be initialized with lvalue. An *lvalue reference variable* act as an alias to the object it is referencing.

```text
Best practice

When defining a reference, place the ampersand next to the type(not next to the referenced variable's name).
```


Note: We can modify and read value using a lvalue reference variable of the variable that it is referencing.

*Example*
```cpp

int x {5};
int& y{x}; // here y is an lvalue reference to x

std::cout << y; // here we are reading the value of x using y

y = 55; // here we are modifying the value of x using y
std::cout << x; // here we are reading the modified value of x
```

## Intializing lvalue reference
All references must be initialized(Just like constant).

*Bound*: When a reference is initialized with an object(or function), we say it is *bound* to the object(or function).

*Reference binding*: The process by which a reference becomes bound to an object(or function) is called *reference binding*.

*referent*: The object(or function) to which the reference is bound is called *referent*.

Note: Lvalue reference must be bound to a modifiable lvalue. Lvalue reference can't be bound to a literal, rvalue or non-modifiable lvalue(otherwise we could change the value using the reference which would violate the constness of the original object). lvalue are also called non-const reference.

In most cases, the type of reference must match the type of the object(or function) being referenced(i.e. referent). There are few exceptions to this rule.

Lvalue refernces to `void` are not allowed.

*Example*
```cpp
int x {5};
int& y {x}; // here y is an lvalue reference to x

double& z {x}; // this is not allowed as z is an lvalue reference to double and x is an int
int& z{5}; // this is not allowed as z is an lvalue reference to int and 5 is an rvalue
const int a {5};
int& c {a}; // this is not allowed as c is an lvalue reference to int and a is a non-modifiable lvalue
```

## Reference can't be reseted
Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object.

*Example*
```cpp
int x{5};
int y{10};

int& ref{x}; // here ref is an lvalue reference to x

ref = y; // here we are not changing the reference to y, we are just changing the value of x to y
```

## Scoping of reference variable
A refernce variable follows the same scoping and duration rule that normal variable do.

### Reference and referent have independent lifetimes.(With one exception)
i.e.
1. The reference can be destroyed before the object it is referencing.(Completely fine)
1. The object being referenced can be destroyed before the reference.(*Dangling reference*)


## Dangling reference
When an object being reference is destroyed before a reference to it, the reference is left referencing an object that no longer exists. Such a reference is called a *dangling reference*.

# 4. Lvalue reference to const

A lvalue reference variable cannot reference a non-modifiable variable. But we can add `const` keyword before lvalue reference variable to make it reference a non-modifiable variable. These variable are know as *lvalue reference to const* or *const reference*.

*Example*
```cpp
const int x{5};
const int& y{x}; // here y is an lvalue reference to const

// we can only use const reference to read the value of the variable, we are not able to modify the variable.
```

## lvalue reference to const with a modifiable value
We can also bind lvalue reference to const to modifiable value. In such case, the object being referenced is treated as const when accessed through the reference. When the referent is addressed directly, it is still modifiable.

*Example*
```cpp

int x{5};
const int& ref{x};

std::cout << ref; // here we are reading the value of x using constant reference
ref = 6; // this is not allowed as ref is a constant reference

x = 6; // this is allowed as x is a modifiable lvalue
```

```
Best Practice
Favour lvalue reference to const over lvalue reference to non-const unless you need to modify the object being referenced.
```


## Initializing an lvalue reference to const with an rvalue

With lvalue reference to const we can also reference rvalue, which is not possible with lvalue reference to non-const.

```cpp
const int& ref{5}; // here ref is an lvalue reference to const
```

## Behind the scene
Behind the scene what C++ does it creates a temporary object(anonymous object) for the rvalue and then binds the reference to that temporary object. This temporary object is destroyed at the end of the statement.(This temporary object has no scope).

## So once the temporary variable is destroyed is the reference a dangling reference?
No, When a const lvalue reference is bound to temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference. This is called *reference lifetime extension*.

## Key point
1. lvalue reference can only bind to modifiable lvalue.
1. lvalue reference to const can bind to modifiable lvalue, non-modifiable lvalue, and rvalues. This make them much more flexible type of reference.

# Pass by lvalue reference

## Use cases of pass by references

1. To pass large objects without making a copy.
Pass by reference can be used to avoid making an expensive copy(like string and other class type) of an argument when calling a function. The reference in the function header are bounded to the argument passed in and act as an alais to the object, being passed in so no copy is made. 

*Example*
```cpp
void printValue(std::string& value) {   // here the parameter is a reference to string so no copy is made
    std::cout << value;
}

int main()
{
    std::string name {"Frank"};
    printValue(name); // here we are passing the name by reference
}
```

- Binding a reference is always inexpensive. 

2. To modify the parameter passed in.

In case of a pass by value, the function parameter is a copy of the argument passed in. So any modification made to the parameter inside the function is not reflected in the argument passed in. But in case of pass by reference, the parameter is an alias to the argument passed in. So any modification made to the parameter inside the function is reflected in the argument passed in.

*Example*
```cpp
int increment(int y)
{
    ++y;                   // here we are modifying the parameter, so y is incremented and destroyed
}

int increment(int& y)
{
    ++y;                   // here we are modifying the argument passed in, so y is incremented
}
```


## Pass by reference to non const(non const references) can only accept accept modifiable lvalues(non const lvalues)

As reference to non const can only accept modifiable lvalues, so we can't pass rvalues or const lvalues or rvalues to them.
*Example*
```cpp
int printValue(int& value)
{
    std::cout << value;
} 

int main()
{
    int x{5};
    printValue(x); // this is fine as x is a modifiable lvalue

    const int y{5};
    printValue(y); // this is not allowed as y is a non modifiable lvalue
    
    printValue(5); // this is not allowed as 5 is an rvalue
}
```
## Using const reference to pass modifiable lvalues, non modifiable lvalues and rvalues

A reference to const value can be bounded to modifiable lvalue, non modifiable lvalue and rvalues. So we can use reference to const to pass modifiable lvalue, non modifiable lvalue and rvalues. const reference also guarantees that the argument passed in will not be modified inside the function.

*Example*
```cpp

int printValue(const int& value)
{
    std::cout << value;
}

printValue(5); // This will work
const int z{5};
printValue(z); // This will work
```

## Mixing pass by value and pass by reference
A function with multiple parameters can determine whether each parameter is passed by value or passed by reference indivually.

**Example**
```cpp
void foo(int x, int& y, const string& name);
```

## when to pass by reference
Since most of the class types are expensive to copy it is advised to pass by class type with const reference and fundamental types with `pass by value`.

## Cost of pass by value vs pass by reference

for fundamental data types pass by value cost the same as pass by reference. But accessing a reference is slightly slower than accessing a value as it adds an addtional step of redirection. Whereas for expensive type pass by value is much more expensive than pass by reference. So for fundamental types always use pass by value and for expensive types use pass by reference. We shouldn't be using pass by reference for all types(both fundamental and expensive).

# Introduction to pointers.

## The address-of operator(&)
The address-of operator returns the memory address of it operand

*Example*
```cpp
int x{5};

std::cout << &x; // this will print the memory address of x
```

For object that use more than one byte of memory, the address-of operator returns the address of the first byte of memory used by the object.

## Different context for the address-of operator(&)
1. When used with a variable, it returns the address of the variable. `&x`
1. When used following a type name, & denotes a lvalue reference. `int& x`
1. When used in binary context in a expression, & is a bitwise AND operator. `x & y`


## Dereference operator(*)
The dereference operator returns the value at a given memory address as an lvalue.`*x`

## Pointer
A *pointer* is an object that holds a memory address(typically of another variable as its value). We can use the address of this object later.

pointer types are declared using an asterisk(*) placed after the type name and before the identifier.
*Example*

```cpp
int x{5};
int& ref{x}; // here ref is a reference to an integer
int* ptr{&x}; // here ptr is a pointer to an integer
```

## Pointer initialization
A pointer that has not been initialized is called a *wild pointer*. A wild pointer can point to any memory address. Dereferencing a wild pointer can cause undefined behaviour.

```
Best Practice
Always initialize you pointer variables.
``` 

*Example*
```cpp
int* ptr; // this is a wild pointer
int* ptr{}; // this is a null pointer
int* ptr{&x}; // this is a pointer to x
```
    
## Pointer values
A pointer holds and address and hence the value used to initialize a pointer is an address. A variable with the address of operator is used to initialize a pointer.

`int* ptr{&x};`

A dereference operator can be used to access the value at the address stored in a pointer.  

`*ptr`

Note: The type of the pointer has to match the type of object being pointed to. Similar to a reference.

Note: Initializing a pointer with a literal value is not allowed.

*Example*
```cpp
int i{5};
double d{5.0};

int* ptr{&i}; // this is fine
int* ptr{&d}; // this is not allowed

int* ptr{5}; // this is not allowed
```

## Pointer and assignment

We can use assignment with pointers in two different ways
1. To change what the pointer is pointing at(by assigning the pointer a new address)
*Example*

```cpp

int x{5};

int* ptr{&x}; // ptr is now pointing to x

int y{10};
prt = &y; // ptr is now pointing to y

```
2. To change the value being pointed at(by assigning the dereferenced pointer a new value)
*Example*

```cpp
int x{5};

int* ptr{&x}; // ptr is now pointing to x
*ptr = 10; // x is now 10
```


## Pointer behave much like lvalue references with some difference

*Example*
```cpp

int x{5};
int& ref{x}; // ref is a reference to x
int* ptr{&x}; // ptr is a pointer to x

std::cout << x; // 5
std::cout << ref; // 5
std::cout << *ptr; // 5

ref = 10; // x is now 10

std::cout << x; // 10
std::cout << ref; // 10
std::cout << *ptr; // 10

*ptr = 20; // x is now 20

std::cout << x; // 20
std::cout << ref; // 20
std::cout << *ptr; // 20

```

### Difference between pointer and reference

| Reference | Pointer |
|-----------|---------|
| Reference must be initialized when declared | pointers are not required to be initialized |
| Reference are not objects | Pointers are objects |
| References cannot be reseated(i.e. changed to point something else) | Pointers can change what they are pointing to |
| References cannot be null(i.e. should be always bound to an object) | Pointers can be null |
| References are generally safe(except dangling reference)| pointers are inherently dangerous |

### The address of operator returns a pointer
Note: The address of operator does not return a literal denoting the address value, but it returns a pointer of the type of the operand.

*Example*
```cpp

int x{5};
std::cout << typeid(&x).name(); // Pi, where pi is a pointer to an integer
```

## Size of pointer

The size of a pointer is dependent on the architecture of the machine. On a 32 bit machine the size of a pointer is 4 bytes and on a 64 bit machine the size of a pointer is 8 bytes. As a pointer should be able to address the largest memory location on the machine.

Note: Size of a pointer does not depend on the type of the variable it is pointing to. It is always the same.

## Dangling pointer
Much like a dangling reference, a dangling pointer is a pointer that is holding the address of a object that is no longer valid.

Dereferencing a dangling pointer can cause undefined behaviour.

*Example*
```cpp
int x{5};
int* ptr{&x};

{
    int y{10};
    ptr = &y;
} // y is destroyed here

std::cout << *ptr ; // undefined behaviour
```

# Null Pointer

When a poiner is holding a null value, it means the pointer is not pointing at anything. Such a pointer is called a null pointer.

```dotnetcli
Best practice
Value initalize your pointer(to be null pointers) if you are not initializing them with the address of a valid object.
```

Note: A pointer initially set to null can later be changed to point a valid object.

### The `nullptr` keyword

The nullptr keyword is used to initialize a pointer to null.

```cpp
int* ptr{nullptr}; // ptr is now a null pointer

int* ptr2{}; // This is also a null pointer

int* ptr3; // This is a wild pointer

// We can change what the null pointer is pointing to.

int x{5};
ptr = &x; // ptr is now pointing to x
```

```dotnetcli
Best practice
Use 'nullptr' when we need a null pointer literal for initialization, assignment or passing a null pointer to a function also for comparisons.
```


### Derefencing a null pointer results in undefined behaviour.

### Conditional using null pointer

In cpp a null pointer is implicitly converted to false boolean value and a non-null pointer is implicitly converted to true boolean value.

*Example*
```cpp
int* ptr{nullptr};

if(ptr == nullptr)
{
    // code
}
else
{
    // code
}

// We can also skip the nullptr keyword and use the pointer directly in the if condition as a null pointer will implicitly converted to a boolean value
```

Note: We can only differentiate if a pointer is null pointer or not. We cannot differentiate if a non-null pointer is pointing to a valid object or dangling pointer. Therefore it is a good practice to set a pointer to null after the object it is pointing to is destroyed.

```dotnetcli
Best practice

A pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for null, and can assume any non-null pointer is valid.
```

### Legacy null pointer: `NULL` and `0`

In C++ we can use `NULL`(defined in 'cstddef' header inherited from C) and `0` to initialize a pointer to null. But it is not recommended to use them as they should be avoided in modern C++.


### Favour references over pointer whenever possible.

Pointr have additional ability of being able to change what they are pointing at, and to be pointed at null. This is inherently dangerous. The these abilities can make creating dangling pointer easier and we can also deference a null pointer which can cause undefined behaviour.

Whereas as for references, we cannot reference a null object and we cannot change what they are referencing. Dangling references are hader to create.

```dotnetcli
Best practice

Favour references over pointer unless the additional capabilities provided by the pointer are needed.
```