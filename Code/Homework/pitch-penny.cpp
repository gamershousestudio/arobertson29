#include<iostream>
#include<iomanip>

using namespace std;

// Global variables
const int r = 5;
const int c = 5;

const string sprites[] = {"⬜️", "🟥", "🧩", "🎮", "🎾", "🌇", "🎎"};
const string prizes[] = {"a puzzle", "a game", "a ball", "a poster", "a doll"};

const int amountOfPrizes = 5;

const int chances = 3;
const int coins = 10;

// Function prototypes
void Output(int arr[][c]);

// Main init function
int main()
{
    srand(time(NULL));

    // Variables
    int random[2];

    int a[r][c];

    int count[amountOfPrizes]; 

    int won[chances];
    int prizeCount = 0;

    cout << "\n\n";

    // Sets every value in the array to zero
    for(int x = 0; x < r; x++) for(int y = 0; y < c; y++) a[x][y] = 0;
    for(int i = 0; i < amountOfPrizes; i++) count[i] = 0;
    for(int i = 0; i < chances; i++) won[i] = 99;

    // Loops from the first prize(2) to the last prize
    for(int j = 2; j < (amountOfPrizes + 2); j++)
    {
        // Loops through for each chance and adds a new prize to the array
        for(int i = 0; i < chances; i++)
        {
            random[0] = rand() % r;
            random[1] = rand() % c;

            if(a[random[0]][random[1]] != 0)
            {
                i--;
            }
            else
            {
                a[random[0]][random[1]] = j;
            }
        }
    }

    Output(a);

    cout << "\nTossing " << coins << " coins...\n\n";

    // Places all coins
    for(int i = 0; i < coins; i++)
    {
        // Gets a random point to put the coin
        random[0] = rand() % r;
        random[1] = rand() % c;

        // Keeps track of what was landed on
        if(a[random[0]][random[1]] != 1) // 1 is index for coin(makes sure the coin didnt already land there)
        {
            count[a[random[0]][random[1]] - 2]++; // 2 is the amount of indexes before the first prize
        }

        // Places the coin
        a[random[0]][random[1]] = 1;
    }

    Output(a);

    // Checks if the user won each prize
    for(int i = 0; i < amountOfPrizes; i++)
    {
        if(count[i] == chances)
        {
            won[prizeCount] = i;
            prizeCount++;
        }
    }

    // Outputs what the user won
    cout << "\nYou won";

    if(prizeCount > 0)
    {
        for(int i = 0; i < prizeCount; i++)
        {
            if(won[i] == 99) continue;

            cout << " " << prizes[won[i]];

            if((i + 1) < prizeCount && prizeCount > 2) cout << ",";
            if((i + 2) == prizeCount) cout << " and"; 
        }

        cout << "!\n\n";
    }
    else
    {
        cout << " absolutely nothing...\n\n";
    }

    return 0;
}

void Output(int arr[][c])
{
    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            cout << setw(3) << sprites[arr[x][y]];
        }

        cout << "\n";
    }
}