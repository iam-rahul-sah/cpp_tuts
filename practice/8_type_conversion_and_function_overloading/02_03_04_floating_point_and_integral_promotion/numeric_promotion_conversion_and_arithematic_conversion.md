# Conversion

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
- singed char or signed short can be converted to int
- unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type or unsingned int otherwise.
- If char is signed by default, it follows the same rules as signed char. If char is unsigned by default, it follows the same rules as unsigned char.
- bool can be converted to int, with false becoming 0 and true becoming 

Note: while integral promotion is value-preserving, it does not necessarily preserve the sign(singed/unsigned) of the type. For example, a signed char can be converted to an unsigned int.

### Not all value-preserving conversions are numeric promotions
some value-preserving type conversion (such as `char` to `short`, `int` to `long`, `float` to `double`) are not numeric promotions. These conversions are called **numeric conversions**. This is because such conversions do not assist in the goral of converting smaller types to larger types that can be **processed more efficiently**.

## Numeric conversion

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

In C++, certain operators requires that their operands be of the same type. If one of these operators is invoked with operands of differeent types, one or both of the operands will be implicitly converted to matching types using a set of rules called the ** usual arithmetic conversions**.

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