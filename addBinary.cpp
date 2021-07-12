#include<bits/stdc++.h>

using namespace std;


string addBinary(string a, string b)
{
    string result = "";

    int len1 = a.size();
    int len2 = b.size();

    cout<<"len1 = "<<len1<<endl;
    cout<<"len2 = "<<len2<<endl;
    

    if(len1 < len2)
    {
        int len = len2 - len1;

        for(int i=0;i<len;i++)
        {
            //cout<<a<<endl;
            a = "0" + a;
            len1++;
        }
    }
    else
    {
        int len = len1 - len2;

        for(int i=0;i<len;i++)
        {
            b = "0" + b;
            len2++;
        }
    }

    //cout<<a<<endl;
    //cout<<b<<endl;

    int sum = 0;
    int carry = 0;

    for(int i=len1-1;i>=0;i--)
    {
        int first = a[i] - '0';
        int second = b[i] - '0';

        sum = first + second + carry;

        carry = sum/2;
        sum = sum%2;

        //cout<<carry<<" "<<sum<<endl;

        char c = sum + '0';
        result = c + result;
    }

    if(carry == 1)
        result = "1" + result;

    return result;
}



int main()
{
    cout<<addBinary("1", "111");
}
    