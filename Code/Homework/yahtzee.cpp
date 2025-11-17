#include <iostream>

using namespace std;

// Function prototypes
bool Yahtzee(int a[]);
bool Four(int a[]);
bool Three(int a[]);
bool SmallStraight(int a[]);
bool LargeStraight(int a[]);

int Chance(int a[]);

void Insertion(int a[]);

void Swap(int & a, int & b);

int Round(int c0, int c1, int c2, int c3, int c4);

// Constants
const string sides[] = {"⚀", "⚁", "⚂", "⚃", "⚄", "⚅"}; // Unicode for each side
const int rounds;
const int limit;

// Init function
int main()
{
    srand(time(NULL));

    // Variables
    int score = 0;

    int yahtzee;
    int four;
    int three;
    int small;
    int large;
    int chance;

    // Welcome text
    cout << "\nWelcome to Yahtzee(not sponsored)!\n\n";
    
    // Game loop
    for(int i = 0; i < rounds; i++)
    {
        cout << "Round " << (i + 1) << ": \n\n";
        score += Round();
    }

    cout << "Your total score is " << score << "\n\n";

    return 0;
}

bool Yahtzee(int a[])
{
    // Checks if the minimum and maximum is the same(also means that values between the two are the same)
    if(a[0] == a[4])return 1;

    return 0;
}

bool Four(int a[])
{
    // Checks if the first and fourth(or second and fifth) is the same(also means that values between the two are the same)
    if(a[0] == a[3] || a[1] == a[4]) return 1;

    return 0;
}

bool Three(int a[])
{
    // Checks if the first and third(or second and fourth; third and fifth) is the same(also means that values between the two are the same)
    if(a[0] == a[2] || a[1] == a[3] || a[2] == a[4]) return 1;

    return 0;
}

bool SmallStraight(int a[])
{
    // Checks if numbers are sequential
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;

    for(int i = 0; i < 5; i++)
    {
        if(a[i] == 0) c0++;
        else if(a[i] == 1) c1++;
        else if(a[i] == 2) c2++;
        else if(a[i] == 3) c3++;
        else if(a[i] == 4) c4++;
        else if(a[i] == 5) c5++;
    }

    if(c0 > 0 && c1 > 0 && c2 > 0 && c3 > 0) return 1;
    else if(c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0) return 1;
    else if(c2 > 0 && c3 > 0 && c4 > 0 && c5 > 0) return 1;

    return 0;
}

bool LargeStraight(int a[])
{
    // Checks if all numbers are sequential
    if(a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) return 1;
    else if(a[0] == 2 && a[1] == 3 && a[2] == 4 && a[3] == 5 && a[4] == 6) return 1;

    return 0;
}

int Chance(int a[])
{
    int s = 0;

    // Adds the total of each value
    for(int i = 0; i < 5; i++)
    {
        s += a[i] + 1;
    }    

    return s;
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


void Swap(int & a, int & b)
{
    // Swaps two vales
    int c = a;
    a = b;
    b = c;
}

int Round()
{
    // Variables
    int dice[5];

    int score = 0;

    // Randomizes values
    cout << "You rolled:\n";
    
    for(int i = 0; i < 5; i++)
    {
        dice[i] = rand() % 6;
        cout << sides[dice[i]] << " ";
    }

    cout << "\n\nThe sorted values are:\n";
    Insertion(dice);

    for(int i = 0; i < 5; i++)
    {
        cout << sides[dice[i]] << " ";
    }

    cout << "\n\nYou got a ";

    // Finds what the user got
    if(Yahtzee(dice))
    {
        score = 50;
        cout << "YAHTZEE!\n\n";
    }
    else if(LargeStraight(dice))
    {
        score = 40;
        cout << "Large Straight!\n\n";
    }
    else if(SmallStraight(dice))
    {
        score = 30;
        cout << "Small Straight!\n\n";
    }
    else if(Four(dice))
    {
        score = Chance(dice);
        cout << "Four of a Kind!\n\n";
    }
    else if(Three(dice))
    {
        score = Chance(dice);
        cout << "Three of a Kind!\n\n";
    }
    else
    {
        score = Chance(dice);
        cout << "Chance!\n\n";
    }

    cout << "Your round score is " << score << "\n\n";

    return 0;
}