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

int find(vector<int> &preorder, int start, int end, int x)
{
    int index = start;
    while (index <= end && preorder[index] < x)
    {
        index++;
    }
    return index;
}


TreeNode *buildTree1(vector<int> &sortedArr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *newNode = new TreeNode(sortedArr[start]);
    newNode->left = buildTree1(sortedArr, start + 1, index - 1);
    newNode->right = buildTree2(sortedArr, index, end);
    return newNode;
}

TreeNode *leastCommonAncestors(TreeNode *root, const int &l, const &r)
{
    if (root == NULL)
        return NULL;
    if (root->val < 1)
        return leastCommonAncestors(root->right, l, r);
    else if (root->val > r)
        return leastCommonAncestors(root->left, l, r);
    else
        return root;
}

int main(){
    
}