#include <iostream>

int breakOrReturn()
{
    while (true)
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char c{};
        std::cin >> c;
        if (c == 'b')
        {
            break;         // This break will exit the loop and execute the statement after the loop
                            // this won't return any value to the caller
        }

        if (c == 'r')
        {
            return 1; // The return will exit the whole function and return 1 to the caller.
        }   
    }
    // statment after the loop only break can execute the statement
    std::cout << "We broke out of the loop\n";

    return 0;
    
}
int main()
{
    int returnValue{breakOrReturn()};
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';
    return 0;
}