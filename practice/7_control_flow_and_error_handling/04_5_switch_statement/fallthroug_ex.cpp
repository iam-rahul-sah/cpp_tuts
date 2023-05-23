#include<iostream>

int main()
{
    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
    case 2:
        std::cout << 2 << '\n';
    case 3:
        std::cout << 3 << '\n';
    case 4:
        std::cout << 4 << '\n';
    default:
        std::cout << 5 << '\n';
    }

    return 0;
}