#include<iostream>

// Function to check if a given char is vowel or not using OR operator
bool isVowelUsingComparing(char c)
{
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool isVowelUsingSwitchAndFallthrough(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}

void printResult1(char c)
{
    if (isVowelUsingComparing(c))
    {
        std::cout << c << " is a vowel." << '\n';
    }
    else
    {
        std::cout << c << " is not a vowel." << '\n';
    }
}
void printResult2(char c)
{
    if (isVowelUsingSwitchAndFallthrough(c))
    {
        std::cout << c << " is a vowel." << '\n';
    }
    else
    {
        std::cout << c << " is not a vowel." << '\n';
    }
}
int main()
{
    std::cout << "Enter a character: ";
    char userChar{};
    std::cin >> userChar;

    printResult1(userChar);
    printResult2(userChar);
    return 0;
}