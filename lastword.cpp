#include<bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s)
{
    int len = s.size();

    int count = 0;

    int i = len-1;

    while(s[i] == ' ' && i>0)
        i--;
    
    

    while(i >= 0)
    {
        if(s[i] != ' ')
            count++;

        else
            return count;

        i--;
    }

    return count;
}


int main()
{
    cout<<lengthOfLastWord(" sd   ");   
}
    