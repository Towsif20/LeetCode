#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int nodes;
    int** matrix;
    int* outDegree;
    bool* taken;

    public:

    Graph(int n)
    {
        nodes = n;

        matrix = new int*[nodes];

        for(int i=0;i<nodes;i++)
        {
            matrix[i] = new int[nodes];
        }

        outDegree = new int[nodes];
        taken = new bool[nodes];

        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                matrix[i][j] = 0;
            }

            outDegree[i] = 0;
            taken[i] = false;
        }
    } 

    void addEdge(int u, int v)
    {
        if(matrix[u][v] == 0)
        {
            matrix[u][v] = 1;
            outDegree[u]++;
        }
    }

    void removeEdge(int u, int v)
    {
        if(matrix[u][v] == 1)
        {
            matrix[u][v] = 0;
            outDegree[u]--;
        }
    }

    void removeNode(int v)
    {
        for(int u=0;u<nodes;u++)
        {
            removeEdge(u, v);
            removeEdge(v, u);
        }

        taken[v] = true;
    }

    int findZeroOutDegNode()
    {
        int v = -1;

        for(int u=0;u<nodes;u++)
        {
            if(outDegree[u] == 0 && !taken[u])
            {
                v = u;
                break;
            }
        }

        return v;
    }

    vector<int> findOrder()
    {
        vector<int> order;

        for(int u=0;u<nodes;u++)
        {
            int v = findZeroOutDegNode();

            if(v == -1)
            {
                order.clear();
                return order;
            }

            removeNode(v);
            taken[v] = true;

            cout<<v<<" ";

            order.push_back(v);

        }


        cout<<endl;
        return order;
    }

    void print()
    {
        for(int u=0;u<nodes;u++)
        {
            cout<<u<<" : ";

            for(int v=0;v<nodes;v++)
            {
                cout<<matrix[u][v]<<" ";
            }

            cout<<endl;
        }
    }

    ~Graph()
    {
        for(int i=0;i<nodes;i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] taken;
    }
};

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    //vector<int> order;
    
    Graph g(numCourses);

    for(vector<int> v : prerequisites)
    {
        g.addEdge(v[0], v[1]);
    }

    //cout<<g.findZeroOutDegNode();

    return g.findOrder();;
}

int main()
{   
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    v1.push_back(1);
    v1.push_back(0);

    v2.push_back(0);
    v2.push_back(1);

    // v3.push_back(3);
    // v3.push_back(1);

    // v4.push_back(3);
    // v4.push_back(2);

    vector<vector<int>> vect;

    vect.push_back(v1);
    vect.push_back(v2);
    // vect.push_back(v3);
    // vect.push_back(v4);

    findOrder(2, vect);

}