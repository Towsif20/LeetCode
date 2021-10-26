#include <iostream>
#include <math.h>
#include <vector>
#include <stack>

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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    TreeNode *temp = root;

    while (true)
    {
        if (temp->val > val)
        {
            if (temp->left == nullptr)
            {
                temp->left = new TreeNode(val);
                break;
            }
            temp = temp->left;
        }
        else if (temp->val < val)
        {
            if (temp->right == nullptr)
            {
                temp->right = new TreeNode(val);
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}

TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->val > val)
            temp = temp->left;

        else if (temp->val < val)
            temp = temp->right;

        else if (temp->val == val)
            break;
    }

    return temp;
}

void inorderTraversalUtil(TreeNode *root, vector<int> &order)
{
    if (root == nullptr)
        return;

    inorderTraversalUtil(root->left, order);
    // cout<<root->val<<" ";
    order.push_back(root->val);
    inorderTraversalUtil(root->right, order);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> order;

    inorderTraversalUtil(root, order);

    return order;
}

void preOrderTraversalUtil(TreeNode *root, vector<int> &order)
{
    if (root == nullptr)
        return;

    order.push_back(root->val);
    preOrderTraversalUtil(root->left, order);

    preOrderTraversalUtil(root->right, order);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> order;

    preOrderTraversalUtil(root, order);

    return order;
}

void flatten(TreeNode *root)
{
    vector<int> preorder = preorderTraversal(root);

    TreeNode *t = root;

    for (int i = 0; i < preorder.size(); i++)
    {
        if (i == 0)
        {
            t = root;
        }
        else
        {
            if (t->left != nullptr)
            {
                delete t->left;
            }

            if (t->right == nullptr)
            {
                t->right = new TreeNode(preorder[i]);
                t = t->right;
            }
            else
            {
                t->right->val = preorder[i];
                t = t->right;
            }
        }
    }
}

void postOrderTraversalUtil(TreeNode *root, vector<int> &order)
{
    if (root == nullptr)
        return;

    postOrderTraversalUtil(root->left, order);

    postOrderTraversalUtil(root->right, order);

    order.push_back(root->val);
}

vector<int> postOrderTraversal(TreeNode *root)
{
    vector<int> order;

    postOrderTraversalUtil(root, order);

    return order;
}

void leverOrderUtil(TreeNode *root, int level, vector<vector<int>> &order)
{
    if (root == nullptr)
        return;

    if (order.size() == level)
    {
        vector<int> v;
        order.push_back(v);
    }

    order[level].push_back(root->val);

    leverOrderUtil(root->left, level + 1, order);
    leverOrderUtil(root->right, level + 1, order);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> order;

    leverOrderUtil(root, 0, order);

    return order;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        return false;

    if (p == nullptr && q == nullptr)
        return true;

    if (p->val == q->val)
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    return false;
}

int maxOfSubTree(TreeNode *root, int currentMax)
{
    if (root == nullptr)
        return currentMax;

    if (root->val > currentMax)
        currentMax = root->val;

    int a = maxOfSubTree(root->left, currentMax);
    int b = maxOfSubTree(root->right, currentMax);

    if (a > b)
        return a;

    return b;
}

int minOfSubTree(TreeNode *root, int currentMin)
{
    if (root == nullptr)
        return currentMin;

    if (root->val < currentMin)
        currentMin = root->val;

    int a = minOfSubTree(root->left, currentMin);
    int b = minOfSubTree(root->right, currentMin);

    if (a < b)
        return a;

    return b;
}

int maxAncestorDiff(TreeNode *root)
{
    int rightMax = maxOfSubTree(root->right, root->val);
    int rightMin = minOfSubTree(root->right, root->val);

    int leftMax = maxOfSubTree(root->left, root->val);
    int leftMin = minOfSubTree(root->left, root->val);

    int a = (rightMax - rightMin);
    int b = (leftMax - leftMin);

    if (a > b)
        return a;

    return b;
}

int getLevel(TreeNode *root, int x, int level)
{

    if (root == NULL)
        return -1;

    if (root->val == x)
        return level;

    int left = getLevel(root->left, x, level + 1);

    if (left != -1)
        return left;

    int right = getLevel(root->right, x, level + 1);

    return right;
}

int findParent(TreeNode *root, int x, int parent)
{
    if (root == nullptr)
        return -1;

    if (root->val == x)
        return parent;

    int left = findParent(root->left, x, root->val);

    if (left != -1)
        return left;

    int right = findParent(root->right, x, root->val);

    return right;
}

bool isCousins(TreeNode *root, int x, int y)
{
    int levelX = getLevel(root, x, 0);
    int levelY = getLevel(root, y, 0);

    if (levelX != levelY)
        return false;

    int ParentX = findParent(root, x, -1);
    int ParentY = findParent(root, y, -1);

    if (ParentX == ParentY)
        return false;

    return true;
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    swap(root->left, root->right);

    return root;
}



int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(1);

    root1->left = new TreeNode(2);
    root2->left = new TreeNode(2);

    root1->right = new TreeNode(3);
    root2->right = new TreeNode(3);

    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    // root1->right->right->left = new TreeNode(3);

    cout << isCousins(root1, 4, 5);

    // cout<<parent->val<<endl;

    // cout<<isSameTree(root1, root2);

    // cout<<maxAncestorDiff(root1);

    // root->val = 5;

    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);

    // vector<int> order = postOrderTraversal(root);

    // for(int i : order)
    // {
    //     cout<<i<<" ";
    // }
}