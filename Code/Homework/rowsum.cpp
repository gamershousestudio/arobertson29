#include<iostream>

using namespace std;

const int r = ;
const int c = ;

int main()
{
    srand(time(NULL));

    int a[r][c];

    int s;

    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            a[r][c] = rand();
        }
    }

    return 0;
}