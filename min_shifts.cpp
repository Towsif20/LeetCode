#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

vector<int> minOperations(string boxes)
{
    int n = boxes.size();

    vector<int> answers;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            int c = boxes[j] - '0';

            if (c == 1)
                sum += abs(j - i);
        }

        answers.push_back(sum);
    }

    return answers;
}

int main()
{

    return 0;
}