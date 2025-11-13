#include <iostream>

using namespace std;

// Function prototypes
bool Yahtzee(int a[]);
bool Four(int a[]);
bool Three(int a[]);
bool SmallStraight(int a[]);
bool LargeStraight(int a[]);

void Chance(int a[]);

void Insertion(int a[]);

void Swap(int & a, int & b);

// Constants
const string sides[] = {"⚀", "⚁", "⚂", "⚃", "⚄", "⚅"}; // Unicode for each side

// Init function
int main()
{
    srand(time(NULL));

    // Variables
    int dice[5];

    // Welcome text
    cout << "\nWelcome to Yahtzee(not sponsored)!\n\n";
    
    // Main game loop
    Chance(dice);

    cout << "You rolled:\n";

    for(int i = 0; i < 5; i++)
    {
        cout << sides[dice[i]] << " ";
    }

    cout << "\n\nThe sorted values are:\n";
    Insertion(dice);

    for(int i = 0; i < 5; i++)
    {
        cout << sides[dice[i]] << " ";
    }

    cout << "\n\nYou got a ";

    return 0;
}

bool Yahtzee(int a[])
{
    // Checks if the minimum and maximum is the same(also means that values between the two are the same)
    if(a[0] == a[4])
    {
        return 1;
    }
}

bool Four(int a[])
{
    // Checks if the first and fourth is the same(also means that values between the two are the same)
    if(a[0] == a[3])
    {
        return 1;
    }
}

bool Three(int a[])
{
    // Checks if the first and third is the same(also means that values between the two are the same)
    if(a[0] == a[2])
    {
        return 1;
    }
}

bool SmallStraight(int a[])
{
    // Checks if one is added to each number in the sequence
    for(int i = a[0]; i < )
}

bool LargeStraight(int a[])
{

}

bool FullHouse(int a[])
{

}

// Randomizes values
void Chance(int a[])
{
    for(int i = 0; i < 5; i++)
    {
        a[i] = rand() % 6;
    }
}

// Sorting via insertion
void Insertion(int a[])
{
    // Loops through all values
    for(int i = 0; i < 5; i++)
    {
        int j = i;

        // Moves the value closer to the front as long as it is less then the one before it
        while(j > 0 && a[j - 1] > a[j])
        {
            Swap(a[j], a[j - 1]);

            j--;
        }
    }
}

// Swaps two vales
void Swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
}
