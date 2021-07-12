#include<bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int len = nums.size();

    if(target  <= nums[0])
        return 0;

    for(int i=0;i<len;i++)
    {
        if(nums[i] == target)
            return i;

        if(i < len-1)
        {
            if(target > nums[i] && target < nums[i+1])
                return i+1;
        }
    }

    return len;
}

int main()
{   
    vector<int> v;

    // v.push_back(0);
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(4);

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);

    cout<<searchInsert(v, 0);
}