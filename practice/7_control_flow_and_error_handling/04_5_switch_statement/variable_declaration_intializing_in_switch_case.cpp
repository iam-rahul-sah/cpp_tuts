#include<iostream>

int main()
{
    // Defining and assigning inside a switch block
    switch (1)
    {
        int a; // Defining a variable is okay
        // int a{4};  // not okay initialization is not allowed
    case 1:
        int y; // Definition is allowed within a case, bad practice
        y = 4; // okay: assignment is allowed
        break;
    
    case 2:
        // int z{5}; // Initialization is disallowed
        y = 5; // okay
        break;
    
    // In case if we still want to initialize a variable we can do something like this
    case 3:
    {
        int z{5};
        break;
    }
    default:
        break;
    }
    return 0;
}