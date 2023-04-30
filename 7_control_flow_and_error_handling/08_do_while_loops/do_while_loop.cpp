// This program asks user for an input and loops until user has selected a valid option

#include <iostream>

int main()
{
    int selection{};
    do
    {
        std::cout << "Please make a selection: 1" << '\n';
        std::cout << "1) Addition" << '\n';
        std::cout << "2) Subraction" << '\n';
        std::cout << "3) Multiplication" << '\n';
        std::cout << "4) Division" << '\n';
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3 && selection != 4);

    std::cout << "You selected " << selection << " " << '\n';
    
    // The functionality can also be added using a while loop but that adds some new problems
    //example 1: Intialize the selection variable with a value that is not in the list
    // This adds the problem of magic number.

    int selection2{0};
    while (selection2 != 1 && selection2 != 2 && selection2 != 3 && selection2 != 4)
    {
        std::cout << "Please make a selection: 2" << '\n';
        std::cout << "1) Addition" << '\n';
        std::cout << "2) Subraction" << '\n';
        std::cout << "3) Multiplication" << '\n';
        std::cout << "4) Division" << '\n';
        std::cin >> selection2;
    }
    std::cout << "You selected " << selection2 << " " << '\n';
    // To avoid a magic number we can just another operator to check if the option selected is valid or not.
    // While this solves the problem of magic number but adds a new variable just to check the selected values

    int selection3{};
    bool invalid=true;

    while (invalid)
    {
        std::cout << "Please make a selection: 3" << '\n';
        std::cout << "1) Addition" << '\n';
        std::cout << "2) Subraction" << '\n';
        std::cout << "3) Multiplication" << '\n';
        std::cout << "4) Division" << '\n';
        std::cin >> selection3;

        if(selection3 == 1 || selection3 == 2 || selection3 == 3 || selection3 == 4)
        {
            invalid = false;
        }
    }
    std::cout << "You selected " << selection3 << " " << '\n';
    
    return 0;
}