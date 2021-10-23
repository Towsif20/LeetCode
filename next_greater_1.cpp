#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        int k;

        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                k = j;
                break;
            }
        }

        int greater = -1;

        for (int j = k + 1; j < nums2.size(); j++)
        {
            if (nums2[j] > nums2[k])
            {
                greater = nums2[j];
                break;
            }
        }

        result.push_back(greater);
    }

    return result;
}

int main()
{
    return 0;
}