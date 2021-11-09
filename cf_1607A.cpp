#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    string alphabet, s;

    int index[26];

    for (int test = 0; test < t; test++)
    {
        cin >> alphabet;
        cin >> s;

        for (int i = 0; i < 26; i++)
        {
            index[alphabet[i] - 'a'] = i;
        }

        int sum = 0;

        int len = s.length();

        for (int i = 1; i < len; i++)
        {
            sum += (abs(index[s[i] - 'a'] - index[s[i - 1] - 'a']));
        }

        cout << sum << endl;
    }
}
