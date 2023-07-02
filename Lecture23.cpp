#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Que 1
int Height_of_tree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(Height_of_tree(root->left),Height_of_tree(root->right));
}



//Que 2
vector<vector<int>> levelOrder(TreeNode* root) {                            // Iterative way
    vector<vector<int>> res;
    if(root==NULL){
        return res;
    }

    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){

        int len = que.size();
        vector<int> temp;
        for(int i=0;i<len;i++){
            TreeNode* node = que.front();
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
            temp.push_back(node->val);
            que.pop();
        }
        res.push_back(temp);
    }
    return res;
}

void levelOrder(TreeNode* root, int level, vector<vector<int>> &res)
{
    if(!root)
        return;
    if(level == res.size())
        res.push_back({root->val});
    else
        res[level].push_back(root->val);
    levelOrder(root->left , level+1, res);
    levelOrder(root->right, level+1, res);
}
vector<vector<int>> levelOrder(TreeNode* root) {                                    //recursive way
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return res;
}

int main() {
    cout<<"Good one."<<endl;
    return 0;
}
