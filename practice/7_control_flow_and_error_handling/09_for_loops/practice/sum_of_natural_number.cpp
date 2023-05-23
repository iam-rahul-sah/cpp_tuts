#include <iostream>

int sumTo(int value)
{
    int total{0};
    for (int i{1}; i <= value; ++i)
    {
        total += i;
    }
    return total;
    
}
int main()
{
    int inputNum{};
    std::cout << "Enter a number: ";
    std::cin >> inputNum;
    std::cout << "The sum of natural numbers till " << inputNum << " is " << sumTo(inputNum) << '\n';
    return 0;
}