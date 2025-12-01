/*

PSEUDOCODE:

In main
 - secret is randomly 
 generated
 - welcome text
 - In while
   - ran until number is guessed
   - user enters their guess
   - output GiveHint

In GiveHint
 - Tell user if number is too low, too high, or correct

COMPARISON:
In my psuedocode, I didn't write out any of the actual logic, just made the general idea for what
I needed the code to do.  This made the psuedocode writing process go by much quicker, but in
more advanced projects would make the code writing much harder because I would have to come up
with the logic for my code.  I treated the psuedocode more as a basic outline then an english
representation for my code.  While writing my code, I learned more about the psuedocode process
and why it is so important for more advanced programs like AIs.  It is also useful to map out the
logic, though I'm not sure I would use psuedocode exactly for that.

*/

#include<iostream>

using namespace std;

string GiveHint(int guess, int secret);

int main()
{
    srand(time(NULL));
    
    int secret = rand() % 100 + 1;
    int guess;
    
    cout << "\nWelcome to Guess the NumberTM\n"
    << "A random number between one and one hundred has been generated\n" // Apologies that these lines look weird, gdb is not being nice
    << "To start, please start by starting\n\n";

    do
    {
        cout << "guess: ";
        cin >> guess;
        
        cout << "\n" << GiveHint(guess, secret) << "\n\n";
        
    } while(guess != secret);
}

string GiveHint(int guess, int secret)
{
    if(guess > secret)
    {
        return "Guess too high, try again";   
    }
    else if(guess < secret)
    {
        return "Guess too low, try again";
    }
    else
    {
        return "Congrats!  You got it correct";
    }
}

