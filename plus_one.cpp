#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> v;

    int len = digits.size();

    int sum = 0;
    int carry = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        sum = digits[i] + carry;
        carry = sum / 10;
        sum %= 10;

        v.push_back(sum);
    }

    if (carry > 0)
    {
        v.push_back(carry);
    }

    len = v.size();

    for (int i = 0; i < len / 2; i++)
    {
        int j = len - 1 - i;

        int t = v[i];
        v[i] = v[j];
        v[j] = t;
    }

    return v;
}

int main()
{
    vector<int> digits{4, 3, 2, 1};

    vector<int> v = plusOne(digits);

    for (int i : v)
    {
        cout << i;
    }
    cout << endl;
}
