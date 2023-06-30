# C++ basics

## Statements
A statement is a ftype of instruction that causes the program to perform some actions. A statement is analogoues to a sentence in a language.

**__Type of statement in C++__**
1. Declaration statement
1. Jump statement
1. Expression statements
1. Compound statements
1. Selection statement(conditionals)
1. Iteration statment(loops)
1. Try blocks

**Function:** A function is a collection of statements taht executes sequentially.

**Syntax Error:** A syntax error is a compiler error at compile-time when your program violates the grammer rule of C++ language.
**Rule:** Every C++ program must have a special function named **"main"**. When the program runs, the statments inside of the main are executed in sequential orders.

**Note:** cout stands for character output. In C++ statements often ends with a semicolon(;).


## Comments.
A comments is a programmer-readable note that is inserted directly into the source code comments are ignored by the compiler and are for programmer's use only.

**Types of comments:**
- Single line comment
    - The '//' symbols begins a C++ single-line comment, which tells the compiler to ignore everthing from the // symbol to the endo of line.

```cpp
// Example if short comment

std::cout << "Hello world";            // aligned using
std::cout << "rahul";                  // tabs and spaces

// if long comments

// place long comments above the statmens
std::cout << "A very very long statment";

**Note:** Typically a single-line comment is used to make a quick comment about a single-line of code.

- Multi-line comment
    - The (/*) and (*/) pair of symbol denotes a C-styole multi-line comment. Everyting in betwween the symbol is ignored.

```cpp
// Example
/* This is a multi-line comment
 * the matching asterisks to the 
 * left can making these easier to read
 */
```
**Warning:** Don't use multi-line commetns inside other multi-line commetns wrapping a single-line comment inside a multi-line is okay.

e.g. /*  This is outer comment /* this is inner comment */. The compiler see's the closing tag for inner commdent and rest of the sentences is considered a statment by C++ and gives a compilerr warning */.


### What-How-Why(Proper use of comments):
Typically comments should be use for libarary, function or program.
1. "What" a library, program or function does. Typically placed at the top of the file or library.
    - e.g. // The program calculates the student's final grade
    - // This functin adds two number
2. "How" the code is going to accomplish its goal. Typically placed within library, program and function
    - e.g. // To generate a random item, we're going to do the following:
    - // Put all of the items on a list.
    - // Calculate the probability of each item
    - // Choose a random no.
    - // choose which item random no. corresponds to
    - // Return the appropriate item.
3. At statment level, comments whould be used to describe "Why" the code is doing something.
    - e.g. Why is sight = 0?
    - // This player just drank a potion of blindness and can not see anything
    - proving a comment like // sight is assgined 0, explains "What" is happening.
    - Programmers often have to make a tough decision between solving a problem one way or another way comments are good way to remind yourself the reason you made one decision instead of another
    - e.g. // we decided to use a linked list instead of an
    - // array because array do inserting too slowly.

**Best practice:** Comment your code liberally, and write your comment as if speaking to some who has no idea what the code does. Don't assume you remember why you made a specific choices.

**Commenting out code:** converting one or more line of code into a comment is called "commenting out your code".

**Reasons for commenting out code:**
1. Commenting out piece of code that is giving errors.
1. Comenting out broken code, so that we an run the program and fix the problem later.
1. Debugging to find source of error.
1. To replace old code with new code, still kepping the old code(commented out) for various reasons.

## Objects and variables.
- **Data:** Data is any information that can be moved, processed or stored by a computer.
- **Program:** Program is a collection of instructioin that manipulate data to produce a desired result.
- **Object:** An object is a region of storage that has a value and other associated properties

**Note:** Ojects can be named or unnamed. A named object is called a "variable" and the name of the object is called an "identifier"

**Variable instantiation:**
- In order to create a variable, we use a special kind of declaration statement called **"definition"**.
- "Instantiation" means that the object will create and assigned a memory address.

**Defining mulitple variable:**
```cpp
int a;            // valid, and should be prefered
int b;

// equivalent to 
int a, b;        // valid, but should be avoided

int a, int b;    // invalid
int a, double b; // invalid

int a;
double b;        // valid
```

**Best practice:** Althought the lanaguage alows to define multiple variable in a single statement it is not recommended.

## Variable assignement and initialization

**Assignment:** After a variable has been defined, we can give a value afterward. This process is called as **"assignment"**.

**Initialization:** Assignment require atleast two statement, when these two stemps are combined i.e. when a variable is defined, you can also provide an initial value at the same time. This is called "initialization".

**Intializer:** The value used to initialize is called an "initializer".

**Type of assignement**
- There is only one way of assigning a value to a variable. i.e. using assignment("=") operator it is called "copy assignment". "=" copy values from RHS to LHS of the operator.

**Warning:** "=" is an assignment operator and not equality operator. Thus it is used to assign value from one object to another object. Whereas "==" is used as equality opoerator.

**Type of initialization:**
1. Default initialization:(`int a;`)
    - When no initial value is given, this is called default initialization. In most case, default initialization leaves a variable with undefined value.
2. Copy initialization:(`int a = 5;`)
    - Copy value from RHS of "=" operator to LHS to the variable. "Copy initialization" is not used in modern code.
3. Direct initializaion:(`int a(10);`)
    - When a value is provided inside parentheses, this is called direct initialization.
4. Brace/unfiorm/list initialization(`int a{20};`)
    - the modern way to initialize object in C++ is to use a from of initialization that make use of curly braces.

**Note:** Both copy initialization and direct initialization are not used much in modern C++ expect for one case. Instead brace initialization is used the most.

**Note:** Brace initializationi disallows "narrowing conversion".
```cpp
int x{3.7};           // this will give an error
int y(3.7);
int z = 3.7          // rest of the two initialization will drop the floating point digits and initliaze the variable
```

**Best practice:** Favour brace initialization whenever pssible

**Value initialization & Zero initialization:** When a variable is initialized with empty braces "value initialization" takes place. In most case, value initialization will initialize the variable to zero(or empty based on type of variable). In  such case when zeroing occurs, this is called "Zero initialization".

**Q. When should i initialize with {0} vs {}?**  
- Use an explicit initializing, when we are actually using the value "0".
```cpp
// e.g. 
int {0};
std::cout << x;
```
- Use value initialization, if the value is temporary
```cpp
// e.g. 
int x{};
std::cin >> x;
```

**Best practice:** Always initialize your variable.

**Multiple initialization:**
```cpp
// multiple initialization all three cases
int a = 5, b = 6;  // copy initialization
int c(7), d(8);    // direct initialization
int e{9}, f{10};   // brace initialization

int a, b = 5;  // wrong, "a" left uninitialized
```

### Unused initalized variable and `[[maybe_unused]]`
If "treat warning as error" is enaabled compiler will generate error if we define a variable and don't use it.
```cpp
// e.g.
int main()
{
    int x{5};               // initialized but unused variable
    return 0;
}
// the compiler will give warning, which will then be treated as error
```    

- From C++17, `[[maybe_unused]]` is used to tell the compiler to expect the varrable may not be used, so it will no give an warnings.
```cpp
// e.g.
int main()
{
    [[maybe_unused]] int x{3};
    return 0;                         // this program will compiler without any warning.
}
```

##  Iostream, cout, cin and endl
1.`std::cout`: We used `std::cout`, along with the insertion operator `(<<)`, to send text to the console to be printed.
- Data flow during text output:
    - `Data is given to the program(e.g. inserted by the programmer)` --> `cout` --> `console`

- To print more than one thing on the same line, the insertion operator `(<<)` can be used to concatenate multiple pieces of output. This is called chainging output.
```cpp
std::cout << "Hello" << "World";
```

2. `std::endl`: When output with std:cout, std::endl prints a newline character to the console endl stands for "end line"

**Best practice:** Output a newline whenever a line of output is complete.

### std::endl vs '\n'
- `std::end` is a bit inefficient as it acutally does two things
    1. It move the cursor to the next line of the console and
    1. It make sure that any canched output shows up on the screen immediately(this is called "flushing" the output), std::cout often flushes the output any way so it redundant.
- On the other hand '\n' just print a newline and it can also be emvedded directly into sentences.

**Best practice:** Prefer '\n' over std::endl when outputting text to the console.

**Warning:** '\n' uses a backslash, not a forward slash. Using a forward slash instead may reuslt in undefined behaviour.

3. `std::cin`: cin stands for character input. It reads input from keyboard using an extraction operator(>>).
    - Data flow in cin `user` --> `console` --> `program`

**Note:** We don;t need to use '\n' when accepting input, as the user will need to press the enter key to have their inputed accepted.
**Note:** It is possible to accept multiple inputs in a single statement using multiple`(>>)` operator.

## Uninitialized variable and undefined behaviour
A variable that has not been given a known varlue usually thorugh initialization or assignement is called an uninitialized variables.

**Warning:** Some compiler, such  a visual studio, will initialize the content of memory to some preset value when your're uisng a debug build configuration. This will not happen when using a release build configuration. 

**Note:** "Undefined behaviour(UB)" is the result of executing code whose behaviour is not well defined by the C++ language.

### Symptoms of code implementing UB.
1. Different result every time it runs.
2. Consistently producing some incorrect error.
3. Sometimes produces correct result, sometimes not.
4. Seems like it working but produces incorrec reuslt later in the program.
5. Program crash, immediately or later
6. Works on some compiler and not on ther
7. Program works until you change some other seemingly unrelated code.

**Rule:** Take care to avoid all situation that result in undefined behaviour, such as uninitialized variables.

## Keyword and naming identifiers
**Keyword:** C++ reserves a set of 92 words(as of C++20). These reserved words are called keyword.

**Note:** C++ also defines special identifiers: override, final, import and module. These have a specific meaning when used in certain context but are not reserved.

**Identifier:** The name of a variable(or function, type or other kind of item) is called an identifier.

**Identifier naming rule:**  
- The identifier cannot be a keyword
- The identifier can only be composed on letter, number and the underscore character
    - (a-z, A-Z,0-9, _) Allowed
    - ($, #, -, /) Not allowed
- The identifer must begin with a letter or an underscore. It cannot start with a number.
- C++ is case sensitive, VIP and vip are different.

**Best practice for naming variables:**
1. In C++ the variable name should begin with a lowercase letter. If the variable name is one word, all lowercase is expected.
2. Function name also start with a lower case letter(e.g. main)
3. If identifier is multi-word, there are two common convention, snake_case(underscore), camelCase(intercapped). Pefer "camelCase"

**Best practice:** When working in an existing program, use the convention of that program(even if they don't conform to modern best practice). Use modern best practice when your are writing new programs.

**Note:** You should avoid naming your identifier starting with an underscore, as they are typically reserved for OS, library, and/or compiler use.

**Note:** Identifier name should be clear about what the value they are holding means.

**Rule:** 
- An identifier with a trival use can have a short name(e.g. such as i). 
- An identifier that is more broadly(e.g. a function that is called from many different places in a program), should have a longer and more descriptive name(e.g. instead of open, use opneFileOnDisk).
- Avoid abgrevaitons(as they are hard to read).
- A comment could helop to keep the length of variable managable. e.g. `numberOfChar`  // no. of char with whitespace and punctuations.

## Whitespace and basic formatting
"Whitespace" is a term that refers to characters that are used for formatting purpose. In C++ this refer primarily to spaces, tabs and newlines. C++ compiler generally ignore whitespaces, except when processing text literals. C++ is a white space independent language.

**Note:** Newline are not allowed in quoted text.

```cpp
std::cout        <<     "Hello world";
std::cout <<            "hello world";
std::cout
<<     "Hello world"
// all the above statments are the same.

std::cout << "hello          world";
std::cout << "helloworld"

// both of the above statment are not same.

std::cout << "Hello 
                world";  // newline not allowed in quoted text, error.
```

**Basic formatting guidelines:**
1. Use 4 spaces for text formatting
2. Two accepted style for function braces:
    - By goolge
```cpp
int main(){
}
// reason - It is unnecessary to waste ra whole line just for the sake of formatting.
``` 
    - By author
```cpp
int main()
{
}
// reason - Braces are aligned and it is easy to read.
```     
3. Each statment within curly braces should start one tab in from the opening braces of the function it belongs to.
4. 80 character is the maximum length a line. If a line is going to be longer, it should be split into mulitple lines, by aligning it with the line above.
5. If a long line is split with an operator(e.g.<< or + ), that ooperator should be placed at the beginning of the next line, not at the end of current line.
```cpp
// e.g. 
std::cout << 3 + 4
           + 5 + 6
           * 7 * 8;
```
6. Use whitespace to make your code easier to read by aligning value or comments or adding spaces between blocks of code
```cpp
// e.g.
cost = 57;  // cost of one notebook
pricePerItem = 24;

// use intead
cost            = 57;        // cost of one notebook
pricePerItem    = 24;

// Autoformatting VS 2022
// Edit > advanced > format document
// Edit > advanced > format selection
```
**Best practice:** Your lines should be no longer than 80 character in length.

## Introduction to literals and operators.
**Litera:** A "literal"(also known as a literal constant) is a fixed value that has been inserted directly into the source code.  

**Operators:** An "operation" is a mathematical calculation involving zero or more input value(called "operands") that produces a new value called as output value. The specific operation to be perfromed is denoted by a symbol called as "operator".
- In C++, the output value of an opoeration is often called an return value
- It is common to represent an operator, by adding an operato suffix to the symbol. e.g. `operator+`, `operatr>>`.

#### Operator's arity
The number of operands that an operato takes is called the operatos's arity.
- Unary - one operand(e.g. negation -)
- Binary - two operand(e.g. +,-,*)
- Ternary - three operand(e.g. only one in C++ `?:`)
- Nullary - act on no operand(e.g. only one in C++ `throw operator`)

**Chaining operator:** Operator can be chained togethere such that the output of one operator can be used as the input for otherr operator.

#### Return vaue and side effects.
- Most operator in C++ just use their operands to calculate and return value(e.g. 2 + 3  // Just returns a value of 5)
- Few operator to not produce return values(e.g. delter and throw)
- Some operator have additional behaviours.
    - An operator that has some observable effect beyond producing a return value is said to have a "side effect"
    - e.g. `x = 5` this operation has a side-effect of assigning the value of 5 to x. It is observable(e.g. by printing value of x)
    - e.e. `std::cout << "Hello world` this operation also has a side effect of printing text to the console and it is observable even after the statment has executed.
- For the operator that we call primarily for their return value(e.g. +), it's usually obvious what their return value will be.
    - e.g. 5 + 7 + 3 * 2   // retuns 18
- For the operators that we call primarily for their side effect(e.g. =, <<), it's not always obvious what return value they produce.
    - e.g. x = y = 5;
    - here the return vlaue of the expression (y = 5) is Lvalue
    - whereas the return value of the expression (x = y) is Rvalue.
    - e.g. std::cout << "hello" << "world";
    - evaluating the expression from LHS, here std::cout is return first so taht it could print "world" to the screen.

## Introduction to expression
An `"expression"` is a combination of literals, variables, and function calls that calculates a single value. The process of executing an expression is called `"evaluating"` and the single value produced is called the `"result"` of the expression.

- ex. 2, "hello world", x, 2+3, five() all these are examples of expression.

- literal evaluates to their own value
- Variable evaluates to the value of variable.

**Note:** Expression do not end with semi-colon, and cannot be compile by themselves.

**Expression statement**
It is an expression followed by a semicolon.
e.g.
- x = 5, is just an expression and cannot be compiled
- x = 5; is an expression statment and can be compiled

**Useless expression statment**  
2 + 3;  // useless statment, as the value is calculated and discarded.

## Flowchart, Pseudocode and algorithm
**Flowchar:** A flowchar is simply a graphical representation of steps. It shows steps in sequential order and is widely used to presenting the flow of algorithm, workflow or process.

**Flowchar symbol**  
![Flow char symbol](/images/flowchart.png)

**Algorithm:** It's an organized logical sequence of the actions or the approach towards a particular problem. Algorithms are expressed using natural verbal but somewhat technical annotation

**Pseudocode:** It's simply an implementation of an algorithm in the form of annotations and informative text written in plain english. It has no syntax like any of the programming language and thus can't be compiled or interpreted by the computer.

**Example:** Algorithm, flowchart and psuedocode ot print all natural numbers up to n.

**Algorithm:**
1. Start
1. get value of n from the user
1. initialize i = 1
1. if(i <= n) go to step 5 else go to step 8.
1. print i value
1. increment i value by 1
1. go to step 4
1. stop


**Flowchart:**  
![flowchar printing natural number till n](/images/flowchart_print_till_n.png)

**Pseudocode:** 
```
This program will print aall the natural numbers till n(user input)
{
    in the main function
    
    Take the number from the user
        while counter is less than or equal to number
            print the value of counter
            Add on to the counter
        Else
            end the program
}
```

## Developing your first program
**Best practice:** New programmers often try to write an entire program all at once, and then get overwhelmed when it produces a lot of errors. A better startegy is to add one piece at a time, make sure it compiler and test it. Then when you're sure it's working move on to the next piece.

**Example:** 
- Prgram to print double of a number
    1. start
    1. Ask user to enter a number
    1. Declare varaible n to store the number
    1. Read n from the user

For step six there are 3 pssible solution.

- Not-good solution
    5. Multiply n by 2 and assign it back to n(n = n * 2)
    6. Display n
    7. Stop
**Why is this a bad solution:** In this solution the user input is reassigned another value and the original input is lost and we are unable to use it for other solution.

- Mostly-good solution
    5. Delcare variable doubleNum to stor the double of number
    6. Initialize doubleNum = num * 2
    7. Display doubleNum
    8. Stop
**Why is this not the best solution:** Here we are using a n additional variable, which is not the best solution.

- Preferd solution
    5. display num * 2
    6. stop
**Why is this the best solution:** Here we are not overwritting the user input neither we are usign another variable to store the value.