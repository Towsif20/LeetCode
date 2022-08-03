#include <bits/stdc++.h>

using namespace std;

bool isUnique(char c, unordered_map<char, int> &map)
{
    for(auto it : map)
    {
        if(map[c] == 0)
            break;

        if(it.first == c)
            continue;

        if(it.second == map[c])
            return false;
    }

    return true;
}

int minDeletions(string s)
{
    vector<int> map(26, 0);

    int len = s.length();

    for(int i=0;i<len;i++)
    {
        map[s[i]-'a']++;
    }

    
    

    //cout<<s<<" "<<temp<<endl;

    unordered_set<int> set;

    int count = 0;

    for(int i=0;i<26;i++)
    {
        while(map[i] && set.find(map[i]) != set.end())
        {
            map[i]--;
            count++;
        }

        set.insert(map[i]);
    }

    

    return count;
}

int main()
{
    string s = "abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz";

    cout<<minDeletions(s);
}
