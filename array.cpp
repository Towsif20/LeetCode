#include<bits/stdc++.h>

using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> ans;

    for(int i:nums)
    {
        ans.push_back(i);
    }

    for (int i : nums)
    {
        ans.push_back(i);
    }

    return ans;
}

int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int sum = 0;

    for(int i=0;i<nums.size()-1;i+=2)
    {
        sum += nums[i];
    }

    return sum;
}

int missingNumber(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());

    int n = nums.size();

    // if(nums[0] == 1)    return 0;
    // if(nums[n-1] == n-1)    return n;

    // for(int i=1;i<n;i++)
    // {
    //     if(nums[i] - nums[i-1] > 1) return nums[i-1] + 1;
    // }

    int result = n;
    for(int i=0;i<n;i++)
    {
        result ^= nums[i];
        result ^= i;
    }

    return result;
}

int main()
{
    return 0;
}