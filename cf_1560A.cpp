#include<bits/stdc++.h>

using namespace std;

int findKthTerm(int k)
{
    int x = 0;

    for(int i=1;i<=k;i++)
    {
        if(i%3 == 0 || i%10 == 3)
            x++;//continue;

        x++;
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

        cout<<x<<endl<<endl;
    }

    return 0;


}

