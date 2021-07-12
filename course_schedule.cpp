#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int nodes;
    bool* visited;
    //bool* recStack;
    vector<vector<int>> edges;

    public:

    Graph(int n)
    {
        nodes = n;
        visited = new bool[n];
        //recStack = new bool[n];

        for(int i=0;i<n;i++)
        {
            vector<int> v;
            edges.push_back(v);

            visited[i] = false;
            //recStack[i] = false;
        }
    } 

    void addEdge(int u, int v)
    {
        edges[u].push_back(v);
    }

    bool hasCycleUtil(int u, bool* recStack)
    {
        //cout<<"u = "<<u<<endl;
        for(int i = 0; i < nodes; i++)
        {
            //cout<<visited[i]<< " ";
        }
        //cout<<endl;

        for(int i = 0; i < nodes; i++)
        {
            //cout<<recStack[i]<< " ";
        }
        //cout<<endl;
        
        
        //cout<<endl;

        if(!visited[u])
        {
            visited[u] = true;
            recStack[u] = true;

            // vector<int>::iterator i;
            // for(i = edges[u].begin(); i != edges[u].end()  ; ++i)
            // {
            //     if(!visited[*i] && hasCycleUtil(*i, recStack))
            //     {
            //          return true;
            //     }
            //     else if(recStack[*i])
            //         return true;

            // }

            for(int i=0;i<edges[u].size();i++)
            {
                if(!visited[edges[u][i]] && hasCycleUtil(edges[u][i], recStack))
                    return true;

                else if(recStack[edges[u][i]])
                    return true;
            }
        }

        recStack[u] = false;

        return false;
    }

    bool hasCycle()
    {
        bool * recStack = new bool[nodes];

        for(int i=0;i<nodes;i++)
        {
            recStack[i] = false;
        }

        for(int u=0;u<nodes;u++)
        {
            if(hasCycleUtil(u, recStack))
                return true;
        }
        return false;
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
        delete visited;
        //delete recStack;
    }
};

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    Graph g(numCourses);

    
    for(vector<int> v : prerequisites)
    {
        g.addEdge(v[0], v[1]);
    }
    

    //g.print();

    return !g.hasCycle();
}

int main()
{   
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(0);

    v2.push_back(0);
    v2.push_back(1);

    vector<vector<int>> vect;
    vect.push_back(v1);
    //vect.push_back(v2);

    cout<<canFinish(2, vect);
}