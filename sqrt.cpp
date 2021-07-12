#include<bits/stdc++.h>

using namespace std;


int mySqrt(int x)
{
    unsigned int root = 0;
    unsigned int square = 0;

    while(true)
    {
        square = root*root;

        if(square == x)
            return root;

        if(square > x)
        {
            return root-1;
        }
        
        root++;
    }
}


bool isPerfectSquare(int x)
{
    unsigned int root = 0;
    unsigned int square = 0;

    while(true)
    {
        square = root*root;

        if(square == x)
            return true;

        if(square > x)
        {
            return false;
        }
        
        root++;
    }
}


int main()
{
    cout<<mySqrt(pow(2, 31) - 1 )<<endl;
    cout<<isPerfectSquare(2147395600);
}
    