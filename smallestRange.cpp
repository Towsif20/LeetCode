#include<bits/stdc++.h>

using namespace std;

int smallestRangeI(vector<int>& nums, int k)
{
    int len = nums.size();
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i=0;i<len;i++)
    {
        if(max < nums[i])
            max = nums[i];

        if(min > nums[i])
            min = nums[i];
    }

    max -= k;
    min += k;

    if(min > max)
        return 0;

    return max - min;
}

int main()
{
    vector<int> a{1,3,6};

    cout<<smallestRangeI(a, 1);
}
    