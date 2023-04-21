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