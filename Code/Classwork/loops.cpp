/* LOOPS NOTES

Steps for creating a loop:
 - Create a loop variable
 - Check the loop variable as a part of the condition
 - Loop variable has to change somewhere in the loop

*/

#include<iostream>

using namespace std;

int main()
{
    // While loop examples
    int x = 0;

    while(x < 10)
    {
        cout << x++ << endl;
    }


    char play;

    cout << "Do you want to start the game?(y/n)\n";
    cin >> play;

    while(toupper(play) == 'Y')
    {
        cout << "Do you want to start the game?(y/n)\n";
        cin >> play;
    }

    // DoWhile examples
    // Dowhile can run one at the least while while may not run at all
    do
    {
        cout << "Do you want to start the game?(y/n)\n";
        cin >> play;
    }while(toupper(play) == 'Y');

    return 0;
}