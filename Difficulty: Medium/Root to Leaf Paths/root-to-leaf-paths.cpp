/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node*root){
        if(root->right==NULL && root->left==NULL) return true;
        return false;
    }
    void solve(Node*root,vector<vector<int>>&ans,vector<int>&ds){
        if(root==nullptr) return ;
        ds.push_back(root->data);
        if(isLeaf(root)){
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }
        solve(root->left,ans,ds);
        solve(root->right,ans,ds);
        ds.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>ds;
        solve(root,ans,ds);
        return ans;
    }
};