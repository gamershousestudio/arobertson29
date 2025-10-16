#include<iostream>

using namespace std;

int Factorial(int base);

int main()
{
    int base;

    cout << "\n\nPlease enter your base: ";
    cin >> base;
    cout << "\nThe factorial of " << base << " is " << Factorial(base) << ".\n\n";

    return 0;
}

int Factorial(int base)
{
    if(base == 1)
    {
        return base;
    }
    else
    {
        return base * Factorial(base - 1);
    }
}