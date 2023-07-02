#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    inorder(root->left);
    result.push_back(root->val); // add the current node's value to our
    inorder(root->right);        // traversal list and then recursively traverse its children
}
vector<int> inorder(TreeNode *root)
{
    vector<int> result;    // initialize an empty array of integers as output
    inorder(root, result); // call helper function with initial parameters (the input subtree
    return result;
}

vector<int> preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return ();
    }
    vector<int> result;
    stack<TreeNode *> S;
    TreeNode temp = root;
    while (true)
    {
        while (temp != NULL)
        {
            result.push_back(temp->val);
            S.push(temp);
            temp = temp->left:
        }
        if (S.empty())
        {
            break;
        }
        temps.top();
        S.pop();
        temp temp->right;
    }
    return result;
}

vector<int> inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> result;
    stack<TreeNode *> S;
    TreeNode *temp = root;
    while (true)
    {
        while (temp != NULL)
        {
            S.push(temp);
            temp = temp->left;
            C if (S.empty())
            {
                break;
            }
            temp = S.top();
            S.pop();
            temp = temp->right;
        }
        return result;
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + max(height(root->left), height(root->right)));
    }
}

void printGivenLevel(TreeNode root, int level, vector<int> &levelH)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        levelH.push_back(root->val);
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1, levelH);
        printGivenLevel(root->right, level - 1, levelH);
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> levelOrder;
    int H = height(root);
    for (int h = 0; h <= H; h++)
    {
        vector<int> levelH;
        printGivenLevel(root, h, levelH);
        levelOrder.push_back(levelH);
    }
    return levelOrder;
}

vector<int> levelOrderIterative(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> result;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();
        result.push_back(root->val);
        if (root->left != NULL)
            Q.push(root->left);
        if (root->right != NULL)
            Q.push(root->right);
    }
    return result;
}

vector<vector<int>> levelOrderLineByLineIterative(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> result;
    vector<int> currLevel;
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();
        if (root == NULL)
        {
            result.push_back(currLevel);
            currLevel.clear();
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            currLevel.push_back(root->val);
            if (root->left != NULL)
                Q.push(root->left);
            if (root->right != NULL)
                Q.push(root->right);
        }
    }
    return result;
}

int main()
{
}