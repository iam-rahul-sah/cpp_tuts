# Goto statement(Unconditional jump)

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