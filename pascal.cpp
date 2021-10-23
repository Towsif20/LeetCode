#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal;

    for(int i=0;i<numRows;i++)
    {
        vector<int> row_i(i+1);

        row_i[0] = 1;

        for(int j=1;j<i;j++)
        {
            row_i[j] = pascal[i-1][j-1] + pascal[i-1][j];
        }

        row_i[i] = 1;

        pascal.push_back(row_i);
    }

    return pascal;
}

double n_C_r(int n, int r)
{
    if(r == 0)
        return 1;

    if(r == n)
        return n;

    if(n < r)
        return 0;

    
    return (n/r) * n_C_r(n-1, r-1);
}


vector<int> getRow(int rowIndex)
{
    vector<int> row;



    return row;
}


int main()
{
    vector<vector<int>> pascal = generate(7);

    for(vector<int> v : pascal)
    {
        for(int i : v)
        {
            cout<<i<<" ";
        }

        cout<<endl;
    }

    return 0;

    cout<<(n_C_r(5,2));
}