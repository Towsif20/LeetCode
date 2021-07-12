#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int sq_sum(int n)
{
    int sum = 0;
    
    while(n)
    {
        int mod = n%10;
        sum += (mod*mod);

        n /= 10;
    }

    return sum;
}

bool isHappy(int n) 
{
    n = sq_sum(n);
    int loop = n;
    bool inside_while = false;

    while(true)
    {
        if(inside_while && n == loop)
            return false;
        
        if(!inside_while)
            inside_while = true;

        if(n == 1)
            return true;

        n = sq_sum(n);
    }
}

int main()
{   
    cout<<isHappy(7);
}