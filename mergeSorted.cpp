#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
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

    nums1.clear();

    for(int i=0;i<m+n;i++)
    {
        nums1.push_back(result[i]);
    }
}



int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 0, nums2, 3);

    for(int i : nums1)
    {
        cout<<i<<" ";
    }
}
    