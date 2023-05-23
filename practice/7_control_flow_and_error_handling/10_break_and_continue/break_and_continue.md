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