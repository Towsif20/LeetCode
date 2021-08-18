#include<bits/stdc++.h>

using namespace std;

int row, col;

unsigned int findNearestSquareRoot(unsigned int n)
{
    unsigned int root = sqrt(n);

    return root;
}

void findPosition(unsigned int n)
{
    unsigned int root = findNearestSquareRoot(n);

    unsigned int sq = root*root;

    unsigned int diff = n - sq;

    if(diff == 0)
    {
        row = root;
        col = 1;
        return;
    }

    if(diff <= root+1)
    {
        row = diff;
        col = root + 1;
        return;
    }

    if(diff > root + 1)
    {
        row = root + 1;
        col = root + 1 - (diff - (root+1));

        return;
    }
}

int main()
{

    unsigned int t, n;

    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>n;

        findPosition(n);

        cout<<row<<" "<<col<<endl;
    }

    return 0;


}

