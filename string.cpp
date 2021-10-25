#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;

    for (string s : operations)
    {
        if (s == "X++" || s == "++X")
            x++;

        else
            x--;
    }

    return x;
}

vector<int> partitionLabels(string s)
{
    int n = s.size();

    int i = 0, j = 0, start = 0;

    map<char, int> maxIndexOfChar;

    for (i = 0; i < n; i++)
    {
        maxIndexOfChar[s[i]] = i;
    }

    cout << endl;

    vector<int> result;

    i = 0;
    while (i < n)
    {
        if (j < maxIndexOfChar[s[i]])
            j = maxIndexOfChar[s[i]];

        cout << j << " ";

        if (i == j)
        {
            result.push_back(i - start + 1);
            start = i + 1;
        }
        i++;
    }

    return result;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;

    int n = intervals.size();

    if (n == 1)
    {
        result.push_back({intervals[0][0], intervals[0][1]});

        return result;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((intervals[i][0] > intervals[j][0]) || (intervals[i][0] == intervals[j][0] && intervals[i][1] > intervals[j][1]))
            {
                int t0 = intervals[i][0];
                int t1 = intervals[i][1];

                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];

                intervals[j][0] = t0;
                intervals[j][1] = t1;
            }
        }
    }

    int min = intervals[0][0];
    int max = intervals[0][1];

    bool flag = false;

    int global_min = INT_MAX;
    int global_max = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        if (intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][0] <= intervals[i][1])
        {
            max = ::max(intervals[i + 1][1], intervals[i][1]);

            if (i + 1 == n - 1)
            {
                flag = true;
            }
        }

        else
        {
            global_min = ::min(global_min, min);
            global_max = ::max(global_max, max);

            if (global_max > max && global_min < min)
                continue;

            result.push_back({min, max});

            min = intervals[i + 1][0];
            max = intervals[i + 1][1];
            if (i + 1 == n - 1)
            {
                result.push_back({min, max});
            }
        }
    }

    if (flag)
    {
        global_min = ::min(global_min, min);
        global_max = ::max(global_max, max);

        if (global_max > max && global_min < min)
            return result;

        result.push_back({min, max});
    }
    return result;
}

int main()
{
    vector<vector<int>> param = {{1, 4}};
    vector<vector<int>> vec = merge(param);

    for (vector<int> v : vec)
    {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}