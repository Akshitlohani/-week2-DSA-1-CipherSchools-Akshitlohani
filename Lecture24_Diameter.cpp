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

int diameter(TreeNode *root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0,ld=0,rd=0;
    ld =diameter(root->left,&lh); 
    rd =diameter(root->right,&rh);

    *height=max(lh,rh)+1;
    return max(lh,rh+1,max(ld,rd));
}

int main()
{
}