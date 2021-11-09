#include <bits/stdc++.h>

using namespace std;

//not okay

void solve(vector<vector<char>> &board)
{
    int m = board.size();

    int n = board[0].size();

    // bool flipped[200][200];

    // for (int i = 0; i < 00; i++)
    // {
    //     for (int j = 0; j < 200; j++)
    //     {
    //         flipped[i][j] = false;
    //     }
    // }

    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (board[i][j] == 'O')
            {
                if (board[i - 1][j] == 'O')
                {
                    if (i - 1 == 0)
                        continue;
                }

                if (board[i + 1][j] == 'O')
                {
                    if (i + 1 == n - 1)
                        continue;
                }

                if (board[i][j - 1] == 'O')
                {
                    if (j - 1 == 0)
                        continue;
                }

                if (board[i][j + 1] == 'O')
                {
                    if (j + 1 == m - 1)
                        continue;
                }

                board[i][j] = 'X';
                //flipped[i][j] = true;
            }
        }
    }
}

int main()
{
}
