#include <iostream>

using namespace std;

int Max(int a[]);
int Min(int a[]);

const int size = 50; // VSCode doesnt like to recognize these as global :/
const int range = 10000;

int main() 
{
    srand(time(NULL));
    
    int numbers[size];
    
    int max = 0;
    int min = 0;
    
    for(int i = 0; i < size; i++)
    {
        numbers[i] = rand() % (range + 1);
        cout << "\n" << numbers[i];
        
        if(numbers[i] > numbers[max])
        {
            max = i;
        }
        else if(numbers[i] < numbers[min])
        {
            min = i;
        }
    }
    
    cout << "\n\nThe maximum number is " << numbers[Max(numbers)] << ".\n";
    cout << "The minimum number is " << numbers[Min(numbers)] << ".\n";
    
    return 0;
}

int Max(int a[])
{
    int max = 0;

    for(int i = 0; i < size; i++)
    {
        if(a[i] > a[max])
        {
            max = i;
        }
    }

    return max;
}

int Min(int a[])
{
    int min = 0;

    for(int i = 0; i < size; i++)
    {
        if(a[i] < a[min])
        {
            min = i;
        }
    }

    return min;
}