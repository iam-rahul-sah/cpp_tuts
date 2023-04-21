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