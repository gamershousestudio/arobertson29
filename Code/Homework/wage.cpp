#include<iostream>

using namespace std;

int main()
{
    const short int overtime_time = 40;

    float hours, wage;

    char overtime;

    cout << "\n\n\nHello, welcome to wage calculator\n\n";

    cout << "What is your hourly wage? \n";
    cin >> wage;

    cout << "How many hours did you work? \n";
    cin >> hours;

    cout << "\n\n\n";

    if(hours > overtime_time)
    {
        cout << "Congrats, you qualify for overtime!\n";

        cout << "Does your employer offer overtime? (y/n)\n";
        cin >> overtime;

        if(toupper(overtime) == 'Y')
        {
            cout << "Your total pay is $";
            cout << wage * 40 + (wage * 1.5f * (hours - 40)) << "!\n";

            return 0;
        }
    }

    cout << "Your total pay is $";
    cout << wage * hours << "!\n";

    return 0;
}