#include <iostream>
#include <string>

using namespace std;

string GetBinary(string input)
{
    string output = "";

    int size = sizeof(input) / sizeof(input[0]);

    char chars[size];

    for(int i = 0; i < size; i++)
    {
        chars[i] = input[i];
    }

    int ascii[size];

    for(int i = 0; i < size; i++)
    {
        ascii[i] = chars[i];
    }

    return output;
}

string SetBinary(string input[])
{
    string output = "";

    int size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < size; ++i) 
    {
        int ascii_val = stoi(input[i], nullptr, 2);                                      
        char c = static_cast<char>(ascii_val);
        output += c;
    }

    return output;
}

int main()
{
    /*

    // Array of binary strings representing ASCII codes
    string binary[] = {"1001000", "1100101", "1101100", "1101100", "1101111", 
                       "100000", "1010111", "1101111", "1110010", "1101100", 
                       "1100100", "100001"};
                       
    const int size = sizeof(binary) / sizeof(binary[0]);

    string result = "";

    for (int i = 0; i < size; ++i) 
    {
        int ascii_val = stoi(binary[i], nullptr, 2);                                      
        char c = static_cast<char>(ascii_val);
        result += c;
    }

    cout << result << endl;

    */

    string binary[] = {"1001000", "1100101", "1101100", "1101100", "1101111", 
                       "100000", "1010111", "1101111", "1110010", "1101100", 
                       "1100100", "100001"};

    cout << SetBinary(binary);

    return 0;
}
