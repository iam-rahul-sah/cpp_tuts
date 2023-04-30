#include <iostream>
#include <cmath>

int main()
{
    // Backward goto jump
    {
        int num{};
    repeat: // statement label for the goto statement
        std::cout << "Enter a positive integer: ";
        std::cin >> num;

        if (num < 0)
        {
            goto repeat; // goto statement
        }
        std::cout << "The square root of " << num << " is " << std::sqrt(num) << '\n';
    }

    // Forward goto jump
    {
        bool skip{true};
        if (skip)
            goto end; // jump forward; statement label 'end' is visible here due to it having function scope

        std::cout << "cats\n";
    end:; // statement labels must be associated with a statement
    }

return 0;
}