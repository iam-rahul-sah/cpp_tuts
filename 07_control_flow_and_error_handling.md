# Control flow and error handlind

## Switch Statment Basic

### Why use switch statement

Chaining many if-else statement together is possible but this is both difficult and inefficient it is inefficient as it will evaluate the condition for each if-else statement.  

Whereas Switch statement will only evaluate the condition once and check the cases based on the evaluated condition.  

[Check Out here](E:\CPP_Tuts\7_control_flow_and_error_handling\4_switch_statement_basic\main.cpp)

The Idea behind a Switch statement is siple: A expression is evaluated to produce a value. If the expressions's values is equale to value after any case labels, the statement after the matching case label is executed. If no matching case label is found, the statement after the default label is executed.

### Switch statement breakdown

#### Starting a switch statement
- A switch statement starts with a `switch` keyword. Followed by parenthesis `()` which contains the condition for evulation. `switch (condition)`. The condition can be a single variable or a expression.
- Note: The condition of the switch statement must be of integral data type(int, char, true, false, etc). It cannot be a floating point data type(float, double, etc).

#### Case labels
- The label that follows the switch statement is the case label. The case label is a keyword `case` followed by a constant expression. The constant expression must match the type of codition or must be convertible to the type of condition.
- If the value in condition expression match the value in the case label. The statement inside the case label will be executed.
- We can have any number of case label. All case label in a switch statement must be unique.


#### Default label
- Default label is another kind of lable in a switch statement. it is declared using the keyword `default`. The default label is executed if none of the case label matches the condition.
- Default label is optional
- We can only have one default statement per switch statment.
- By convention, defualt case is placed last in the switch statment.


If the value of the expression does not match with any case label and no default label is present, the switch statement will end without executing any statement.

#### Break Vs Return

A return statement when executed will return the control to the calling function. The calling function will then continue executing from the next statement after the function call. i.e. it will exit the function.

Whereas when we use break statement it will exit the switch statement. The control will then be passed to the next statement after the switch statement.

*A break statement should be used in a switch statement after every case label. If we do not use a break statement, the control will fall through to the next case label. This is called fall through.*

## Switch falltrough and scoping
### Fallthrough

When a switch expression matches a case label or optional default label, execution begins at the first statement following the matching labe. Execution will then continue sequentially until one of the following termination conditions happens:
1. The end of the switch statement is reached.
1. It encounter a `break` or a `return` statement.
1. Something else interrupts the flow of control.(OS shut down, etc)

Note: The consequent case labels is not one of the termination conditions. Thus, without a `break` or `return` statement, execution will continue to the next case label.

[5_fallthrough_and_scoping > main.cpp](E:\CPP_Tuts\7_control_flow_and_error_handling\5_switch_fallthrough_and_scoping\main.cpp)

> When execution flows from a statement underneath a label inot statments underneath a subsequent label, this is called **fallthrough**


Since fallthrough is rarely desired, many compiler flag this as warning. To help address this warning, C++17 adds a new attribute `[[fallthrough]]` to indicate that fallthrough is intentional. 

### What are attributes?
Attributes are a modern C++ feature that allows the programmer to provide the compiler with some addtional data about the code.

Note: The [[fallthrough]] attribute modifies a null statement to indicate that fallthrough is intentional. The null statement is the semicolon that terminates a case label.

Example
```
case 1:
    do_something();
    [[fallthrough]];
```

An example of intentional fallthough for optimization is in 5_fallthrough_and_scoping > main2.cpp.


### Switch case scoping

With if statements, we can only have an single statement after the if-condition, and that statement is considered to be implicitly inside a block.
Whereas with switch statements, the statements after labels are all scoped to the switch block. No implicit blocks are created.

**Example**
```dotnetcli
if(condition)
    statement1;
    statement2;

here the statement1 implicitly inside a block and statement2 is not a part of the if condition.
if(condition)
{
    statement1;
}
statement2;

Whereas for switch case it does not create a implicit block.

case 1:
    statement1;
    statement2;
    statement3;
    break;

All the statements after the case label are scoped to the switch statement.

```

### Variable declaration and initialization in switch case

We can declare or define(but not initialize.) variables in a switch case, both before and after the case labels. However, we cannot declare or define variables in the middle of a case label.

Initializing a variable before and inside a case is not allowed. As if the case is not executed, the variable will never be initialized. We can only initialize a variable inside the last case(default) label. 

**Example**
```
switch (1)
{
    int a; // okay: definition is allowed before the case labels
    int b{ 5 }; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        int z{ 4 }; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:
        break;
}
```

All statements inside the switch are considered to be part of the same scope. Thus, a variable defined in one case can be used in another case.

Though if we need to initalize a variable inside a block we can do so by using a block.

**Example**
```
switch (1)
{
    case 1:
    { // note addition of explicit block here
        int x{ 4 }; // okay, variables can be initialized inside a block inside a case
        std::cout << x;
        break;
    }
    default:
        std::cout << "default case\n";
        break;
}
```
## Goto statement(Unconditional jump)

An uncoditional jump is a jump that is not dependent on any condition. In other words, it is a jump that is always executed. 

In C++, unconditional jumps are implemented via a **goto** statement, and the sport to jump is specified by a statement label.

[Unconditional jump example](goto_example.cpp)


## Statement labels have function scope

Statement labels have a third kind of scope: function scope, which means that they are visible througout the function even before the its point of declaration. The **goto statement** and its corresponding **statement label** must be in the same function.

**Syntax**

```
void some_function()
{
    statement_label:
        statement 1;
    goto statement_label; // This will loop forever
}
```
Note: Goto statement can jump both backward and forwared inside a function.

Note: statement label should always be associated with a statement. If you want to jump to a statement that is not associated with a statement label, you can use a **null statement**.



### Limitations of Jump statements

1. We can only jump within the bound of a single function.
1. We can't jump forward over a variable declaration/initialization.

Note: We can jump backward over a variable declaration/initialization. and the variable will be reinitialized when teh initializtion statement is reached.

## Avoid using goto statement

### Problems with goto statement
1. It allows a programmer to jump aournd the code arbitrarily. This creates a spaghetti code. Spaghetti code is a code that has a path of execuation that is hard to follow.
1. 
1. # Loops

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


# Do while loop

A `do while` statement is a looping construct that works just like a while loop, execpt that the statement always executes at least once. After the statement has be executed, the `do-while` check the condition in the while statement. If the condition is true, the statement is executed again. This process continues until the condition is false.


**Syntax**
```
do
{
    // statements
}while(condition);
```

[**Example** of a problem solved using `do-while` loop](do_while_loop.cpp)

# For Loops statement

The `for loop` is the most widely utilized looping statement when we have an obivious loop variable(i.e. when we know how many times we want to loop) as it let us easily and consicely define, initialize, test and change the value of loop variable.

As of `C++11`, there are two different kinds of `for loop` statements:
1. Classic `for loop`
1. `Range-based for loop`


**Syntax**
```
for(init-statement; condition; end-expression)
{
    statement;
}
```

**An equivalent `while loop`**
```
{  // note the whole while loop should be encolsed inside a block so that the loop variable is not visible outside the loop.
    init-statement;   // used to define varaiables used inside the loop
    while(condition)
    {
        statement;
        end-expression;   // used to update the loop variable prior to rechecking of the codition
    }
}

```

**Step of evaluation of a for loop**
A `for loop` evaluate in three steps
1. The `init-statement` is executed. Used to initalize the varaible used in the loop. This is executed only once at the start of the loop
1. The `condition` is evaluated. If the condition is true, the loop body is executed. If the condition is false, the loop terminates.
1. The `end-expression` is executed. This is used to update the loop variable prior to rechecking of the condition. This is executed at the end of each iteration of the loop. After evaluation the execution returns to second step.


**More for loop examples**
1. [Function to calculate integer exponentiation.](for_loop_integer_exponentiation.cpp)
1. [for loop with different operation on loop variable](different_for_loop_example.cpp)


### The perils of `operato!=` in `for loop` condition.

**Example**
We wish to print number from 1 to 9. We can do this using two condition
1. `i < 10`
1. `i != 10`

In the first case the loop will terimate if the value is anything greater than 10. But in case of the second case, the loop will only terminate if the value of `i` is 10 any other value will cause the loop to continue.(for e.g. `if(i == 9){i++;}` will cause the loop to continue forever)

### Off by one error
`off by one` error occurs when the loop iterates (+1) or (-1) than the required steps to produce the desired result.

Suppose we want to print from 1 to 5 and we intialized `int i =1` and we use the condition `i < 5` this produces the result of
`1 2 3 4` which is one step less than the required steps.

Note: This kind of error mostly occurs due to using wrong relation operator

### ommitted expressions in `for loop`

**Equivalent `while loop` using `for loop` with omitted expressions**
```
int i = 0;
for(;condition;)
{
    statement;
    end-expression;
}
```

**Note**: Ommiting all the expression in the for loop will result in an infinite loop.
**Example**
```
for(;;)
{
    statement;
}
Note when the condition in the for loop is omitted, the value of condition is evaluated as true.
```

### Multiple expressions in `for loop`

Usually `for loops` iterate over only one variable. But the programmer can define multiple variables in the init-statement and make use of the `comma operator` to change the value of multiple variable in the end-expression. We can also use logical operator to combine multiple conditions.

**Example**
```
#include<iostrem>

int main()
{
    for(int x{0}, y{0}; x < 10 && y < 10; x++, y++)
    {
        std::cout << x << ' ' << y << '\n'; 
    }
}
```

Note: This is the only place in C++ where defining multiple variable in a single statement is allowed.


### Nested `for loop`
`for loops` can be nested inside other loops.


**Practice**
1. [print number from 0 to 20](practice/print_number_from_0_to_20.cpp)
1. [sum to all natural number till n](practice/sum_of_natural_number.cpp)

# Break and continue

## Break
The `break statement` causes a `while loop`, `do-while loop`, `for loop` or `switch statement` to end, with execution continuing with the next statement after the loop or switch being broken out of.

### Breaking a switch statement
A `break` is typically used at the end of each case to signify the case is finished(which prevents fallthrough into subsequent cases).

### Breaking a loop
In context of a loop, a break statement can be used to end the loop early. Execution continues with the next statement after the end of the loop.

Note: Break is also a common way to get out of an intentional infinite loop.

**Example**
```
while(true)
{
    std::cout << "Enter 0 to exit or any other key to continue: ";
    int num{}
    std::cin >> num;

    if(num == 0)
    {
        break;   // This break statement break out of the loop and execution starts at the next statement after the loop.
    }

    std::cout << "We're out!\n";
}
```

### Break vs return 
A `break statement` terminates the switch or loop, and execution continues at the first statement beyond the switch or loop. A `return statement` terminates the entire function, and execution continues at the point where the function was called. A return statement are usually used to return a value from a function to the caller.

[Break and continue example](break_and_continue.cpp)

### Continue
The `continue statement` provides a convenient way to end the current iteration of a loop without termination the entire loop.( i.e. it is used to skip one iteration if a certain condition is met, and continue with the next iteration).

Note: `continue statement` when executed it jump to the bottom of the current loop, which is okay as the end-expression in a for-loop is executed after the loop body. Whereas for a while loop if we use `continue` statement, we need to make sure that the end-expression is executed before the continue statement. our else our program will enter an infinite loop.

Therefore, inside a while loop we should execute all the statements that are required to be executed before the continue statement.

[**Example while loop enterning infinite loop becuase of continue statement**](while_continue_infinite_loop.cpp)

### The debate over use of break and continue
When use judiciously, `break` and `continue` can make code more readable and maintainable. But when used excessively, they can make code difficult to understand and maintain.

### Debate over use of early return
A return statement that is not the last statement in a function is called an `early return`. Early returns should only be used when they simplifies the logic of code. Early returns can make code more readable and maintainable.

# Halts

A `halt` is a flow control statement that terminates the program. In C++, halts are implemented as functions(rather than keywords). so our halt statement is a function call.


Note: When a program exit normally, The main function implicitly calls the `std::exit()` function.

The Term `normal termination` means the program has exited in an expected way. Note that the term `normal termination` does not imply anything about whether the program was successful or not. A program can exit normally even if it failed to complete its task.

`std::exit()` performs the following tasks:
1. Objects with static storage duration are destroyed in reverse order of construction.
1. Miscellaneous file cleanup is performed
1. Control is returned back to the OS.


### Calling std::exit() explicityly
Although `std::exit()` function is implicitly called when the `main` function ends, `std::exit()` can also be called explicitly. It live in the `cstdlib` header.


Note: statement after std::exit() are never executed. As std::exit() specifies the termination of the program.

Note: Calling `std::exit()` explicitly does not clean up any local variables(either in the current function, or in function up the call stack). Becuase of this, it is not recommended to call `std::exit()` explicitly.

## std::atexit()

Note: When we call `std::exit()` explicitly, we need to do some cleanup work manually. We can create a function that performs the cleanup work. But then we need to call it before every `std::exit()` call. This is not a good solution.

To assit with this, C++ offers the `std::atexit()` function, which allows us to speicfy a function that will automatically be called on program termination via `std::eixt()`.

[Here is a program demonstrating cleanup, std::exit() and std::atexit().](atexit.cpp)

### When should we use a halt?

 Almost never, as halts do not clean up memory or perform any other cleanup tasks. Halts should be avoided in all cases.

# Introduction to Testing your Code

**Software testing** is the process of determining whether or not software actually works as expected.

## Test you program in small pieces
We should write small function(or classes), and then compiling and testing them immediately. That way, if we make a mistake, we will only need to debug a small piece of code. That has been changed since the last time. 

Testing a small part of code in isolation to ensure that 'unit' of code is correct is called **unit testing**. Each unit test is designed to ensure that a particular behaviour of the unit is correct.

## How to test your code(Informal testing)
One way we can test code is to do informal testing as we write the program. After writing a unit of code(a function, a class, etc), we can write some code to test the unit that was just added, and then erase then test once the test passes.
```cpp
// So here's our temporary tests to validate it works
    std::cout << isLowerVowel('a'); // temporary test code, should produce 1
    std::cout << isLowerVowel('q'); // temporary test code, should produce 0
```
## Preserving your test
The function that were generated for informal testing can be preserved so that if we want we can test that same code again later.(If we changed anything and we want to check if the earlier code still works as expected). To preserve the test case, we can create another function and all test inside of it.
**Example**
```cpp
// Not called from anywhere right now
// But here if you want to retest things later
void testVowel()
{
    std::cout << isLowerVowel('a'); // temporary test code, should produce 1
    std::cout << isLowerVowel('q'); // temporary test code, should produce 0
}
```

## Automating our test function

One problem still hold, that after running these test function we need to manually test the output. We can write a test function that contains both the tests AND the expected answer and compares them so we don't have to.

```cpp
int testVowel()
{
    if (!isLowerVowel('a')) return 1;
    if (isLowerVowel('q')) return 2;

    return 0;
}
```

## Integrating testing
Once each of our units has been tested in isolation, they can be integrated into our program and retested to make sure they were integrated properly. This is called **integration testing**.

[An example of program with automated test function](practice/testing.cpp)

## Code Coverage
The term **Code coverage** is used to describe how much of the source code(statment, branch, etc) of a program is executed while testing using a test case. 

### Statment coverage
The term statement coverage refers to the percentage of statements in a program that have been executed during testing.

**For example** for a function like
```cpp
int foo(int x, int y)
{
    int z{ y };
    if (x > y)
    {
        z = x;
    }
    return z;
}
```
calling a function like `foo(1, 0)` will give a complete statement coverage. 

for the `isLowerVowel()` function from the previous example, we require two call to test all of the statements, as ther is no way to reach statemtn 2 and 3 in the same function call.

## Branch coverage
Branch coverage refers to the percentage of branches that have been executed, each possible branch counted separately. An `if statement     has two branches. A `switch statement` has one branch for each `case` label, and one branch for the `default` label.

Note: The previous call to foo(1,0) gave us 100% statement coverage and exercised the use case where `x>y`, but that only gives us 50% branch coverage. We need one more call, to foo(0,1), to test the use case where the if statement does not execute.

In the `isLowerVowel()` two calls to the function(i.e. `isLowerVowel('a')` and `isLowerVowel('q')`) will give us 100% branch coverage. As there are only two branch one for lowerVowel and another for other alphabets.

for example and if-else if-else block would require three calls to test all branches.

## Loop coverage
Loop coverage(informally called the 0,1,2 test) says that if you have a loop in your code, you should ensure it workd properly when it iterates 0 times, 1 time, and 2 times. This is because most bugs in loops occur in one of these three cases.

Note: if a loop works correctly for 2-iteration case, it should work correclty for all iteration greater then 2.

## Testing different categories of input

A function that is written to take input of some type. Should be test against all possible input of that type. For example, a function that takes an integer as input should be tested against positive, negative, and zero values(i.e. categories of values).

### Some basic guidelines for category testing:
For integers: Negative values, zero, positive values, and the special case of 1 and -1.
For Floating point: Negative values, zero, positive values.
For String: Empty string(just a null terminator), normal valid string, string that have whitespace, string that are all whitespace.
For pointer: Test nullptr, and valid pointer.