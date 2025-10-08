#include <iostream>

using namespace std;

int MilesToFeet(int miles); // <- prototype

int main()
{
    int m;

    cout << "\nHow many miles?\n";
    cin >> m;

    cout << endl << MilesToFeet(m) << endl << endl; // <- function call

    return 0;
}

int MilesToFeet(int miles) // <- signature
{
    return miles * 5280; // <- definition
}