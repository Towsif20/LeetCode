#include<bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<int> result;

    int i = 0;
    int j = 0;

    while(i<m && j<n)
    {
        if(nums1[i] <= nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        }

        else
        {
             result.push_back(nums2[j]);
             j++;
        }
    }

    while(i<m)
    {
        result.push_back(nums1[i]);
        i++;
    }

    while(j<n)
    {
        result.push_back(nums2[j]);
        j++;
    }

    return result;
}

vector<int> sortedSquares(vector<int>& nums)
{
    vector<int> result1;
    vector<int> result2;

    int len = nums.size();

    int i = 0;

    int negativeIndex = -1;
    bool nonNegative = false;

    for(i=0;i<len;i++)
    {
        if(nums[i] >= 0)
        {
            negativeIndex = i-1;
            nonNegative = true;
            break;
        }
    }

    if(!nonNegative)
        negativeIndex = len-1;

    for(int i=negativeIndex;i>=0;i--)
    {
        result2.push_back(nums[i]*nums[i]);
    }

    for(int i=negativeIndex+1;i<len;i++)
    {
        result1.push_back(nums[i]*nums[i]);
    }

    return merge(result1, result2);
}


int main()
{
    vector<int> nums = {-5,-3,-2,-1};

    vector<int> nums1 = sortedSquares(nums);

    for(int i : nums1)
    {
        cout<<i<<" ";
    }
}
    