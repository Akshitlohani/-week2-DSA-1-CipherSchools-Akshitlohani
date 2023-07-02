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

// Q1(root to leaf max sum)
bool isLeaf(TreeNode *root){
    return (root!=NULL && root->left==NULL && root->right==NULL);
}

void maxSumPath(TreeNode* root, int sum,int &maxSum){
    if(root==NULL)  return;
    sum+=root->val;
    if(isLeaf(root)){
        maxSum=max(maxSum,sum);
        return ;   
    }
    else{
        maxSumPath(root->left,sum,maxSum);     
        maxSumPath(root->right,sum,maxSum);
    }
}
int maxPath(TreeNode* root){
    int maxSum=0;
    maxPath(root,0,maxSum);
    return maxSum;  
}

// Q2(Max sum path problem) leaf to leaf
int leafToleaf(TreeNode* root, int *sum){
    if(root==NULL){
        *sum=0;
        return 0;
    }
    if(isLeaf(root)){
        *sum=0;
        return root->val;      
    }
    int lSum=0, rSum=0;
    lSum=leafToLeafMaxSum(root->left,ltrSum);
    rSum=leafToLeafMaxSum(root->right,rtlSum);
    if(root->left !=NULL && root->right!=NULL){
        *ltrSum=max(*ltrSum,root->val,lSum,rSum);
        return max(lSum,rSum)+root->val;
    }
    else if(root->left!=NULL){
        return root->val + lSum;
    }
    else{
        return root->val + rSum;
    }
}


int main(){
    
}