#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// What the compiler does
template<>
int max<int>(int x,int y)
{
    return (x > y) ? x : y;
}
int main()
{
    std::cout << max<int>(8,9)<< '\n';   // creating a function instance by pasing actual data type
    std::cout << max(20,25) << '\n';     // compiler auto deduces the data type of variable and make a function instance of that type.
    std::cout << max<double>(5,7) << '\n';   // the argument in this function are implicitly converted to double data type.
    std::cout << max<>('a', 'b') << '\n';
    std::cout << max(true, false) << '\n';
    return 0;
}