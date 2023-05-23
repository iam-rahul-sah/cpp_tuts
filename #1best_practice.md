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


**Function overloading**
- Use function overloading to make your program simpler.

**Default arguments**
- If the function has a forward declaration(especially one in a header file), put the default argument there. Otherwise put the default argument in the function definition.

**Function template**
- Use a single capital letter(starting from T) to name your type template parameters(e.g. T, U, V, etc..)
- Favour the normal function call syntax when using function teemplates(i.e. use `max()`, instead of `max<int>()`)
- Template that are needed in mulitiple files should be defined in a header file, and then `#included` wherever needed. This allows the compiler to see full template definition and instantiate the function as needed.
- Feel free to use abbreviated function template with a single auto parameter, or where each auto parameter should be an independent type(when language standard is set to 20 or newer)

**Lvalue reference const**


**Pass by lvalue reference**
- Favour passing by const reference over passing by non-const unless you have a specific reason to do otherwise.(e.g. you need to modify the parameter)
- Pass fundamental types by value, and class (or struct) types by const reference.

**Pointer**
- When declaring a pointer type, place the astrisk next to the type name.
- Always initialize you pointer variables.
- Value initalize your pointer(to be null pointers) if you are not initializing them with the address of a valid object.
- Use 'nullptr' when we need a null pointer literal for initialization, assignment or passing a null pointer to a function.