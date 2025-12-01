#include <iostream>

using namespace std;

int main()
{
    // Variables
    string word;
    string modified;
    string palindrome;

    // Introduction
    cout << "\nWelcome to everyones favorite egame show!\nIs that a palendrome!!!";

    cout << "\n\nPlease enter your word/phrase:\n";
    getline(cin, word);

    for(int i = 0; i < word.length(); i++) word[i] = tolower(word[i]);

    // Removes spaces
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] != ' ')
        {
            modified += word[i];
        }
    }

    // Flips it
    for(int i = modified.length() - 1; i >= 0; i--)
    {
        palindrome += modified[i];
    }

    // Uppercases first letter in word
    word[0] = toupper(word[0]);

    // Output
    if(modified == palindrome)
    {
        cout << "\n" << word << " is, in fact, a palindrome!!!!!!\n\n";
    }
    else
    {
        cout << "\nWho even hired this guy, he can't even do basic english...\n\n";
    }

    return 0;
}