#include<iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    // Variables
    int slot0 = 0;
    int slot1 = 0;
    int slot2 = 0;

    int b0 = 0;
    int b1 = 0;
    int b2 = 0;

    int t0 = 0;
    int t1 = 0;
    int t2 = 0;

    int tokens = 100;

    // Introduction
    cout << "\nHello, welcome to GamblingIsFun LLC!\n";

    // Rules
    cout << "\nRules: \nYou have 100 tokens, and can spend 1 token to play.\n";
    cout << "If you roll all 1s, you get 4 tokens, 2s for 8, and 3s for 12\n";

    string spin;

    do
    {
        // User input
        cout << "\nYou have " << tokens << " tokens left.\nWould you like to spin(y/n): ";
        cin >> spin;
        
        // Gambling loop
        if(tolower(spin[0]) == 'y')
        {
            tokens--;

            // Generates random values
            slot0 = rand() % 3 + 1;
            slot1 = rand() % 3 + 1;
            slot2 = rand() % 3 + 1;

            b0 = (slot0 % 3) + 1;
            b1 = (slot1 % 3) + 1;
            b2 = (slot2 % 3) + 1;

            t0 = (slot0 + 1) % 3 + 1;
            t1 = (slot1 + 1) % 3 + 1;
            t2 = (slot2 + 1) % 3 + 1;

            // Prints slot values
            cout << "\n " << t0 << "   " << t1 << "   " << t2 << " ";
            cout << "\n[" << slot0 << "] [" << slot1 << "] [" << slot2 << "]\n";
            cout << " " << b0 << "   " << b1 << "   " << b2 << " \n";

            // Sees if all slot values are the same
            if(slot0 == slot1 && slot1 == slot2)
            {
                // Adds the slot value * 4 to tokens
                cout << "\nCongrats!\nYou won " << slot0 * 4 << " tokens!\n";

                tokens += slot0 * 4;
            }
        }
    }
    while(tolower(spin[0]) != 'n' && tokens > 0);

    // Exits the program
    if(tokens > 0) // Finds why/how the user exited
    {
        cout << "\nThank you for playing! \nYour total score is " << tokens << " tokens!\n\n";
    }
    else // Ran out of tokens
    {   
        cout << "\nYou failed! \nPlease try again. \nOr- don't I guess.\n\n";
    }

    return 0;
}