// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    return a.second > b.second;
}

string sort(map<char, int> &M)
{

    vector<pair<char, int>> A;

    for (auto &it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    //M.clear();

    string result = "";

    for (auto &it : A)
    {
        //cout << it.first << ' ' << it.second << endl;
        int count = (int)it.second;
        //cout << count << endl;
        for (int i = 0; i < count; i++)
        {
            result += (char)it.first;
        }
    }

    return result;
}

string frequencySort(string s)
{
    map<char, int> M;

    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;

        M[c] = 0;

        c = 'a' + i;

        M[c] = 0;
    }

    for (char c : s)
    {
        M[c]++;
    }

    // Function Call
    //sort(M);

    return sort(M);
}

int main()
{
    cout << frequencySort("aabcccc");
    return 0;
}
