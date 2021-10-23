#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

bool capital(char c)
{
    return (c >= 'A' && c <= 'Z');
}

char lower(char c)
{
    if (capital(c))
        return c - 'A' + 'a';

    return c;
}

bool alphanumeric(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isPalindrome(string s)
{
    int len = s.size();

    int i = 0, j = len - 1;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        while (!alphanumeric(s[i]) && i < j)
            i++;

        while (!alphanumeric(s[j]) && i < j)
            j--;

        s[i] = tolower(s[i]);
        s[j] = tolower(s[j]);

        if (s[i] != s[j])
            return false;
    }

    return true;
}

bool checkPalindrome(string s, int left, int right)
{
    int len = s.size();

    for (int i = left, j = right; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

bool validPalindrome(string s)
{
    int len = s.size();

    for (int k = 0; k < len; k++)
    {

        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
            }
        }
    }

    return true;
}

string restoreString(string s, vector<int> &indices)
{
    int len = s.size();

    string result = s;

    for (int i = 0; i < len; i++)
    {
        result[indices[i]] = s[i];
    }

    return result;
}

int ceil_divide(int x, int div)
{
    if (x % div == 0)
        return x / div;

    return x / div + 1;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int sum = 0;
    int result = 0;

    int left = 1, right = 1000001;

    while (left <= right)
    {
        sum = 0;

        int mid = left + (right - left) / 2;

        for (int num : nums)
        {
            int x = ceil_divide(num, mid);

            sum += x;
        }

        if (sum > threshold)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            result = mid;
        }
    }

    return result;
}

int main()
{

    cout << validPalindrome("cbccb");

    return 0;
}