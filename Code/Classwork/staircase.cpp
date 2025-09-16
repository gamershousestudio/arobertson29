#include<iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    int grade = rand() % 101;

    cout << "Your grade for this semester is " << grade << "\n";

    return 0;
}