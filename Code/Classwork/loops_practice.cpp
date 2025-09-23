#include<iostream>

using namespace std;

int main()
{
    char decrease;
    int VSgrade = 100;

    const int amount = 500;

    cout << "Do you want to decrease Skop's grade? (y/n)\n";
    cin >> decrease;

    cout << endl;

    while(tolower(decrease) == 'y' && (VSgrade > 0))
    {
        VSgrade -= 1;

        cout << "Victor's grade is now " << VSgrade << endl;

        if((VSgrade % amount == 0 && VSgrade > 0))
        {
            cout << "\nDo you want to lower his score more? (y/n)\n";
            cin >> decrease;

            cout << endl;
        }
    }

    return 0;
}