#include<bits/stdc++.h>

using namespace std;

bool sameDiagonally(vector<vector<int>>& matrix, int start_row, int start_column)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int i = start_row;
    int j = start_column;

    while(i<m && j<n)
    {

        if(matrix[i][j] != matrix[start_row][start_column])
            return false;

        i++;
        j++;
    }

    return true;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    for(int i=0;i<m;i++)
    {
        if(!sameDiagonally(matrix, i, 0))
            return false;
    }

    for(int i=0;i<n;i++)
    {
        if(!sameDiagonally(matrix, 0, i))
            return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}
    };

    vector<vector<int>> matrix2 =
    {
        {1,2},
        {2,2}
    };

    cout<<isToeplitzMatrix(matrix2);
}
    