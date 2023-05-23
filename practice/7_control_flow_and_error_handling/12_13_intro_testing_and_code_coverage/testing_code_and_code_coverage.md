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