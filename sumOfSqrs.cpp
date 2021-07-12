#include<bits/stdc++.h>

using namespace std;


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


//  using fermat's theorem

// bool judgeSquareSum(int n)
// {
//     if(isPerfectSquare(n-1))
//         return true;

//     map<int, int> factors;

//     while(n%2 == 0)
//     {
//         //cout<<2<<" ";
//         //factors[2]++;
//         n /= 2;
//     }

//     int root = sqrt(n);

//     for(int i=3;i<=root;i+=2)
//     {
//         while(n%i == 0)
//         {
//             //cout<<i<<" ";
//             factors[i]++;

//             n /= i;
//         }
//     }

//     if(n > 2)
//     {
//         //cout<<n;
//         factors[n]++;
//     }
//     //cout<<endl;

//     map<int,int>::iterator itr;

//     for(itr=factors.begin(); itr!=factors.end(); itr++)
//     {
//         //cout<<itr->first<<" "<<itr->second<<endl;
//         if((itr->second)%2 == 1)
//             return false;
//     }

//     return true;
// }

bool judgeSquareSum(int n)
{
    if(n == 0)
        return true;
        
    map<unsigned int, int> m;

    unsigned int square = 0;

    for(unsigned int i=1;i*i<=n;i++)
    {
        square = i*i;
        m[square] = 1;

        if(square == n)
            return true;

        if(m.find(n-square) != m.end())
            return true;
    }

    return false;
}

int main()
{
    cout<<judgeSquareSum(2147395600);
}
    