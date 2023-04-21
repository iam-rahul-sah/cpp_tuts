#include<iostream>

int main()
{
    int num{1};
    while (num < 51)
    {
        
        if (num < 10)
        {
            std::cout << 0 ;
        }
        std::cout << num << ' ';
        if (num % 10 == 0)
        {
            std::cout << '\n';
        }
        ++num;
        
    }

    return 0;
    
}