#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int len = matrix.size();

    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            
            int t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
            
        }
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len/2;j++)
        {
            int t = matrix[i][j];
            matrix[i][j] = matrix[i][len-1-j];
            matrix[i][len-1-j] = t;
        }
    }
}

bool equals(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    int len = mat.size();

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(mat[i][j] != target[i][j])
                return false;
        }
    }

    return true;
}


bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    for(int i=0;i<4;i++)
    {
        rotate(mat);

        if(equals(mat, target))
            return true;
    }

    return false;
}

int main()
{   
    
}