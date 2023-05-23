# Halts

A `halt` is a flow control statement that terminates the program. In C++, halts are implemented as functions(rather than keywords). so our halt statement is a function call.


Note: When a program exit normally, The main function implicitly calls the `std::exit()` function.

The Term `normal termination` means the program has exited in an expected way. Note that the term `normal termination` does not imply anything about whether the program was successful or not. A program can exit normally even if it failed to complete its task.

`std::exit()` performs the following tasks:
1. Objects with static storage duration are destroyed in reverse order of construction.
1. Miscellaneous file cleanup is performed
1. Control is returned back to the OS.


### Calling std::exit() explicityly
Although `std::exit()` function is implicitly called when the `main` function ends, `std::exit()` can also be called explicitly. It live in the `cstdlib` header.


Note: statement after std::exit() are never executed. As std::exit() specifies the termination of the program.

Note: Calling `std::exit()` explicitly does not clean up any local variables(either in the current function, or in function up the call stack). Becuase of this, it is not recommended to call `std::exit()` explicitly.

## std::atexit()

Note: When we call `std::exit()` explicitly, we need to do some cleanup work manually. We can create a function that performs the cleanup work. But then we need to call it before every `std::exit()` call. This is not a good solution.

To assit with this, C++ offers the `std::atexit()` function, which allows us to speicfy a function that will automatically be called on program termination via `std::eixt()`.

[Here is a program demonstrating cleanup, std::exit() and std::atexit().](atexit.cpp)

### When should we use a halt?

 Almost never, as halts do not clean up memory or perform any other cleanup tasks. Halts should be avoided in all cases.