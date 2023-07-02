#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

//Que 1
int Height_of_tree(Node* root){
    if(root == NULL){
        return 0;
    }

    int lheight = Height_of_tree(root->left);
    int rheight = Height_of_tree(root->right);
    return max(lheight,rheight) +1;

}

int Diameter_of_tree(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = Height_of_tree(root->left);
    int rheight = Height_of_tree(root->right);
    int curdia = lheight+rheight+1;

    int ldiameter = Diameter_of_tree(root->left);
    int rdiameter = Diameter_of_tree(root->right);
    return max(curdia,max(ldiameter,rdiameter));
}

int Diameter_of_tree_optimal(Node* root,int* height){
    if(root==NULL){
        *height = 0;
        return 0;
    }

    int lh =0,rh =0;
    int ldiameter = Diameter_of_tree_optimal(root->left,&lh);
    int rdiameter = Diameter_of_tree_optimal(root->right,&rh);

    int curdia = lh+rh+1;
    *height = max(lh,rh)+1;
    return max(curdia,max(ldiameter,rdiameter));
}



//Que 2
void vot(Node* root,int hd,map<int,vector<int>> &mp){
    if(root==NULL){
        return;
    }
    mp[hd].push_back(root->data);
    vot(root->left,hd-1,mp);
    vot(root->right,hd+1,mp);
}

vector<vector<int>> verticalTraversal(Node* root) {
    map<int,vector<int>> mp;
    vector<vector<int>> res;
    vector<int> topview;
    vector<int> bottomview;
    vot(root,0,mp);

    for(auto keyval : mp){
        vector<int> temp = keyval.second;
        topview.push_back(temp.front());
        bottomview.push_back(temp.back());
        sort(temp.begin(),temp.end());
        res.push_back(temp);
    }

    for(auto i:topview){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:bottomview){
        cout<<i<<" ";
    }
    cout<<endl;
    return res;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(10);
    int height = Height_of_tree(root);
    cout<<height<<endl;

    int diameter1 = Diameter_of_tree(root);
    cout<<diameter1<<endl;

    int diameter2 = Diameter_of_tree_optimal(root,0);
    cout<<diameter2<<endl;
    return 0;
}
