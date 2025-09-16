#include<iostream>

using namespace std;

int main()
{
    // Ways to simulate random number generation
    srand(time(NULL)); // Tells the computer to geet a 'random' number(based on the internal clock)

    int random = rand(); // gives a random value

    // Modulus: finds the remander of a number
    // Ex.
    int remander = 5 % 2; // What is the remander of 5(int) / 2(int)
    cout << remander << "\n";

    // 50/50 random chance
    int yes_or_no = rand() % 2;
    bool true_or_false = bool(yes_or_no);

    // 33/33/33 random chance
    int yes_or_no_or_maybe = rand() % 3;

    int chance = rand() % 4; // 25 percent chance
    chance = rand() / 5; // 20 percent chance...

    return 0;
}