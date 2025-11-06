#include<iostream>

using namespace std;

void Multiply(int array[], int m);

const int size = 10;

int main()
{
    int array[size];
    
    int range = 20;

    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % (range + 1);
        cout << "\n" << array[i];
    }

    int multiplier;

    cout << "\n\nWhat would you like your multiplier to be?\n";
    cin >> multiplier;

    cout << "\nThe new array is\n";
    Multiply(array, multiplier);
    
    for(int i = 0; i < size; i++)
    {
        cout << "\n" << array[i];
    }

    cout << "\n\n";

    return 0;
}

void Multiply(int array[], int m)
{
    for(int i = 0; i < size; i++)
    {
        array[i] *= m;
    }
}