/* COMMENTING GUIDE

Comment right before line of code is for that region until the next instance
Comment before an empty line before a line of code is for the whole area until the next instance
Comment on the same line as code is specific to just that line
Comment outside of a function summerizes the role of that function

*/

//-----------------------------------------------------------------------------------------------------------
#pragma region Notes

/* REFERENCE GUIDE

For the sake of my bad memory, any commands and operators which we have not discussed in class and are
a part of the standard cpp library.  All explanations are based on my own research, and therefore may
be oversimplified/not fully accurate to what the command actually does.  I will redact "class" from this
list as it is simple and I had it as previous knowledge.

1) Bitwise & operator(appears as a &= b in this code; equivelent to a = a & b)
    Applies AND operator to each bit within a variable's allocated memory
    Ex. 1 & 1 = 1; 1001 & 1110 = 1000

2) Bitwise | operator
    Applies OR operator to each bit within a variable's allocated memory

3) Bitwise ~ operator
    Applies NOT operator to each bit within a variable's allocated memory

4) #pragma region & #pragma endregion
    Makes lines of code collapsable.  Am using here to help with organization

5) c_lflag
    Struct within termios containing terminal files

6) Idea behind EnableRawMode()
    Puts all bitmaps together; isolating values that need to be negated as equal to 1
    Negates those values so all other values are equal to 1 and they are 0
    For values that don't need to be negated, they stay the same(1 & 1 = 1; 1 & 0 = 0)
    For values that need to be negated, they are no matter original(0 & 1 = 0; 0 & 0 = 0)

7) 

*/

#pragma endregion
//-----------------------------------------------------------------------------------------------------------
#pragma region MouseInput

// Gets user mouse input
// A lot of this stuff is weird terminal sorcery, but I tried to explain this as best as possible

// Weird header stuff needed for this
#include<termios.h> // Used for editing terminal settings
#include<unistd.h> // Interperates mouse events

termios originalTermios; // Initializes termios

class MouseInput
{
    // Changes terminal settings to edit what signals we get
    void EnableRawMode()
    {
        // Gets termios ready for messing with
        tcgetattr(STDIN_FILENO, &originalTermios) // Saves current state of our termios instance

        termios raw = originalTermios; // Gives us a new termios to mess with

        // Edits settings within c_lflag (by disables I just mean disabling signals for it)
        raw.c_lflag &= ~(ECHO | ICANON | ISIG) // Disables character typing, delayed signals, and kill signals
        raw.c_lflag &= ~(IXON | ICRNL); // Disables terminal pausing
        raw.c_lflag &= ~(OPOST); // Disables autoformat

        // Updates console settings (sets active instance to our raw)
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw)
    }

    // Brings console back to original settings
    void DisableRawMode()
    {
        // Gets our original settings and brings them back
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios)
    }
}

#pragma endregion
//-----------------------------------------------------------------------------------------------------------
#pragma region Initialization

#include<iostream>

using namespace std;

// Global variables
const int xMax = 10; // x = row
const int yMax = 10; // y = col

const string sprites[] = {"⬜️", "⬛️"};

// Function prototypes
int GetNeighbors(bool a[][yMax], int cords[]);

#pragma endregion
//-----------------------------------------------------------------------------------------------------------

int main()
{
    // Game Variables
    bool game[xMax][yMax];
    bool nextFrame[xMax][yMax];

    return 0;
}

//-----------------------------------------------------------------------------------------------------------
#pragma region Functions

// Finds how many neighbors are near a given cell
int GetNeighbors(bool a[][yMax], int cords[])
{
    // Sees if cells around it go out of bounds

    bool nearby[4]; // List of if the nearby cells exist; left = 0; right = 1; top = 2; bottom = 3;
    for(int i = 0; i < 4; i++) nearby[i] = true; // Initializes nearby to minimize logic trees later on

    // Checks if cell is on leftmost
    if((cords[0] - 1) < 0) nearby[0] = true;

    // Checks if cell is on rightmost
    else if((cords[0] + 1) > xMax) nearby[1] = true;

    // Checks if cell is on topmost
    if((cords[1] - 1) < 0) nearby[2] = true;

    // Checks if cell is on bottom most
    else if((cords[1] + 1) > yMax) nearby[3] = true;

    // Checks values of all nearby cells(assuming they exist)

    int active = 0;

    // Linear
    if(nearby[0] && a[cords[0] - 1][cords[1]]) active++; // To the left
    if(nearby[1] && a[cords[0] + 1][cords[1]]) active++; // To the right
    if(nearby[2] && a[cords[0]][cords[1] - 1]) active++; // Above
    if(nearby[3] && a[cords[0]][cords[1] + 1]) active++; // Below

    // Diagonal
    if(nearby[0] && nearby[2] && ) active++; // Top left
    if(nearby[1] && nearby[2] && ) active++; // Top right
    if(nearby[0] && nearby[3] && ) active++; // Bottom left
    if(nearby[1] && nearby[3] && ) active++; // Bottom right
}

#pragma endregion