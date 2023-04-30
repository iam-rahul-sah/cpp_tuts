#include <iostream>

int add(int x, int y)               // add function for adding int type integers
{
    return x + y;
}
double add(double x, double y)       // add function for adding double type integers
{
    return x + y;
}
int main()
{
    std::cout << add(5,9) << '\n';
    std::cout << add(5.5,9.7) << '\n';          // These function call are unambigious as we have exact overloaded function for these function calls.

    return 0;
}