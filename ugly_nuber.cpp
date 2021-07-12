#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

bool isUgly(int n) 
{
    if(n <= 0)
        return false;

    while(n>1)
    {
        if(n%2 == 0)
            n /= 2;

        else if(n%3 == 0)
            n /= 3;

        else if(n%5 == 0)
            n /= 5;

        else
            return false;
    }

    return true;
}

int main()
{   
    cout<<INT_MIN<<endl;
    cout<<INT_MIN/2<<endl;
    cout<<isUgly(-2147483648);
}