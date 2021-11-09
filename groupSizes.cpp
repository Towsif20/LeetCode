#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    vector<int> id;

    int n = groupSizes.size();

    for (int i = 0; i < n; i++)
    {
        id.push_back(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (groupSizes[i] > groupSizes[j])
            {
                int t = groupSizes[i];
                groupSizes[i] = groupSizes[j];
                groupSizes[j] = t;

                t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }

    for (int i : groupSizes)
    {
        cout << i << " ";
    }

    vector<vector<int>> result;

    int k = -1;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;

        k = groupSizes[i];

        for (int j = 0; j < k; j++)
        {
            v.push_back(id[i + j]);
        }

        i += k - 1;

        result.push_back(v);
    }

    return result;
}

int main()
{
}
