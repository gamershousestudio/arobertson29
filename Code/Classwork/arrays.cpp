/* NOTES

Arrays
 - stores multiple values
 - only one value type(unlike python)
 - "used to contain multiple pieces of data of a specific type"
 - type name [ size ] = value -- Declaring arrays
 - accessed using name[ index ]
 - index starts at 0 ALWAYS

Ways of initializing
 - {1, 153, 97, 13468, 23} -- hard coding
 - 

Passing into functions
 - void example(int score, int a[]); // Do not need to declare size

*/

#include<iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    const int num_of_students = 18;
    int f_grades[num_of_students]; // I am eleven

    int pass = 0;
    int fail = 0;

    cout << "\nWelcome to RandomGrades!\n\n";


    for(int i = 0; i < num_of_students; i++)
    {
        f_grades[i] = rand() % 101;
        cout << "Student " << i + 1 << "'s grade for this quarter is " << f_grades[i] << "\n\n";
        
        if(f_grades[i] >= 70)
        {
            pass++;
        }
        else
        {
            fail++;
        }
    }

    cout << "The number of students who passed C++ is " << pass << ".\n";
    cout << "The number of students who passed C++ is " << fail << ".\n\n";

    return 0;
}