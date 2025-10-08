#include<iostream>
#include<iomanip>

using namespace std;

char GetLetter(double grade);

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

    cout << fixed << setprecision(3) << "\nThe average is " << avg << endl;

    cout << "The letter grade is " << GetLetter(avg) << "\n\n";

    return 0; 
}

char GetLetter(double grade)
{
    char letter = 0;

    // A = 89.5
    // B = 79.5
    // C = 70.5
    // D = 69.5
    // F = 

    if(grade >= 89.5)
    {
        letter = 'A';
    }
    else if(grade >= 79.5)
    {
        letter = 'B';
    }
    else if(grade >= 69.5)
    {
        letter = 'C';
    }
    else if(grade >= 70.5)
    {
        letter = 'D';
    }
    else
    {
        letter = 'F';
    }

    return letter;
}