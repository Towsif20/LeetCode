#include<bits/stdc++.h>

using namespace std;

int findOppositePerson(int a, int b, int c)
{
    int diff = abs(a-b);
    
    int n = diff * 2;

    if(c > n || a > n || c  > n)
        return -1;

    if(c - diff <= 0 && c + diff > n)
        return -1;

    if(c + diff == a || c + diff == b)
    {
        if(c - diff <= 0)
            return -1;
    }

    if(c - diff <= 0)
    {
        if(c+diff == a || c+diff == b)
            return -1;

        return c + diff;
    }

    if(c + diff > n)
    {
        if(c-diff == a || c-diff == b)
            return -1;

        return c - diff;
    }


    return -1;
}

int main()
{

    int t, a, b, c, x;

    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;

        x = findOppositePerson(a, b, c);

        cout<<x<<endl;
    }

    return 0;


}

