#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// preserving test case in a function
void testVowel()
{
    std::cout << isLowerVowel('a') << '\n';
    std::cout << isLowerVowel('E') << '\n';
    // still we will need to manually check the result after the test
}

// automated testing
int automatedTestVowel()
{
    if (!isLowerVowel('a'))
    {
        return 1;
    }
    if (isLowerVowel('q'))
    {
        return 2;
    }
    return 0;

    // this function returns the number of test that failed, or 0 if all test passed.
    
}
int main()
{

    std::cout << automatedTestVowel();
    // Testing statement not preserved test cases
    // std::cout << isLowerVowel('a') << '\n';
    // std::cout << isLowerVowel('E') << '\n';
}