#pragma region Initialization

#include<iostream>

using namespace std;

// Global variables
const int xMax = 10; // x = row
const int yMax = 10; // y = col

const string sprites[] = {"⬜️", "⬛️"};

// Function prototypes
int GetNeighbors(bool a[][yMax], int cords[]);

void Output(bool a[][yMax]);

void OnClick(int x, int y, bool a[][yMax]);

#pragma endregion
//-----------------------------------------------------------------------------------------------------------

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
    Struct within termios containing terminal settings files

6) Idea behind EnableRawMode()
    Puts all bitmaps together; isolating values that need to be negated as equal to 1
    Negates those values so all other values are equal to 1 and they are 0
    For values that don't need to be negated, they stay the same(1 & 1 = 1; 1 & 0 = 0)
    For values that need to be negated, they are no matter original(0 & 1 = 0; 0 & 0 = 0)

7) cout.flush()
    Pretty much, things happen faster
    Pushes everything waiting to be cout-ed all at once(normally just saved in memory then cout-ed)

*/

#pragma endregion
//-----------------------------------------------------------------------------------------------------------
#pragma region MouseInput

// Info on click event
struct Input
{
    int row;
    int col;
};

// Gets user mouse input
// A lot of this stuff is weird terminal sorcery, but I tried to explain this as best as possible

// Weird header stuff needed for this
#include<termios.h> // Used for editing terminal settings
#include<unistd.h> // Interperates mouse events

#include<sstream> // Allows memory to be allocated for a seperate (essentially global) variable to save strings
#include<string> // Strings exist in this code

termios originalTermios; // Initializes termios

class MouseInput
{
    // Changes terminal settings to edit what signals we get
    void EnableRawMode()
    {
        // Gets termios ready for messing with
        tcgetattr(STDIN_FILENO, &originalTermios); // Saves current state of our termios instance

        termios raw = originalTermios; // Gives us a new termios to mess with

        // Edits settings within c_lflag (by disables I just mean disabling signals for it)
        raw.c_lflag &= ~(ECHO | ICANON | ISIG); // Disables character typing, delayed signals, and kill signals
        raw.c_lflag &= ~(IXON | ICRNL); // Disables terminal pausing
        raw.c_lflag &= ~(OPOST); // Disables autoformat

        // Updates console settings (sets active instance to our raw)
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    // Brings console back to original settings
    void DisableRawMode()
    {
        // Gets our original settings and brings them back
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
    }

    // Sends code mouse input signals
    void EnableMouse()
    {
        cout << "\x1b[?1000h"; // Send click events
        cout << "\x1b[?1006h"; // Make click events not impossible to read
        cout.flush();
    }

    // Reverts EnableMouse()
    void DisableMouse()
    {
        cout << "\x1b[?1000l"; // Stops sending click events
        cout << "\x1b[?1006l"; // Makes click events impossible to read
        cout.flush(); // I'm impatient; happen now
    }

    // Saves input
    void ParseMouseSequence(const string &seq, bool a[][yMax])
    {
        int button, col, row; // Info contained within the sequence

        char action, ignore;

        // Creates memory for seq
        stringstream ss(seq); // Saves seq to internal memory
        ss >> ignore >> ignore >> button; // Allocates the saved seq
        
        // Grabs col value
        ss.ignore(1, ';');
        ss >> col;

        // Grabs row value
        ss.ignore(1, ';');
        ss >> row;

        // Sees if it is a press(m) or a release(M)
        ss >> action;

        

        // Checks if mouse inputs are valid(actually useful for code)
        if(button != 0) return;
        if(action != 'm') return;

        // Initializes struct values
        Input input;
        
        input.col = (col + (col % 2)) / 2 - 1; // Makes a multiple of two then divides by two(each emoji is two columns)
        input.row = row - 1; 
        
        // Sends values to OnClick() event
        OnClick(input.row, input.col, a);
    }

    // Decodes signals the terminal sends
    void ReadInput(bool a[][yMax])
    {
        // Will be received as: ESC[< button; column; row M << indicates press event type(capital M means release)

        // Loops through each sent byte in the signal
        char c; // Used to store the sequence type

        while(read(STDIN_FILENO, &c, 1) > 0) // Loops through each sequence
        {
            if(c == '\x1b') // Makes sure this is an ESC mouse signal
            {
                char seq[32];
                int i = 0;

                while(read(STDIN_FILENO, &seq[i], 1) > 0) // Loops through each byte in the signal & updates it's seq[] value
                {
                    if(seq[i] == 'M' || seq[i] == 'm') break; // Indicates end of mouse event

                    i++;
                }

                seq[i + 1] = '\0'; // Indicates end of sequence

                // Saves sequence
                ParseMouseSequence(seq, a);
            }
        }
    }

    // Functions needed for global access
    public: 
        void StartMouseSignaling()
        {
            EnableRawMode();
            EnableMouse();
        }

        void GetSignals(bool a[][yMax])
        {
            ReadInput(a);
        }

        void StopMouseSignaling()
        {
            DisableMouse();
            DisableRawMode();
        }
};

#pragma endregion
//-----------------------------------------------------------------------------------------------------------

int main()
{
    // Game Variables
    bool game[xMax][yMax];
    bool nextFrame[xMax][yMax];
       
    // Initializes arrays
    for(int x = 0; x < xMax; x++) for(int y = 0; y < yMax; y++)
    {
        game[x][y] = 0;
        nextFrame[x][y] = 0;
    }

    // TEMP TEST
    Output(game);

    MouseInput input;

    int b, r, c;
    char a;

    input.StartMouseSignaling();
    input.GetSignals(game);
    input.StopMouseSignaling();

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
    if(nearby[0] && nearby[2] && a[cords[0] - 1][cords[1] - 1]) active++; // Top left
    if(nearby[1] && nearby[2] && a[cords[0] + 1][cords[1] - 1]) active++; // Top right
    if(nearby[0] && nearby[3] && a[cords[0] - 1][cords[1] + 1]) active++; // Bottom left
    if(nearby[1] && nearby[3] && a[cords[0] + 1][cords[1] + 1]) active++; // Bottom right

    return active;
}

// Outputs the frame
void Output(bool a[][yMax])
{
    // Clears console
    cout << "\e[1;1H\e[2J"; 
    // Loops through all values in the array and outputs it
    for(int x = 0; x < xMax; x++)
    {
        for(int y = 0; y < yMax; y++)
        {
            cout << sprites[a[x][y]];
        }

        cout << "\n";
    }
}

// Toggles the value of a given cell
void OnClick(int x, int y, bool a[][yMax])
{
    a[x][y] = !a[x][y];

    Output(a);
}

#pragma endregion