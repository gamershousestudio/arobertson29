#include<iostream>

using namespace std;

string Weirdify(string s);

const char quote = 34; // Cannot use ' " ' within strings; so creating a value to store ascii instead

// 's' short for string; "ss" weirdified version of 's'

int main()
{
    string s;
    string ss;

    cout << "Welcome to the weirdifier, where we can weirdify your already weird sentences!\n\nPlease enter your sentence:\n";

    getline(cin, s);
    ss = Weirdify(s);

    s[0] = toupper(s[0]);

    cout << "\n" << s << " weirdified is " << quote << ss << quote << ".\n\n";

    return 0;
}

string Weirdify(string s)
{
    string ss;

    for(int i = 0; i < s.length(); i++)
    {
        ss += s[i];
        ss += s[i];
    }

    return ss;
}