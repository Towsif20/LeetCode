#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node() 
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) 
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};


//BFS
Node* cloneGraph(Node* node) 
{
    if(node == nullptr)
        return nullptr;

    queue<Node*> q;
    map<Node*, Node*> m;

    Node* newNode = new Node();
    newNode->val = node->val;

    q.push(node);

    m[node] = newNode;

    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();

        vector<Node*> neighbors = u->neighbors;

        for(Node* v : neighbors)
        {
            if(m[v] == nullptr)
            {
                newNode = new Node();
                newNode->val = v->val;
                m[v] = newNode;
                q.push(v);
            }

            m[u]->neighbors.push_back(m[v]);
        }
    }

    return m[node];
}



int main()
{   
    
}