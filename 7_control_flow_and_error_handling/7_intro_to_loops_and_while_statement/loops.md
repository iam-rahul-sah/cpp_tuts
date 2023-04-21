# Loops

Loops are control flow statements that allow a piece of ocde to execute prepeatedly until some condition is met. Loops are very useful when we want to execute a piece of code multiple times.

## While loop statement

The `while statement` is the simplest of the three loops types that C++ provides and it has a definition very similar to that of an `if statement`:

**Syntax**
```
while (condition)
{
    statement;
}
```

A `while statement` is declared using the `while` keyword, followed by a `condition in parentheses`, followed by `statement` to be executed. When the while statement is executed, the condition is evaluated. If the condition is true, the statement is executed. Once the statement has finished executing, the control returns to the top of the while statment*(unlike if statement where the control proceed after the execution of the statement in the if block)* and the process is repeated until the condition is false.

[while simple example](while_example.cpp)

**Note**: That if the condition initially evalutates to false, the associated statement is never executed.

**Example**
```dotnetcli
int num{10};
while(num < 10)
{
    std::cout << num << '\n'; // this will never be executed
}
```

### Infinite while loop

Note: If the expression alwasy evaluates to true, the while loop will execute forever. This is called an infinite loop. 

**Example**
```
int num{1};
while(num > 10)
{
    std::cout << num << '\n'; // this loop will run infinetly as value of num never change
}
```
### Intentional infinite loop

Most of the time an infinite loop is not intentional, but sometimes you may want to execute few command infinetly. for e.g. (The main game loop inside a game)

**Example**
```

while(true)
{
    // do certain actions infinetly
}
```

### Loops variables
A loop variable(often called a counter) is an integer that is used to count how many times a loop has executed. Alwasyu use 'real' variable name, such as count, or a name taht gives more details about what you're counting(e.g. userCount).

### Loops variables should be signed
A loop variables should almost always be signed, an unsigned integer can lead to unexpected issues.
[Unsigned integer problem](unsigned_int_count_variable_problem.cpp)

### Doing somethinig every N iterations

Each time a loop executes, it is called and **iteration**.

Note: Often, we want to do something every 2nd, 3rd or 4th iteration , such as print a newline. This can easily be done by using the `modulus operator(%)`.

**Example**
```
int count{1};
while(count < 10)
{
    std::cout << count << ' ';

    if(count % 3 == 0)
    {
        std::cout << '\n';
    }
    count++;
}
```
[Example](practice_problems/print_a_to_z.cpp)
### Nested while loop

It is also possible to nest loops inside of other loops. This is called a nested loop. The inner loop will execute completely for each iteration of the outer loop.

[Program printing a to z using while loop](practice_problems\print_a_to_z.cpp)
### Nested loop example
1. [number triangle](practice_problems\number_pyramid.cpp)
1. [Upside down number triangle](practice_problems\upside_down_number_pyramid.cpp)
1. [right angle triangle](practice_problems\right_angle_triangle.cpp)
1. [right angle triangle with hash](practice_problems/right_angle_triangle_with_hash.cpp)