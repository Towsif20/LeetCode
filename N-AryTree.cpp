#include<bits/stdc++.h>

using namespace std;


class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void postOrderUtil(Node* root, vector<int>& order)
{
    if(root == nullptr)
        return;

    for(Node *n : root->children)
    {
        postOrderUtil(n, order);
    }

    order.push_back(root->val);
}

vector<int> postorder(Node* root)
{
    vector<int> order;

    postOrderUtil(root, order);

    return order;
}


void preOrderUtil(Node* root, vector<int>& order)
{
    if(root == nullptr)
        return;

    order.push_back(root->val);

    for(Node *n : root->children)
    {
        preOrderUtil(n, order);
    }

    
}

vector<int> preorder(Node* root)
{
    vector<int> order;

    preOrderUtil(root, order);

    return order;
}




void leverOrderUtil(Node* root, int level, vector<vector<int>>& order)
{
    if(root == nullptr)
        return;


    if(order.size() == level)
    {
        vector<int> v;
        order.push_back(v);
    }

    order[level].push_back(root->val);

    for(Node* child : root->children)
    {
        leverOrderUtil(child, level+1, order);
    }
}


vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> order;


    leverOrderUtil(root, 0, order);


    return order;
}



int main()
{
    return 0;


}

