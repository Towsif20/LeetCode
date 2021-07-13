#include<bits/stdc++.h>

using namespace std;

int minPartitions(string n)
{
    int max = -1;

    for(char c : n)
    {
        int t = c - '0';

        if(max < t)
            max = t;

        if(max == 9)
            return 9;
    }

    return max;
}


int main()
{
    cout<<minPartitions("1876");
}
    