#include <iostream>

double add(int x, double y)
{
    return x + y;
}
double add(double x, int y)
{
    return x + y;
}
int main()
{
    std::cout << add(5,2.4) << '\n';
    std::cout << add(8.7,5) << '\n';
    return 0;
}