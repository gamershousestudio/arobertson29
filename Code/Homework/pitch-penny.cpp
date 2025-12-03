#include<iostream>
#include<iomanip>

using namespace std;

// Global variables
const int r = 5;
const int c = 5;

const string sprites[] = {"⬜️", "🟥", "🧩", "🎮", "🎾", "🌇", "🎎"};

const int chances = 3;

// Function prototypes
void Output(int arr[][c]);

// Main init function
int main()
{
    srand(time(NULL));

    int a[r][c];

    cout << "\n\n";

    for(int x = 0; x < r; x++) for(int y = 0; y < c; y++) a[x][y] = 0;

    int random[2];

    for(int j = 2; j < 7; j++) // 4 = amount of prizes
    {
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

    cout << "\n";

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