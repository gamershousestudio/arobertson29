#include<iostream>

using namespace std;

int main()
{
    int model;

    // Main loop
    cout << "\nHello, welcome to The Horse and Buggy Auto Comapny\n";
    cout << "Please check your model number to see if you are valid for a refund\n\n";

    do
    {
        cout << "Please enter your model number(0 to exit): ";
        cin >> model;
        // Checks if model is defective
        if(model == 119 || model == 179 || model == 221 || model == 780) // Defective model numbers
        {
            cout << "\nYou have a bad model!  Please come in store to get a full refund.\n\n";
        }

        else if(189 <= model && model <= 195)
        {
            cout << "\nYou have a bad model!  Please come in store to get a full refund.\n\n";
        }
        
        else if(model == 0)
        {
            cout << "Thank you, exiting program...\n";
        }
        else
        {
            cout << "\nYour car is OK\n\n";
        }
    }while(model != 0);

    return 0;
}