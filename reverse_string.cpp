#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

string reverseWords(string s)
{
    string result = "";

    bool last = true;

    string temp = "";

    for (char c : s)
    {
        if (c != ' ')
        {
            temp += c;
            continue;
        }

        if (temp != "")
        {
            if (last)
            {
                result = temp + result;
                last = false;
            }
            else
            {
                result = temp + " " + result;
            }

            temp = "";
        }

        //cout << result << endl;
    }

    if (temp != "")
    {
        if (last)
        {
            result = temp + result;
            last = false;
        }
        else
        {
            result = temp + " " + result;
        }

        temp = "";
    }

    return result;
}

int main()
{
    cout << reverseWords("the sky    is    blue");
}