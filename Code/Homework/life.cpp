/* COMMENTING GUIDE

Comment right before line of code is for that region until the next instance
Comment before an empty line before a line of code is for the whole area until the next instance
Comment on the same line as code is specific to just that line
Comment outside of a function summerizes the role of that function

*/

#include<iostream>

using namespace std;

// Global variables
const int xMax = 10; // x = row
const int yMax = 10; // y = col

const string sprites[] = {"⬜️", "⬛️"};

// Function pprototypes
int GetNeighbors(bool a[][yMax], int cords[]);

// Main loop
int main()
{
    // Game Variables
    bool game[xMax][yMax];
    bool nextFrame[xMax][yMax];

    return 0;
}

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
    if(nearby[0] && nearby[2] && ) active++; // Topleft
    if(nearby[1] && nearby[2] && ) active++; // Topright
    if(nearby[0] && nearby[3] && ) active++; // Bottomleft
    if(nearby[1] && nearby[3] && ) active++; // Bottomright
}