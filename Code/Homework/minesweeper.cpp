//#pragma region Initialization

#include<iostream>
#include<iomanip>

using namespace std;

// Imports for frame limiting
#include<chrono>
#include<thread>

// Global variables (feel free to change x&y max)
const int xMax = 20; // X = row(so technicially Y)
const int yMax = 20; // Y = col(so technicially X)

const int cooldown = 100;

const string sprites[] = {"🟥", "  ", "1️⃣ ", "2️⃣ ", "3️⃣ ", "4️⃣ ", "5️⃣ ", "6️⃣ ", "7️⃣ ", "8️⃣" };

// Function prototypes

void Output(int a[][yMax]);

void GenerateBoard(int a[][yMax], int bombs);

int GetNearby(int a[][yMax], int x, int y);

//#pragma endregion
//-----------------------------------------------------------------------------------------------------------
//#pragma region MouseInput

// Info on click event
struct Input
{
    int row;
    int col;

    bool clickType;
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
    bool ParseMouseSequence(const string &seq, bool a[][yMax]) // Returns if the while loop should be exited
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
        if(button != 0 || button != 1) // Left/right click 
            return true;
        
        if(action != 'm') // Action(up/down)
            return true;

        // Initializes struct values
        Input input;
        
        input.col = (col + (col % 2)) / 2 - 1; // Makes a multiple of two then divides by two(each emoji is two columns)
        input.row = row - 2; // Must subtract an extra one to account for \n buffering

        input.clickType = button; // The number will be either 0 or 1; works fine with bools

        // Exit program
        if(input.row == 0 && input.col >= (yMax + 1) && input.col <= (yMax + 10)) // Position for exit emoji; room for buffering
            return false; 

        
    }

    // Decodes signals the terminal sends
    void ReadInput(bool a[][yMax])
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

//#pragma endregion
//-----------------------------------------------------------------------------------------------------------

int main()
{
    srand(time(NULL));

    int boardFull[xMax][yMax];

    GenerateBoard(boardFull, 40);

    Output(boardFull);

    return 0;
}

//-----------------------------------------------------------------------------------------------------------
//#pragma region Functions

// Finds how many bombs are nearby each space
int GetNearby(int a[][yMax], int x, int y)
{
    // Sees if cells around it go out of bounds

    bool nearby[4]; // List of if the nearby cells exist; left = 0; right = 1; top = 2; bottom = 3;
    for(int i = 0; i < 4; i++) 
        nearby[i] = true; // Initializes nearby to minimize logic trees later on

    // Checks if cell is on leftmost
    if((y - 1) < 0) 
        nearby[0] = false;

    // Checks if cell is on rightmost
    else if((y + 1) > (yMax - 1))
        nearby[1] = false;

    // Checks if cell is on topmost
    if((x - 1) < 0) 
        nearby[2] = false;

    // Checks if cell is on bottom most
    else if((x + 1) > (xMax - 1))   
        nearby[3] = false;

    // Checks values of all nearby cells(assuming they exist)

    int active = 0;

    // Linear
    if(nearby[0] && a[x][y - 1] == -1) active++; // To the left
    if(nearby[1] && a[x][y + 1] == -1) active++; // To the right
    if(nearby[2] && a[x - 1][y] == -1) active++; // Above
    if(nearby[3] && a[x + 1][y] == -1) active++; // Below

    // Diagonal
    if(nearby[0] && nearby[2] && a[x - 1][y - 1] == -1) active++; // Top left
    if(nearby[1] && nearby[2] && a[x - 1][y + 1] == -1) active++; // Top right
    if(nearby[0] && nearby[3] && a[x + 1][y - 1] == -1) active++; // Bottom left
    if(nearby[1] && nearby[3] && a[x + 1][y + 1] == -1) active++; // Bottom right

    return active;
}

// Creates the integer array for the board
void GenerateBoard(int a[][yMax], int bombs)
{
    // Resets board
    for(int x = 0; x < xMax; x++) for(int y = 0; y < yMax; y++)
        a[x][y] = 0;

    // Variables for loop
    int random[2];

    // Loops through how many bombs are needed
    for(int i = 0; i < bombs; i++)
    {
        // Gets random cordinates
        random[0] = rand() % xMax;
        random[1] = rand() % yMax;

        // Makes sure bomb is not already there (-1 = bomb)
        if(a[random[0]][random[1]] != -1)
        {
            // Places bomb
            a[random[0]][random[1]] = -1;
        }
        else
        {
            // Subtracts from i so the loop runs an extra time
            i--;
        }
    }

    // Loops through every space in the board
    for(int x = 0; x < xMax; x++) for(int y = 0; y < yMax; y++)
    {
        // Makes sure it is not a bomb(we don't check nearby for bombs)
        if(a[x][y] != -1)
        {
            a[x][y] = GetNearby(a, x, y);
        }
    }
}

// Outputs the frame
void Output(int a[][yMax])
{
    // Clears console
    cout << "\e[1;1H\e[2J"; 

    cout << "\n";  // Ubuntu VSCode has an issue with buffering; purely to make sure all UI shows up; may need more/less \ns depending on os & terminal

    // Note some OS's and terminals may distort size of grid making x or y larger
    // Loops through all values in the array and outputs it
    for(int x = 0; x < xMax; x++)
    {
        for(int y = 0; y < yMax; y++)
            cout << sprites[a[x][y] + 1];

        // End program emoji
        //if(x == 0)
            //cout << "  " << sprites[3] << "  Quit Program";

        cout << "\n";
    }
}

//#pragma endregion