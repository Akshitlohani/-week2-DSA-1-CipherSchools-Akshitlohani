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


// Q3(Construct Binnary Tree form Inorder &preorder | Inorder & postorder)
int find(vector<int> inOrder, int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == x)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *buildTree(const vector<int> &preOrder, const vector<int> &inOrder, int start, int end, int &curr)
{
    if (start > end)
        return NULL;
    TreeNode *newNode = new TreeNode(preOrder[curr]);
    curr++;
    if (start == end)
        return newNode;
    else
    {
        int idx = find(inOrder, start, end, newNode->val);
        newNode->left = buildTree(preOrder, inOrder, start, idx - 1, curr);
        newNode->right = buildTree(preOrder, inOrder, idx + 1, end, curr);
    }
    return newNode;
}

TreeNode *buildTree(const vector<int> &preOrder, const vector<int> &inOrder)
{
    int curr = 0;
    return buildTree(preOrder, inOrder, 0, inOrder.size() - 1, curr);
}





// Q4(root to leaf problem)
bool isLeaf(TreeNode *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}
void rootToLeafPath(TreeNode *root, vector<vector<int>> &paths, vector<int> &pathSoFar)
{
    if (root == NULL)
        return;
    pathSoFar.push_back(root->val);
    if (isLeaf(root))
    {
        paths.push_back(pathSoFar);
        return;
    }
    else
    {
        rootToLeafPath(root->left, paths, pathSoFar);
        rootToLeafPath(root->right, paths, pathSoFar);
    }
    pathSoFar.pop_back();
}
vector<vector<int>> rootToLeaf(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> paths;
    vector<int> pathSoFar;

    rootToLeafPath(root, paths, pathSoFar);
    return paths;
}




// Q5 populate next pointer
void populateRandomPointer(TreeNode *root)
{
    if (root == NULL || isLeaf)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *prev;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == 0)
            {
                prev = root;
            }
            else
            {
                prev->random = root;
                prev = root;
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
}


int main(){

}