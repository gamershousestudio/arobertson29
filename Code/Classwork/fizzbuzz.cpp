#include<iostream>

using namespace std;

int main()
{
    cout << endl;

    srand(time(NULL));

    int loop_times = 100;
    

    for(int i = 1; i <= loop_times; i++)
    {

        if(i % 3 == 0 && i % 5 == 0)
        {
            cout << "FizzBuzz\n";
        }
        else if(i % 3 == 0)
        {
            cout << "Fizz\n";
        }
        else if(i % 5 == 0)
        {
            cout << "Buzz\n";
        }
        else
        {
            cout << i << endl;
        }
    }

    cout << endl;

    return 0;
}