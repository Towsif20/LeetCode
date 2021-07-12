#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

string multiply(string num1, string num2) 
{
    if(num1 == "0" || num2 == "0")
        return "0";
        
    string ans = "";

    int len1 = num1.length();
    int len2 = num2.length();

    vector<vector<int>> prod;


    for(int i=len2-1;i>=0;i--)
    {
        int p2 = num2[i] - '0';
        int div = 0;
        int mod = 0;

        vector<int> temp;

        for(int j=0;j<len2-i-1;j++)
        {
            temp.push_back(0);
        }

        for(int j=len1-1;j>=0;j--)
        {
            int p1 = num1[j] - '0';

            int mult = p1*p2 + div;

            mod = mult%10;

            //mult = mod + '0';

            div = mult/10;

            temp.push_back(mod);
            
            //cout<<mod<<" ";
        }

        temp.push_back(div);

        for(int j=0;j<i;j++)
        {
            temp.push_back(0);
        }

        prod.push_back(temp);
        
        //cout<<endl;
        // for(int j: temp)
        // {
        //     cout<<j<<" ";
        // }
        // cout<<endl;

    }

    int sum = 0;

    len1 = prod[0].size();

    int div = 0;
    int mod = 0;

    vector<char> result;

    for(int i=0;i<len1;i++)
    {
        int sum = 0;

        for(int j=0;j<len2;j++)
        {
            //cout<<prod[j][i]<<" ";
            sum += prod[j][i];
        }

        sum += div;

        mod = sum%10;
        div = sum/10;

        //cout<<mod;
        result.push_back(mod + '0');

        //cout<<endl;
    }

    //cout<<endl;

    int len = result.size();

    bool flag = false;

    for(int i=len-1;i>=0;i--)
    {
        if(!flag && result[i] == '0')
        {
            continue;
        }

        if(result[i] != '0')
            flag = true;

        ans += result[i];
    }

    return ans;
}


int main()
{   
    //cout<<123*24<<endl;
    //cout<<multiply("123","456");
    string num1 = "498828660196";
    string num2 = "840477629533";

    cout<<multiply(num1, num2);
}