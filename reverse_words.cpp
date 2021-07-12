#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

string longestPalindrome(string s) 
{
    int size = s.length();

    bool ** table = new bool*[size];

    for(int i=0;i<size;i++)
    {
        table[i] = new bool[size];
    }

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            table[i][j] = false;
        }
    }

    int maxlength = 1;
    for(int i=0;i<size;i++)
    {
        table[i][i] = true;
    }

    
    int start = 0;

    for(int i=0;i<size-1;i++)
    {
        if(s[i] == s[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxlength = 2;
        }
    }

    for(int k=3;k<=size;k++)
    {
        for(int i=0;i<size-k+1;i++)
        {
            int j = i + k - 1;

            if(table[i+1][j-1] && s[i] == s[j])
            {
                table[i][j] = true;

                if(k > maxlength)
                {
                    start = i;
                    maxlength = k;
                }
            }
        }
    }

    string lps = "";
    for(int i=start;i<start + maxlength;i++)
    {
        lps += s[i];
    }

    for(int i=0;i<size;i++)
    {
        delete[] table[i];
    }

    delete[] table;

    return lps;
}

int main()
{   
    cout<<longestPalindrome("forgeeksskeegfor");
}