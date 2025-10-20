#include<iostream>

using namespace std;

void FindHiLo(double x, double y, double & hi, double & lo);

int main()
{
    double x, y, hi, lo;

    cout << "\nPlease enter a number that does in fact exist please I still have trama from last time\nNumber: ";
    cin >> x;

    cout << "Number part 2: ";
    cin >> y;

    FindHiLo(x, y, hi, lo);

    cout << "\nThe highest of your two real numbers for once thank you is: " << hi;
    cout << "\nTe low is {a number} with the numerical value of x when x is equal to any real number, specifically the number of the lower one that you typed in which is in fact a value and that value is: " << lo << "\n";

    return 0;
}

void FindHiLo(double x, double y, double & hi, double & lo)
{
    if(x > y)
    {
        hi = x;
        lo = y;
    }
    else
    {
        hi = y;
        lo = x;
    }
}