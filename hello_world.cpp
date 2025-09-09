/* FILE NAMING NOTES

File naming rules for programming:
 - No spaces
 - No special characters(except - and _)
 - Must start with a letter
 - File must end in programming language(.py, .cs, .cpp, java, .js, .html, .css, ect.)

File naming norms for programming:
 - camelCase
 - snake_case <-CPP FILES USE THIS
 - UpperCase
 - Should be related to task(variables, files, functions, etc.)

*/

/* VARIABLE NOTES

What is a variables:
 - Stores things(int, float, bool, char(subset of int; uses ascii), string(list of chars), double(double storage of float), etc.)
 - Takes up space
 - Can use long & short to save/use more space
 
Creating variables:
 - Subset type name = value;
 - Subset type name;
 - Name should follow the naming norms for programming
 - Declaration: specifying type and name
 - Initialization: giving a variable a value

*/

#include <iostream> // Input output stream

// Main function, code executed line by line inside
int main()
{
    // Imports
    using std::cout;
    using std::cin;

    // Prints 'Hello, World!' to the console
    cout << "Hello, World!\n";

    // Returns with error code 0 (no issues)
    return 0;
}