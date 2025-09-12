// Imports input/output stream
#include<iostream>

using namespace std;

// Main function; 0 means no errors
int main()
{

    // Variables
    double length, width;

    // Initializes variables through user input
    cout << "What is the rectange's length? ";
    cin >> length;

    cout << "What is the rectangle's width? ";
    cin >> width;

    cout << "\n\n\n";

    // Returns the perimeter and area
    cout << "The perimeter is " << (2 * length) + (2 * width);
    cout << "\nThe area is " << (length * width) << "\n";

    return 0;
}