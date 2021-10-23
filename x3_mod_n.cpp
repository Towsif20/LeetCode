#include<bits/stdc++.h>

using namespace std;

int main()
{
    for(int i=1;i<187;i++)
    {
        int x = (i*i*i)%187;

        if(i<100)
            cout<<" ";

        if(i<10)
            cout<<" ";

        cout<<i<<" ====> "<<x<<"                      ";

        if(x<100)
            cout<<" ";

        if(x<10)
            cout<<" ";

        if(i%8 == 0)
            cout<<endl;
    }
}
    