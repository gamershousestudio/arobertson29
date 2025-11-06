#include <iostream>

using namespace std;

int main() 
{
    srand(time(NULL));
    
    int size = 100;
    int range = 10000;
    
    int numbers[10000];
    
    int max;
    int min;
    
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
    
    cout << "\n\nThe maximum number is " << numbers[max] << ".\n";
    cout << "The minimum number is " << numbers[min] << ".\n";
    
    return 0;
}
