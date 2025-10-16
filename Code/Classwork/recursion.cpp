/* NOTES   

What is recursion?
 - different way of problem solving
 - breaking down problems and building them back up
 - a function calls itself to solve a problem
 - breaks down a complx problem into smaller problems until a base case is reached
 - builds up once it hits base case
 - base case: the most elementary a problem can get

*/

#include<iostream>

using namespace std;

int Exponent(int base, int power);

int main()
{
    cout << "\n" << Exponent(7, 5) << "\n\n";

    return 0;
}

int Exponent(int base, int power)
{
    if(power == 1)
    {
        return base;
    }
    else
    {
        // Calls itself within the function
        return base * Exponent(base, power - 1);
    }
}