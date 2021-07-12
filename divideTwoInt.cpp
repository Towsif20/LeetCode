#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int divide(int dividend, int divisor)
{
    if(dividend == -2147483648 && divisor == -1)
    {
        return 2147483647;
    }

    if(dividend == 0)
        return 0;

    bool flag = false;
    bool flag2 = false;

    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
    {
        flag = true;
        divisor = -divisor;
    }

    if((dividend<0 && divisor<0))
    {
        flag2 = true;
    }

    int count = 0;
    int prod = divisor;

    if(flag2)
    {
        while(prod >= dividend)
        {
            if(INT_MIN - divisor > prod)
            {
                unsigned int res = -count;
                res--;

                count = -res;
                return count;
            }
            prod += divisor;
            count++;
        }
    }
    else
    {
        while(prod <= dividend)
        {
            if(INT_MAX - divisor < prod)
            {
                unsigned int res = count;
                res++;

                if(flag)
                    return -res;

                return res;
            }
            prod += divisor;
            count++;
        }
    }

    

    if(flag)
        count = -count;

    
    return count;
}


int main()
{   
    int x = 2147483648;
    cout<<x<<endl;
    cout<<divide(-2147483648, -2)<<endl;
    //cout<<-2147483648/-1;
}