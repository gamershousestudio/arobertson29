//#pragma region Initialization

#include<iostream>

using namespace std;

// Imports for frame limiting
#include<chrono>
#include<thread>

// Global variables (feel free to change x&y max)
const int xMax = 50; // X = row(so technicially Y)
const int cols = 50; // Y = col(so technicially X)

const int cooldown = 100;

const string sprites[] = {"⬜️", "⬛️", "⏩", "🟥", "🔄", "⏭️"}; // 0 = inactive cell; 1 = active cell; 2 = step; 3 = quit

// Function prototypes
int GetNeighbors(bool a[][cols], int cords[]);

void Output(bool a[][cols]);

void OnClick(int x, int y, bool a[][cols]);

void Step(bool a[][cols]);

//#pragma endregion
//-----------------------------------------------------------------------------------------------------------

/* COMMENTING GUIDE

Comment right before line of code is for that region until the next instance
Comment before an empty line before a line of code is for the whole area until the next instance
Comment on the same line as code is specific to just that line
Comment outside of a function summerizes the role of that function

*/

//-----------------------------------------------------------------------------------------------------------
//#pragma region Notes

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

4) //#pragma region & //#pragma endregion
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

//#pragma endregion
//-----------------------------------------------------------------------------------------------------------
//#pragma region MouseInput

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
    bool ParseMouseSequence(const string &seq, bool a[][cols]) // Returns if the while loop should be exited
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
        if(button != 0) 
            return true;
        
        if(action != 'm') 
            return true;

        // Initializes struct values
        Input input;
        
        input.col = (col + (col % 2)) / 2 - 1; // Makes a multiple of two then divides by two(each emoji is two columns)
        input.row = row - 2; // Must subtract an extra one to account for \n buffering
        
        // Checks for special rows

        // Exit program
        if(input.row == 0 && input.col >= (cols + 1) && input.col <= (cols + 10)) // Position for exit emoji; room for buffering
            return false; 

        // Resets game board
        if(input.row == 2 && input.col >= (cols + 1) && input.col <= (cols + 10)) 
        {
            for(int x = 0; x < xMax; x++) for(int y = 0; y < cols; y++) a[x][y] = 0;

            Output(a);
        }

        // Runs the next step
        if(input.row == 4 && input.col >= (cols + 1) && input.col <= (cols + 10)) 
            Step(a);    
            
        // Runs the next ten steps
        if(input.row == 6 && input.col >= (cols + 1) && input.col <= (cols + 10)) 
            for(int i = 0; i < 10; i++)
            {
                Step(a);

                this_thread::sleep_for(chrono::milliseconds(cooldown)); // Delays by three seconds
            }

        // Runs the next 100 steps
        if(input.row == 8 && input.col >= (cols + 1) && input.col <= (cols + 10)) 
            for(int i = 0; i < 100; i++)
            {
                Step(a);

                this_thread::sleep_for(chrono::milliseconds(cooldown)); // Delays by three seconds
            }

        // Returns if the click is outside of bounds
        if(input.row > (xMax - 1) || input.col > (cols - 1)) 
            return true; 

        // Sends values to OnClick() event if all checks are passed
        OnClick(input.row, input.col, a);
        return true;
    }

    // Decodes signals the terminal sends
    void ReadInput(bool a[][cols])
    {
        // Will be received as: ESC[< button; column; row M << indicates press event type(capital M means release)

        // Loops through each sent byte in the signal
        char c; // Used to store the sequence type

        bool cont; // Checks if the while loop should continue

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
                cont = ParseMouseSequence(seq, a);

                // Exits if while loop should exit
                if(!cont) return;
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

        void GetSignals(bool a[][cols])
        {
            ReadInput(a);
        }

        void StopMouseSignaling()
        {
            DisableMouse();
            DisableRawMode();
        }
};

//#pragma endregion
//-----------------------------------------------------------------------------------------------------------

int main()
{
    // Game Variables
    bool game[xMax][cols];

    bool paused;
       
    // Initializes arrays
    for(int x = 0; x < xMax; x++) for(int y = 0; y < cols; y++)
        game[x][y] = 0;

    // Introduction
    cout << "\n\nHello!  Welcome to GameOfLifeOnABudget!";
    cout << "\n\nHere are the rules:\n";
    cout << " - If the cell is alive and there are two or three alive cells nearby, it lives\n"
         << " - If a cell is dead and there are three alive cells nearby, it becomes alive\n"
         << " - If a cell is alive and there is one or no alive cell nearby, it dies from loneliness\n"
         << " - If a cell is alive and there is four or more alive cells nearby, it dies from overcrowding";

    cout << "\n\nWould you like to play?(y/n)\n";

    char choice;
    cin >> choice;

    cout << "\n\n";

    if(choice == 'y')
    {
        // Main loop
        Output(game);

        MouseInput input;

        int b, r, c;
        char a;

        input.StartMouseSignaling();
        input.GetSignals(game);
        input.StopMouseSignaling();
    }
    else if(choice == 'n')
    {
        cout << "Then why are you here...";
    }
    else
    {
        cout << "Wow... So competent...";
    }

    cout << "\n\n";

    return 0;
}

//-----------------------------------------------------------------------------------------------------------
//#pragma region Functions

// Finds how many neighbors are near a given cell
int GetNeighbors(bool a[][cols], int cords[])
{
    // Sees if cells around it go out of bounds

    bool nearby[4]; // List of if the nearby cells exist; left = 0; right = 1; top = 2; bottom = 3;
    for(int i = 0; i < 4; i++) 
        nearby[i] = true; // Initializes nearby to minimize logic trees later on

    // Checks if cell is on leftmost
    if((cords[1] - 1) < 0) 
        nearby[0] = false;

    // Checks if cell is on rightmost
    else if((cords[1] + 1) > (cols - 1))
        nearby[1] = false;

    // Checks if cell is on topmost
    if((cords[0] - 1) < 0) 
        nearby[2] = false;

    // Checks if cell is on bottom most
    else if((cords[0] + 1) > (xMax - 1))   
        nearby[3] = false;

    // Checks values of all nearby cells(assuming they exist)

    int active = 0;

    // Linear
    if(nearby[0] && a[cords[0]][cords[1] - 1]) active++; // To the left
    if(nearby[1] && a[cords[0]][cords[1] + 1]) active++; // To the right
    if(nearby[2] && a[cords[0] - 1][cords[1]]) active++; // Above
    if(nearby[3] && a[cords[0] + 1][cords[1]]) active++; // Below

    // Diagonal
    if(nearby[0] && nearby[2] && a[cords[0] - 1][cords[1] - 1]) active++; // Top left
    if(nearby[1] && nearby[2] && a[cords[0] - 1][cords[1] + 1]) active++; // Top right
    if(nearby[0] && nearby[3] && a[cords[0] + 1][cords[1] - 1]) active++; // Bottom left
    if(nearby[1] && nearby[3] && a[cords[0] + 1][cords[1] + 1]) active++; // Bottom right

    return active;
}

// Outputs the frame
void Output(bool a[][cols])
{
    // Clears console
    cout << "\e[1;1H\e[2J"; 

    cout << "\n";  // Ubuntu VSCode has an issue with buffering; purely to make sure all UI shows up; may need more/less \ns depending on os & terminal

    // Note some OS's and terminals may distort size of grid making x or y larger
    // Loops through all values in the array and outputs it
    for(int x = 0; x < xMax; x++)
    {
        for(int y = 0; y < cols; y++)
            cout << sprites[a[x][y]];

        // Adds emojis for "special lines"

        // End program
        if(x == 0)
            cout << "  " << sprites[3] << "  Quit Program";

        // Reset
        if(x == 2)
            cout << "  " << sprites[4] << "  Reset Board";

        // Forward step
        if(x == 4)
            cout << "  " << sprites[2] << "  Forward Step";

        // Forward x10 step
        if(x == 6)
            cout << "  " << sprites[5] << "  Forward x10";

        if(x == 8)
            cout << "  " << sprites[5] << "  Forward x100";

        cout << "\n";
    }
}

// Toggles the value of a given cell
void OnClick(int x, int y, bool a[][cols])
{
    a[x][y] = !a[x][y]; // Inverts current cell value

    Output(a); // Outputs new array
}

// Moves sim forward based on game logic
void Step(bool a[][cols])
{
    // Variables for loops
    bool nextFrame[xMax][cols];
    int cords[2];

    int nearby;

    bool val;

    // Loops through every cell
    for(int x = 0; x < xMax; x++) 
    {
        for(int y = 0; y < cols; y++)
        {
            cords[0] = x;
            cords[1] = y;

            nearby = GetNeighbors(a, cords); // Finds the cells nearby to a given cell

            // Game rules: 2 || 3 = cell stays alive; 3 = cell becomes alive; 1 = cell dies; 4+ = cell dies

            if(a[x][y] && (nearby == 2 || nearby == 3)) val = true; // If the cell is active & 2 or 3 nearby are active
            else if(nearby == 3) val = true; // If cell is inactive & 3 nearby are active
            else val = false; // Cell dies in all other cases

            nextFrame[x][y] = val;
        }
    }

    // Writes new frame
    for(int x = 0; x < xMax; x++) 
    {
        for(int y = 0; y < cols; y++)
        {
            a[x][y] = nextFrame[x][y]; // Updates value
        }
    }

    Output(a);
}
//#pragma endregion