#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

string LCP(string s1, string s2)
{
    // if(s1 == s2)
    //     return s1;

    string lcp = "";
    
    int len1 = s1.length();
    int len2 = s2.length();

    int len = min(len1, len2);
   

    for(int i=0;i<len;i++)
    {
        if(s1[i] != s2[i])
        {
            return lcp;
        }

        else
        {
            lcp += s1[i];
        }
    }

    return lcp;
}

string longestCommonPrefix(vector<string>& strs) 
{
    int len = strs.size();

    if(len == 1)
        return strs[0];
        
    string lcp = LCP(strs[0], strs[1]);

    for(int i=1;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(i != j)
            {
                string current = LCP(strs[i], strs[j]);
                if(lcp.length() > current.length())
                    lcp = current;
            }
        }
    }   

    return lcp;
}

int main()
{   
    vector<string> strs = {"flower","flight", "flow"};
    //vector<string> strs = {"dog","racecar","car"};

    //cout<<LCP("flow", "flight");

    cout<<longestCommonPrefix(strs);
}