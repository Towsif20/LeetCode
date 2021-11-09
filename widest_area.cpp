#include <bits/stdc++.h>

using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    int n = points.size();

    vector<int> x;

    for (int i = 0; i < n; i++)
    {
        x.push_back(points[i][0]);
    }

    sort(x.begin(), x.end());

    int max = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        int dif = x[i + 1] - x[i];

        if (max < dif)
            max = dif;
    }

    return max;
}

int main()
{
}
