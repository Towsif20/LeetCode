#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int romanToInt(string s)
{
    int len = s.length();

    int result = 0;

    for(int i=0;i<len;i++)
    {
        if(s[i] == 'I')
            result += 1;

        else if(s[i] == 'V')
        {
            if(i > 0 && s[i-1] == 'I')
            {
                result += 3;
                continue;
            }

            result += 5;
        }

        else if(s[i] == 'X')
        {

            if(i > 0 && s[i-1] == 'I')
            {
                result += 8;
                continue;
            }

            result += 10;
        }

        else if(s[i] == 'L')
        {
            if(i > 0 && s[i-1] == 'X')
            {
                result += 30;
                continue;
            }

            result += 50;
        }

        else if(s[i] == 'C')
        {
            if(i > 0 && s[i-1] == 'X')
            {
                result += 80;
                continue;
            }

            result += 100;
        }

        else if(s[i] == 'D')
        {
            if(i > 0 && s[i-1] == 'C')
            {
                result += 300;
                continue;
            }

            result += 500;
        }

        else if(s[i] == 'M')
        {
            if(i > 0 && s[i-1] == 'C')
            {
                result += 800;
                continue;
            }

            result += 1000;
        }

    }

    return result;
}

string intToRoman(int num)
{
    vector<string> romanDigits;

    int x = num;

    int div =  1;

    while (x)
    {
        string ch;
        int mod = x % 10;

        if (mod == 0)
        {   
            if(div == 1)
                ch = "X";

            if(div == 10)
                ch = "C";

            if(div == 100)
                ch = "M";
        }
        

        int multiple = mod * div;

        // cout<<"div = "<<div<<endl;
        // cout<<"multiple = "<<multiple<<endl;

        if (multiple <=3 )
        {
            ch = "";
            for(int i=0;i<mod;i++)
            {
                ch += "I";
            }
        }
        else if(multiple == 4)
        {
            ch = "IV";
        }
        else if(multiple <= 8)
        {
            ch = "V";
            for(int i=0;i<mod-5;i++)
            { 
                ch += "I";
            }
        }
        else if(multiple == 9)
        {
            ch = "IX";
        }
        

        else if (multiple <=30 )
        {
            ch = "";
            for(int i=0;i<mod;i++)
            {
                ch += "X";
            }
        }
        else if(multiple == 40)
        {
            ch = "XL";
        }
        else if(multiple <= 80)
        {
            ch = "L";
            for(int i=0;i<mod-5;i++)
            { 
                ch += "X";
            }
        }
        else if(multiple == 90)
        {
            ch = "XC";
        }


        else if (multiple <=300 )
        {
            ch = "";
            for(int i=0;i<mod;i++)
            {
                ch += "C";
            }
        }
        else if(multiple == 400)
        {
            ch = "CD";
        }
        else if(multiple <= 800)
        {
            ch = "D";
            for(int i=0;i<mod-5;i++)
            { 
                ch += "C";
            }
        }
        else if(multiple == 900)
        {
            ch = "CM";
        }
        
        else if (multiple <=3000 )
        {
            ch = "";
            for(int i=0;i<mod;i++)
            {
                ch += "M";
            }
        }

        div *= 10;
        x /= 10;

        romanDigits.push_back(ch);
    }
    

    string roman = "";

    for(int i=romanDigits.size()-1;i>=0;i--)
    {
        roman += romanDigits[i];
    }

    return roman;  
}

int main()
{   
    cout<<intToRoman(3562);
}