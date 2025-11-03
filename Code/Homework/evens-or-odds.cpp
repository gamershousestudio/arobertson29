#include<iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    const int amount = 50;
    int nums[amount];

    int evens = 0;
    int odds = 0;

    cout << "\nWelcome to {I am too tired to come up with a name}\n\n";

    for(int i = 0; i < amount; i++)
    {
        nums[i] = rand() % 101;
        cout << nums[i] << "\n";
    }

    return 0;
}