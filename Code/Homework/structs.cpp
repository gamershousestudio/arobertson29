#include<iostream>
#include <cstdlib>

using namespace std;

struct codingStats
{
    double linesPerMinute;
    int layoffAmount;
    bool hasDegree;
    bool isWeird;
};

int main()
{
    codingStats stats;

    cout << "\nHow many lines of code can you code per minute?\n";
    cin >> stats.linesPerMinute;

    if(stats.linesPerMinute > 5)
    {
        cout << "\nokay... okay... not bad...\n\n";
    }
    else
    {
        cout << "\nSLOWWWWWWW\n\n";
    }

    cout << "How many times have you been layed off?\n";
    cin >> stats.layoffAmount;

    if(stats.layoffAmount <= 0)
    {
        cout << "\nSure bud, sure...\n\n";
    }
    else
    {
        cout << "\nHaha imagine\n\n";
    }

    char yes_or_no;

    cout << "Do you have a comp sci degree? (y/n)\n";
    cin >> yes_or_no;

    if(yes_or_no == 'y') stats.hasDegree = 1;
    else stats.hasDegree = 0;

    if(stats.hasDegree)
    {
        cout << "\nGood job wasting your money\n\n";
    }
    else
    {
        cout << "\nYeah so... your not gonna get a job...\n\n";
    }

    cout << "Are you a v*** coder? (y/n)"; // Had to censor vibe to keep pg
    cin >> yes_or_no;

    if(yes_or_no == 'y') stats.isWeird = 1;
    else stats.isWeird = 0;

    if(stats.isWeird)
    {
        // string cmd = "sudo shutdown -h now";  CENSORED(sadly)
        // system(cmd.c_str());

        cout << "\nDIE HOW DARE YOU DO THIS WHY\n\n";
    }
    else
    {
        cout << "\nYou live... For now...";
    }

    return 0;
}