#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    int64_t position, steps;

    for (int test = 0; test < t; test++)
    {
        cin >> position;
        cin >> steps;

        for (int i = 1; i <= steps; i++)
        {
            if (position % 2 == 0)
                position -= i;

            else
                position += i;
        }

        cout << position << endl
             << endl;
        ;
    }
}
