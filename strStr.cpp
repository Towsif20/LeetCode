#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int strStr(string haystack, string needle)
{
    if(needle == "")
        return 0;

    int ans = -1;

    int len = haystack.length();
    int len2 = needle.length();

    for(int i=0;i<len-len2+1;i++)
    {
        int temp = i;
        int k = i;

        for(int j=0;j<len2;j++)
        {
            if(haystack[k] != needle[j])
            {
                temp = -1;
                break;
            }   
            k++;
        }

        if(temp != -1)
        {
            ans = temp;
            break;
        }
    }

    return ans;
}

int main()
{   
    cout<<strStr("hello", "skdjsad");
}