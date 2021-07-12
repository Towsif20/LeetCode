#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int max = INT_MIN;
    int temp = 0;

    int len = nums.size();

    for(int i=0;i<len;i++)
    {
        temp += nums[i];

        if(max < temp)
            max = temp;

        if(temp < 0)
            temp = 0;
    }

    return max;
}

int main()
{
    //   vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    //   vector<int> v = {1};
      vector<int> v = {5,4,-1,7,8};

      cout<<maxSubArray(v);
}
    