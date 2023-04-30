# include <iostream>

void print(std::string string)
{
}
void print(char ch=' ')
{
}
int main()
{
    print("Hello, world");        // resolves to print(string)
    print('a');                  // resolves to print(char)
    print();                    // resolve to print(char)
    return 0;
}