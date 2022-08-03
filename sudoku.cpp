#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    bool count[9];
    int index;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            count[j] = false;

        for(int j=0;j<9;j++)
        {
            if(board[i][j] == '.')
                continue;

            index = board[i][j] - '0' - 1;
            
            if(count[index])
                return false;

            count[index] = true;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            count[j] = false;

        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] == '.')
                continue;

            index = board[j][i] - '0' - 1;

            if (count[index])
                return false;

            count[index] = true;
        }
    }

    for (int t = 0; t < 9; t += 3)
    {
        for (int k = 0; k < 9; k += 3)
        {
            for (int i = t; i < t + 3; i++)
            {
                for (int j = 0; j < 9; j++)
                    count[j] = false;

                for (int j = k; j < k + 3; j++)
                {
                    if (board[i][j] == '.')
                        continue;

                    index = board[i][j] - '0' - 1;

                    if (count[index])
                        return false;

                    count[index] = true;
                }

                //cout << endl;
            }

            //cout << endl;
        }
        // k += 3;
        //cout << endl;
    }

    return true;
}

int main()
{
    int t = 0, k = 0;

    for(int t=0;t<9;t+=3)
    {
        for(int k=0;k<9;k+=3)
        {
            for (int i = t; i < t + 3; i++)
            {
                for (int j = k; j < k + 3; j++)
                {
                    cout << i << "," << j << "\t";
                }

                cout<<endl;
            }

            cout<<endl;
        }
        // k += 3;
        cout<<endl;
    }
}
