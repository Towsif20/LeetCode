#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

string convert(string s, int numRows) 
{
    if(numRows == 1 || s.length() < numRows)
        return s;

    string zigzag = "";

    int len = s.length();
    //cout<<len<<endl;
    char ** table = new char*[numRows];

    for(int i=0;i<numRows;i++)
    {
        table[i] = new char[len];
    }

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<len;j++)
        {
            table[i][j] = ' ';
        }
    }

    int row = 0;
    int col = 0;
    int i = 0;

    while(i<len)
    {
        if(row == 0)
        {
            for(int j=0;j<numRows;j++)
            {
                table[row][col] = s[i];
                i++;
                row++;
            }
            continue;
        }

        
        row--;

        for(int j=0;j<numRows-2;j++)
        {
            row--;
            col++;
            
            table[row][col] = s[i];
            i++;
        }

        row = 0;
        col++;
    }

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    int count = 0;
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<len;j++)
        {
            char c = table[i][j];

            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ',' || c == '.')
            {
                zigzag += table[i][j];
                count++;
            }    
        }
    }

    
    //cout<<count<<endl;
    //cout<<zigzag.length()<<endl;

    for(int i=0;i<numRows;i++)
    {
        delete[] table[i];
    }

    delete[] table;
    
    return zigzag;
}

int main()
{   
    cout<<convert("PAYPALISHIRING", 4);

    
}