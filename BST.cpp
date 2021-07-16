#include<iostream>
#include<math.h>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(root == nullptr)
        return new TreeNode(val);

    TreeNode* temp = root;

    while(true)
    {
        if(temp->val > val)
        {
            if(temp->left == nullptr)
            {
                temp->left = new TreeNode(val);
                break;
            }
            temp = temp->left;
        }
        else if(temp->val < val)
        {
            if(temp->right == nullptr)
            {
                temp->right = new TreeNode(val);
                break;
            }
            temp = temp->right;
        }
        
    }
    return root; 
}

TreeNode* searchBST(TreeNode* root, int val)
{
    TreeNode* temp = root;

    while(temp != nullptr)
    {
        if(temp->val > val)
            temp = temp->left;

        else if(temp->val < val)
            temp = temp->right;

        else if(temp->val == val)
            break;
    }

    return temp;
}


void inorderTraversalUtil(TreeNode* root, vector<int>& order)
{
    if(root == nullptr)
        return;

    inorderTraversalUtil(root->left, order);
    // cout<<root->val<<" ";
    order.push_back(root->val);
    inorderTraversalUtil(root->right, order);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> order;

    inorderTraversalUtil(root, order);

    return order;
}

void preOrderTraversalUtil(TreeNode* root, vector<int>& order)
{
    if(root == nullptr)
        return;

    order.push_back(root->val);
    preOrderTraversalUtil(root->left, order);
    
    preOrderTraversalUtil(root->right, order);
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> order;

    preOrderTraversalUtil(root, order);

    return order;
}


void postOrderTraversalUtil(TreeNode* root, vector<int>& order)
{
    if(root == nullptr)
        return;

    
    postOrderTraversalUtil(root->left, order);
    
    postOrderTraversalUtil(root->right, order);

    order.push_back(root->val);
}

vector<int> postOrderTraversal(TreeNode* root)
{
    vector<int> order;

    postOrderTraversalUtil(root, order);

    return order;
}


int main()
{   
    TreeNode* root = new TreeNode(1);

    //root->val = 5;

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> order = postOrderTraversal(root);

    for(int i : order)
    {
        cout<<i<<" ";
    }

}