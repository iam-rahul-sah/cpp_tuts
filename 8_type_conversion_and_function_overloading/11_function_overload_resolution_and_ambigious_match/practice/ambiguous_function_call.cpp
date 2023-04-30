// Program to demonstrate ambigioius function call due to two possible numeric conversion from long to int and long to double
# include <iostream>

void print(int x)
{
}

void print(double x)
{
}
int main()
{
    print(5L);
    // Note: A long cannot be promoted to a int therefore step 2 is not applicable over here
    // In step 3 that are two possible match eitther the function can resolve to print(int) or print(dobule) after numeric conversion.
    // This give an error.
    return 0;
}