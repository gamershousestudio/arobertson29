#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    double avg;
    int numsAmount = 0;
    double numsAdded = 0;

    cout << "\nHello, welcome to grade calculator!\n\n";
    cout << "To start, please enter your grades.  Enter 101 to exit.\n";

    double input;
    
    while(input != 101)
    {
        cout << "\nPlease enter your grade:  ";
        cin >> input;
        
        if(input != 101)
        {
            numsAdded += input;
            numsAmount++;
        }
    }
    avg = numsAdded / numsAmount;

    cout << fixed << setprecision(3) << "\nThe average is " << avg << endl << endl;

    return 0; 
}