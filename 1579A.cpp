#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int A, B, C;

    string s;

    for (int k = 0; k < t; k++)
    {
        A = B = C = 0;

        cin >> s;

        int len = s.length();

        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'A')
                A++;

            else if (s[i] == 'B')
                B++;

            else
                C++;
        }

        if (A + C == B)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}