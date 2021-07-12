#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int j=0;

    int len = nums.size();

    for(int i=0;i<len-1;i++)
    {
        if(nums[i+1] != nums[i])
        {
            nums[j] = nums[i];
            j++;
        }
    }

    if(len > 0)
        nums[j++] = nums[len-1];

    return j;
}

int removeElement(vector<int>& nums, int val)
{
    int j=0;

    int len = nums.size();

    for(int i=0;i<len;i++)
    {
        if(nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
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

    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);

    cout<<removeElement(v, 2);
}