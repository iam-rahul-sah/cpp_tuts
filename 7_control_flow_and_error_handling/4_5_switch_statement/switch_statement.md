# Switch Statment Basic

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