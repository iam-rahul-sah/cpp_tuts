#include <iostream>
#include <cstdint>

std::int64_t pow(int base, int exponent)
{
    std::int64_t value{1};
    for (int i = 0; i < exponent; ++i)
    {
        value = base * value;
    }
    return value;
    
}
int main()
{
    std::cout << pow(7,2) << '\n';
    return 0;
}