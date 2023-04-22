# Best Practice

## Control Statement and Error handling

### `Switch` statement
- *Prefer `switch statement` over `if-else` statement when there is a choice*  
- *Place the `default` case last in the `switch statement`*
- *Each set of statement underneath a label should end in a `break` statement or a `return` statement. This include the statement underneath the last label in the switch.*
- *Use the `[[fallthrough]]` attribute(along with a null statement) to indicate that fallthrough is intentional*
- *If defining variables used in a case statement, do so in a block inside the case statement*

### `Goto` statement
- *Aviod using `goto` statement*


### `Loops` statement(while loop)
**While loop**
- Favour `while(true)` for intentional infinite loops.
- Loop varaibles should be of type (signed) `int` only.

**do While loop**
- Favours `do while` loops over `while` loops when the loop body must be executed at least once.
- favour `while` loops over `do while` when given equal choice.

**for loop**
- Avoid using `operator!=` when doing numeric comparisons in `for loop` condition.
- Defining multiple variables(in the init-statement) and using the comma operator(in the end-expression) is acceptable in `for loop`.


**Break and continue**
- Use `break` and `continue` when they simplify your loop logic.
- User `early return` when they simplify your loop logic.

**Halts(Early exit)**
- Only use a halt if there is no safe way to return normally from the main function. If you haven't disabled exceptions, prefer using exceptions for handling errors safely.


**Introduction to testing our code**
- Write your program in small, well defined units(function or classes), compile often, and test your code as you go.

**Code coverage**
- Aim for 100% branch coverage of your code.
- Use the 0,1,2 test to ensure your loops works correctly with different numbers of iterations.
- Test different categories of input values to make sure your unit handles them properly.

**Narrowing conversion**
- Avoid narrowing conversions whenever possible. If you do need to perform one, use static_cast to make it an explicit conversion.


**Explicit type conversion**
- Avoid using C-style casts.
- Favour `static_cast` when you need to convert a value from one type to another type.

**Typedefs and type aliases**
- Name your type aliases starting with a capital letter and do not use a suffix(unless you have a specific reason to do otherwise).
- Prefer type aliases over typedefs.
- Use type aliases judiciously, when they provide a clear benefit to code readability or code maintenance.


**Type deduction**
- Use type deduction for your variables, unless you need to commit to a specific type.

**Type deduction for functions**
- Favour explicit return types over function return type deduction for normal functions.