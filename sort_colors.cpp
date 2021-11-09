#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums)
{
    int count[3] = {0, 0, 0};

    int len = nums.size();

    for (int i = 0; i < len; i++)
    {
        count[nums[i]]++;
    }

    int index = 0;

    for (int c = 0; c < 3; c++)
    {
        for (int i = 0; i < count[c]; i++)
        {
            nums[index++] = c;
        }
    }
}

int main()
{
}
