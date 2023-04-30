#include<iostream>

// add function with integer parameters
int add(int x, int y)
{
    return x + y;
}

// add function with double parameters
double add(double x, double y)
{
    return x + y;
}

int main()
{
    // The compiler is able to differentiate a function call based on
    // the type of argument
    std::cout << add(8,10) << '\n';  // all int parameter call to add(int, int)
    std::cout << add(7.2, 3.5) << '\n';  // all double parameter call to add(int, int)

    std::cout << add(10,7.2) << '\n';  // here the compiler is not able to determine which function to call
                                        // and hence gives an error.

    return 0;
}