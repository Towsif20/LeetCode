#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        while (j < k)
        {
            if (k < nums.size() && nums[k] == nums[k + 1])
            {
                k--;
                continue;
            }

            if (nums[i] + nums[j] + nums[k] > 0)
                k--;

            else if (nums[i] + nums[j] + nums[k] < 0)
                j++;

            else
            {
                vector<int> v = {nums[i], nums[j], nums[k]};
                result.push_back(v);
                j++;
                k--;
            }
        }
    }

    return result;
}

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int len = nums.size();

    int min = INT_MAX;

    int result = target;

    for (int i = 0; i < len; i++)
    {
        int j = i + 1;
        int k = len - 1;

        while (j < k)
        {
            int val = nums[i] + nums[j] + nums[k];
            int d = abs(val - target);

            if (d == 0)
                return val;

            if (d < min)
            {
                min = d;
                result = val;
            }

            if (val - target > 0)
                k--;
            else
                j++;
        }
    }

    return result;
}

int main()
{
    vector<int> v = {0, 0, 0, 0};
    threeSum(v);
}
