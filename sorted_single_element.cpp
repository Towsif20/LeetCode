#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return nums[low];
}

int hammingDistance(int x, int y)
{
    int t = x ^ y;

    int one = 1;

    int count = 0;

    for (int i = 0; i < 31; i++)
    {
        if ((one & t) == one)
            count++;

        one = one << 1;
    }

    return count;
}

int totalHammingDistance(vector<int> &nums)
{
    int sum = 0;
    int len = nums.size();

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            sum += hammingDistance(nums[i], nums[j]);
        }
    }

    return sum;
}

int main()
{
}
