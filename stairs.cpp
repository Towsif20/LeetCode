#include<bits/stdc++.h>

using namespace std;

int climbStairs(int n)
{
    int count[45];

    count[0] = 1;
    count[1] = 2;

    for(int i=2;i<n;i++)
    {
        count[i] = count[i-1] + count[i-2];
    }

    return count[n-1];
}

int tribonacci(int n)
{
    int count[38];

    count[0] = 0;
    count[1] = 1;
    count[2] = 1;

    for(int i=3;i<=n;i++)
    {
        count[i] = count[i-1] + count[i-2] + count[i-3];
    }

    return count[n];
}

int main()
{
    cout<<tribonacci(25);
}
    