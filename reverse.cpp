#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int reverse(int x) 
{
    int rev = 0;

    int max_by_10 = INT_MAX/10;
    int min_by_10 = INT_MIN/10;
    
    while (x)
    {
        int current = x % 10;

        if(rev > max_by_10)
            return 0;

        else if(rev == max_by_10)
        {
            if(current > 7)
                return 0;
        }

        if(rev < min_by_10)
            return 0;

        else if(rev == min_by_10)
        {
            if(current < -8)
                return 0;
        }


        rev = rev * 10 + current;

        x /= 10;

    }

    return rev;     
}

bool isPalindrome(int x)
{
    if(x < 0)
        return false;

    int rev = reverse(x);

    return rev == x;
}

int main()
{   
    cout<<isPalindrome(-121);
}