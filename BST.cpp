#include<iostream>
#include<math.h>
#include<vector>

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

int main()
{   
    TreeNode* root;

    root->val = 5;


}