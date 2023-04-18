# Switch Statment Basic

### Why use switch statement

Chaining many if-else statement together is possible but this is both difficult and inefficient it is inefficient as it will evaluate the condition for each if-else statement.  

Whereas Switch statement will only evaluate the condition once and check the cases based on the evaluated condition.  

[Check Out here](E:\CPP_Tuts\7_control_flow_and_error_handling\4_switch_statement_basic\1_why_to_use_switch_statement\main.cpp)

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