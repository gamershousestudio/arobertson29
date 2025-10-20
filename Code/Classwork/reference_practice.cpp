#include<iostream>

using namespace std;

void swap(int a, int b);

int main()
{
    int x, y;

    cout << "\nEnter your first number: ";
    cin >> x;

    cout << "\nEnter your second number: ";
    cin >> y;



    cout << "\nThe first number is now " << x << "\n";
    cout << "The second number is now " << y << "\n";

    return 0;
}

void swap(int & a, int & b)
{
    int c = a;

    a = b;
    b = c;
}