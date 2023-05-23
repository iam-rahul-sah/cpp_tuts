#include <iostream>
#include <cstdlib>

void cleanUp()
{
    std::cout << "Did all the cleanup, hurray!\n";
}
int main()
{
    // registering cleanUp() with std::exit() to be called automatically in case of explicit std::exit()
    std::atexit(cleanUp);   // cleanup is not a function call, instead it is a function pointer

    std::cout << 1 << '\n';
    std::exit(0);             // explicit std::exit with status code 0

    // This statment nefver executes
    std::cout << 2 << '\n';
    return 0;
}