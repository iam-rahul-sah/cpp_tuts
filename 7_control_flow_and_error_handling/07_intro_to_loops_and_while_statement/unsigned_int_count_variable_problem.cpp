#include<iostream>

int main()
{
    unsigned int num{10};
    while (num >= 0)   // This loop will run forever 
    {
        std::cout << num << '\n';
        --num;     // as the value reaches 0 and is decrements the value of num is
                // is wraped around and return to MAX_VALUE of int.
    }
    
    return 0;
}