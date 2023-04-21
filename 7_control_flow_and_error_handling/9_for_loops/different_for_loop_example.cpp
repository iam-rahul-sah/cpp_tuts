#include <iostream>

int main()
{
    // for loop with decrementing loop variable
    std::cout << "For loop decrementing variable by 1" << '\n';
    for(int i = 10; i > 0; --i)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // for loop with different operation of loop variable
    std::cout << "For loop incrementing variable by 2" << '\n';
    for (int i = 0; i < 10; i += 2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << "For loop divinding loop variable by 10" << '\n';
    
    for (int i = 500; i > 0; i /= 10)
    {
        std::cout << i << ' ';
    }
    
    
    return 0;
}