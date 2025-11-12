/* NOTES

Types: bubble, selection, insertion

O notation:
 - signifies speed & complexity of algorithm
 - Bubble: O(n^2)
 - Selection: O(n^2)
 - Insertion O(n)
 

*/

void Bubble(int a[]);

void Swap(int & a, int & b);

const int length = 1000;
const int range = 1000;

#include <iostream>

using namespace std;

int main()
{   
    srand(time(NULL));

    int array[length];

    cout << "\nUnsorted array: \n";

    for(int i = 0; i < length; i++)
    {
        array[i] = rand() % range;
        cout << " [ " << array[i] << " ] ";
    }

    Bubble(array);

    cout << "\nSorted array: \n";

    for(int i = 0; i < length; i++)
    {
        cout << " [ " << array[i] << " ] ";
    }

    cout << "\n\n";

    return 0;
}

void Bubble(int a[])
{
    bool changed = 1;

    while(changed)
    {
        changed = false;

        for(int i = 0; i < length - 1; i++)
        {
            if(a[i] > a[i + 1])
            {
                Swap(a[i], a[i + 1]);

                changed = true;
            }
        }
    }
}

void Swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
}