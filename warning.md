# Warnings

### Switch

Once the statement underneath a case or default label have started executing, they will overflow(fallthrough) into subsequent cases. `Break` and `return` statements are used to prevent this.

### Halt

The `std::exit` function does not clean up local variables in the current function or up the call stack.