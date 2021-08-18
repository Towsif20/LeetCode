#include<bits/stdc++.h>

using namespace std;

int findKthTerm(int k)
{
    int x = 0;

    for(int i=1;i<=k;i++)
    {
        x++;

        if(x%3 == 0 || x%10 == 3)
            x++;//continue;

        if(x%3 == 0 || x%10 == 3)
            x++;//continue;
    }

    
    return x;
}

int main()
{

    int t, k, x;

    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>k;

        x = findKthTerm(k);

        cout<<x<<endl;
    }

    return 0;


}

