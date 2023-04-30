#include <iostream>

// We can do something like this by chaning multiple if statement it gets
// overly complex as the we want to add more number.
// Also in if statement
void printDigitNameUsingIf(int x)
{
    if (x == 1)
    {
        std::cout << "One" << '\n';
    }
    else if (x == 2)
    {
        std::cout << "Two" << '\n';
    }
    else if (x == 3)
    {
        std::cout << "Three" << '\n';
    }
    else
    {
        std::cout << "Unknow" << '\n';
    }
}

// Instead we should use switch statement for testing a variable against a set
// of values
void printDigitNameUsingSwitch(int x)
{
    switch (x)
    {
    case 1:
        std::cout << "One" << '\n';
        break;
    case 2:
        std::cout << "Two" << '\n';
        break;
    case 3:
        std::cout << "Three" << '\n';
        break;
    case 4:
        std::cout << "Four" << '\n';
        break;
    default:
        std::cout << "Unknow" << '\n';
        break;
    }
}
int main()
{
    printDigitNameUsingIf(2);
    printDigitNameUsingSwitch(4);
}