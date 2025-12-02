#include<iostream>

using namespace std;

const int r = 5;
const int c = 5;

const string fal = "🟦";
const string tru = "🟥";

const int chances = 3;

int main()
{
    srand(time(NULL));

    bool a[r][c];

    int random[2];

    std::cout << "\n\n";

    // Vars for loops
    string s;

    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            a[x][y] = 0;
        }
    }

    for(int i = 0; i < chances; i++)
    {
        random[0] = rand() % r;
        random[1] = rand() % c;

        if(a[random[0]][random[1]] == 1)
        {
            i--;
        }
        else
        {
            a[random[0]][random[1]] = 1;
        }
    }

    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            if(a[x][y] == 0) s = fal;
            else s = tru;

            cout << s;
        }

        cout << "\n";
    }

    std::cout << "\n";

    return 0;
}