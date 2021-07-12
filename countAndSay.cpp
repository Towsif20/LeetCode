#include<bits/stdc++.h>

using namespace std;

string say(string s)
{
    int j = 1;
    char c = s[0];

    string ans = "";

    for(int i=1;i<s.size();i++)
    {
        if(c == s[i])
        {
            j++;
        }

        else
        {
            char t = j + '0';
            string temp;
            temp.push_back(t);
            temp.push_back(c);
            ans += temp;

            c = s[i];
            j = 1;
        }
    }

    char t = j + '0';
    string temp;
    temp.push_back(t);
    temp.push_back(c);
    ans += temp;


    //cout<<"ans = "<<ans<<endl;
    return ans;
}

string countAndSay(int n)
{
    if(n == 1)
        return "1";

    string s = "";

    while(n > 1)
    {
        n--;
        string res = countAndSay(n);

        return say(res);
    }

    return s;
}



int main()
{   
    cout<<countAndSay(10)<<endl<<"13211311123113112211";
}