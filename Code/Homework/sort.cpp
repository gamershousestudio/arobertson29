/*
Create a function that take an array of 100 random values from 0-1000 and sorts them using an insertion sort. You will output the unsorted array first and 
then output the sorted one. Here is the pseudocode for the insertion sort:

for i ← 1 to length(A)

     j ← i

    while j > 0 and A[j-1] > A[j]

          swap A[j] and A[j-1]

          j ← j - 1

     end while

end for
*/

#include <iostream>

using namespace std;

void Insertion(int a[]);

void Swap(int & a, int & b);

const int length = 100;
const int range = 1000;

int main()
{
     srand(time(NULL));

     int array[length];

     cout << "\nUnsorted array: \n";

     for(int i = 0; i < length; i++)
     {
          array[i] = rand() % range;
          cout << " [" << array[i] << "] ";
     }

     Insertion(array);

     cout << "\nSorted array: \n";

     for(int i = 0; i < length; i++)
     {
          cout << " [" << array[i] << "] ";
     }

     cout << "\n\n";

     return 0;
}

void Insertion(int a[])
{
     bool changed = 1;

     while(changed == 1)
     {
          changed = 0;

          for(int i = 0; i < length; i++)
          {
               int j = i;

               while(j > 0 && a[j - 1] > a[j])
               {
                    changed = 1;

                    Swap(a[j], a[j - 1]);

                    j--;
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