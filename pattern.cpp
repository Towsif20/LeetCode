#include <bits/stdc++.h>

using namespace std;

bool wordPattern(string pattern, string s)
{
    int len1 = pattern.length();
    int len2 = s.length();

    unordered_map<char, int> map1;
    unordered_map<string, int> map2;

    int count = 0;

    for(int i=0;i<len2;i++)
    {
        if (s[i] == ' ')
            count++;
    }

    if(len1 != count + 1)
        return false;


    string temp = "";
    int j = 0;

    for(int i=0;i<len2;i++)
    {
        if (s[i] != ' ')
            temp += s[i];

        if(s[i] == ' ' || i == len2-1)
        {
            cout<<"temp = "<<temp<<endl;
            cout<<"pattern["<<j<<"] = "<<pattern[j]<<endl;

            if(map2[temp] != map1[pattern[j]])
                return false;

            map1[pattern[j]] = i+1;
            map2[temp] = i+1;

            temp = "";
            j++;

            continue;
        }

        //temp += s[i];
    }

    return true;
}

    int main()
{
    string pattern = "abba";
    string s = "dog cat cat fish";

    cout<<wordPattern(pattern, s);
}
