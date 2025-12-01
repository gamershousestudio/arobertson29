#include<iostream>
#include<iomanip>

using namespace std;

const int r = 8;
const int c = 8;

void out(string a[][c]);

int main()
{
    string board[r][c];

    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            board[x][y] = "🟦";
        }
    }

    out(board);

    return 0;
}

void out(string a[][c])
{
    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {

            cout << a[x][y];
        }

        cout << "\n";
    }
}