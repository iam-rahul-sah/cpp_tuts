#include <iostream>

int main()
{
    int count{1};
    // while (count < 11)
    // {
    //     std::cout << count << '\n';
    //     if (count == 5)
    //     {
    //         continue;
    //     }

    //     ++count;  // this statement is never executed after count == 5
    // }   // When the continue statement is executed the pointer jumps to the end of block

    // we can do something like this
    while (count < 11)
    {
        std::cout << count << '\n';
        ++count;
        if (count == 5)
        {
            continue;
        }
        
    }
    return 0;
    
}