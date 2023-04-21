#include<iostream>

int main()
{
    char c{'a'};
    int charToNum{};
    while (c <= 'z')
    {
        std::cout << c << " = " << (charToNum = c) << '\n';
        ++c;
    }
    return 0;
}