#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic_n2(string s, string t)
{
    int len1 = s.length();
    int len2 = t.length();

    if(len1 != len2)
        return false;

    unordered_map<char, char> map;

    unordered_set<char> set;

    for(int i=0;i<len1;i++)
    {
        if(map.find(s[i]) != map.end())
        {
            if(map[s[i]] != t[i])
                return false;

            continue;
        }

        if(set.find(t[i]) != set.end())
            return false;

        set.insert(t[i]);
        map[s[i]] = t[i];
    }

    return true;

}

bool isIsomorphic(string s, string t)
{
    int len1 = s.length();
    int len2 = t.length();

    if (len1 != len2)
        return false;

    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    for(int i=0;i<len1;i++)
    {
        if(map1[s[i]] != map2[t[i]])
            return false;

        map1[s[i]] = i + 1;
        map2[t[i]] = i + 1;
    }

    return true;
}

int main()
{
    string s = "aa";
    string t = "ab";

    cout<<isIsomorphic(s, t);
}
