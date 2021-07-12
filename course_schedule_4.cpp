#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int nodes;
    bool* taken;

    vector<vector<int>> adjacencyList;

    public:

    Graph(int n)
    {
        nodes = n;

        taken = new bool[nodes];

        for(int i=0;i<nodes;i++)
        {
            taken[i] = false;

            vector<int> v;
            adjacencyList.push_back(v);
        }
    }

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    bool reachable(int source, int dest)
    {
        if(source == dest)
            return true;

        for(int i=0;i<nodes;i++)
        {
            taken[i] = false;
        }

        queue<int> q;

        taken[source] = true;

        q.push(source);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int i=0;i<adjacencyList[u].size();i++)
            {
                int v = adjacencyList[u][i];

                if(v == dest)
                    return true;

                if(!taken[v])
                {
                    taken[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }

    void print()
    {
        for(int u=0;u<nodes;u++)
        {
            cout<<u<<" : ";

            cout<<endl;
        }
    }

    ~Graph()
    {
        delete[] taken;
    }
};

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
{
    vector<bool> reachability;

    Graph g(numCourses);

    
    for(vector<int> v : prerequisites)
    {
        g.addEdge(v[0], v[1]);
    }
    
    for(vector<int> v : queries)
    {
        bool reach = g.reachable(v[0], v[1]);
        //cout<<reach<<" ";
        reachability.push_back(reach);
    }

    return reachability;
}

int main()
{   
    vector<int> v1;
    vector<int> v2;
    //vector<int> v3;
    //vector<int> v4;

    v1.push_back(1);
    v1.push_back(0);

    v2.push_back(0);
    v2.push_back(1);

    // v3.push_back(3);
    // v3.push_back(1);

    // v4.push_back(3);
    // v4.push_back(2);

    vector<vector<int>> vect;
    vector<vector<int>> queries;

    vect.push_back(v1);

    queries.push_back(v2);
    queries.push_back(v1);
    //vect.push_back(v2);
    // vect.push_back(v3);
    // vect.push_back(v4);
    
    checkIfPrerequisite(2, vect, queries);
}