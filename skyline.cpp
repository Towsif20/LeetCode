#include <bits/stdc++.h>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    vector<int> max_row;
    vector<int> max_col;

    int n = grid.size();

    for (int i = 0; i < n; i++)
    {
        int max_row_i = INT_MIN;
        int max_col_i = INT_MIN;

        for (int j = 0; j < n; j++)
        {
            if (max_row_i < grid[i][j])
                max_row_i = grid[i][j];

            if (max_col_i < grid[j][i])
                max_col_i = grid[j][i];
        }

        max_row.push_back(max_row_i);
        max_col.push_back(max_col_i);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int new_i_j = min(max_row[i], max_col[j]);

            sum += (new_i_j - grid[i][j]);
        }
    }

    return sum;
}

int main()
{
    vector<vector<int>> v = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};

    cout << maxIncreaseKeepingSkyline(v);
}
