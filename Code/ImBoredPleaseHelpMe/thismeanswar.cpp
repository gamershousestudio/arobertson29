#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Array of binary strings representing ASCII codes
    string binary[] = {"1001000", "1100101", "1101100", "1101100", "1101111", 
                       "100000", "1010111", "1101111", "1110010", "1101100", 
                       "1100100", "100001"};
                       
    const int size = sizeof(binary) / sizeof(binary[0]);

    // We'll build the resulting string here
    string result = "";

    for (int i = 0; i < size; ++i) 
    {
        int ascii_val = stoi(binary[i], nullptr, 2);  // Convert binary to int
        char c = static_cast<char>(ascii_val);       // Convert int to char
        result += c;                                  // Append to result string
    }

    cout << result << endl;  // Prints: Hello World!

    return 0;
}
