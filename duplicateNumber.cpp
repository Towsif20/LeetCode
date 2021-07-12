#include<iostream>
#include<math.h>
#include<vector>

using namespace std;


int findDuplicate(vector<int>& nums)
{
    int len = nums.size();

    for(int i=0;i<len;i++)
    {
        int index = nums[i]%len;
        nums[index] += len;
    }

    for(int i=1;i<len;i++)
    {
        if(nums[i] > 2 * len)
        {
            return i;
        }
    }

    return -1;
}

int singleNumber(vector<int>& nums)
{
    int unique = 0;

    for(int n : nums)
    {
        unique ^= n;
    }

    return unique;
}


int main()
{   
    vector<int> v;

    // v.push_back(4);
    // v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);

    cout<<singleNumber(v);
}