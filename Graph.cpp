#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int nodes;
    //bool* visited;
    //bool* recStack;
    vector<vector<int>> edges;

    vector<int> indegree;
    vector<int> outdegree;

    public:

    Graph(int n)
    {
        nodes = n;
        //visited = new bool[n];
        //recStack = new bool[n];

        for(int i=0;i<n;i++)
        {
            vector<int> v;
            edges.push_back(v);

            indegree.push_back(0);
            outdegree.push_back(0);

            //visited[i] = false;
            //recStack[i] = false;
        }
    } 

    void addEdge(int u, int v)
    {
        edges[u].push_back(v);

        indegree[v]++;
        outdegree[u]++;
    }


    int findSink()
    {
        for(int i=0;i<nodes;i++)
        {
            if(indegree[i] == nodes-1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
    
    void print()
    {
        for(int u=0;u<nodes;u++)
        {
            cout<<u<<" : ";

            for(int v : edges[u])
            {
                cout<<v<<" ";
            }

            cout<<endl;
        }
    }

    ~Graph()
    {
        //delete visited;
        //delete recStack;
    }
};


int findJudge(int n, vector<vector<int>>& trust)
{
    Graph g(n);

    for(vector<int> v : trust)
    {
        g.addEdge(v[0]-1, v[1]-1);
    }

    g.print();

    //return 1;

    return g.findSink() + 1;
}


int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(0);
    v1.push_back(2);

    v2.push_back(1);
    v2.push_back(2);

    //v3.push_back(2);
    //v3.push_back(0);

    vector<vector<int>> vect;

    vect.push_back(v1);
    vect.push_back(v2);
    //vect.push_back(v3);

    cout<<findJudge(3, vect);

    return 0;
}