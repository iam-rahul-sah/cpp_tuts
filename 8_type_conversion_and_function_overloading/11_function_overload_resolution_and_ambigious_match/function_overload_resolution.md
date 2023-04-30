# Function overload resolution during function call

Having a set of differentiated overloaded function is only half of the picture. When a function call is made, the compiler must also ensure that the correct function is called. This is called function *overload resolution*.

Note: With a non-overloaded function, there is only one function that can match a function call(either direclty, or after type conversion) or it doesn't(compiler error.).But with overloaded functions, there may be more than one function that can match a function call. In this case, the compiler must determine which function is the best match.

**[Example of differentiated and unambiguous function call](practice/function_overload_resolution_1.cpp)**


## Resolving overloaded function calls
The compiler steps through a sequence of rule to determine which of the overloaded functions is the best match for the function call. At each step the compiler applies a bunch of type conversion to the argument(s) in the function calls. For each conversion applied, the compiler checks if any of the overloaded function is now a match. After all the different type conversion have been applied and checked for matches, the step is done. The result will be one of the three possible outcomes.

- No matching function were found. The compiler moves to the next step in the sequence.
- A single matching function was found. The Function is considered to be the best match.
- More than one matching function was found. The function call is ambiguous and the compiler will generate an error.

If the compiler reaches the end of the entire sequence without finding a match, It will generate a compiler error that no matching overloaded function can be found for the function call.

## Argument matching sequence
Step 1: Exact match. This happens in two phase.
        First: The compiler looks for a function that exactly matches the argument type(s) in the function call. If it finds one, it is considered the best match and the search stops.(like `int` type arguement to an `int` type parameter)
        Second: The compiler may apply `trivial` conversion to the argument in the function call.
        `Trivial` conversion are set of specific conversion rule that will modify type(without modifying the values) for the purpose of matching overloaded function. These include: `const` and `volatile` qualifiers, `signed` and `unsigned` qualifiers, const to non-const type.

**Note**: Match made via trivial conversion are considered to be an exact match.

Step 2: If no exact match is found, the compiler tries to apply numeric promotion to the argument(s). Ex. from char to int, int to double, etc.
Step 3: If no match is found via numeric promotion the compiler tries to find match via numeric conversion. Ex. from int to char, double to int, char to double.
Step 4: If no match is found via numeric conversion, the compiler tries to find match via user-defined conversion. Ex. from user-defined type to another user-defined type.

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
Step 5: If no match is found via user-defined conversion, the compiler will look for matching function that use ellipsis.
Step 6: If no match is found by this point, the compiler give us an error.

## Ambigious match

**Ambigious match** occurs with overloaded function. It occurs when the comiler find two or more function that can be made to match in the same step. When an ambigious match is encountered the compiler gives us an error stating it has found an ambigious function call.

**[Example of numeric conversion from Long to int or long to double](practice/ambiguous_function_call.cpp)**

## Ways for resolving ambigous matches
1. The best way is to simply define a new overloaded function that takes parameter the type you are trying to call the function with. 
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