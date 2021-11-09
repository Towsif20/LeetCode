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

int main()
{
    vector<int> v = {0, 0, 0, 0};
    threeSum(v);
}
