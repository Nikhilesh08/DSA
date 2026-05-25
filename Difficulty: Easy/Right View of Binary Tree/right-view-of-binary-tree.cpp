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
    vector<int> rightView(Node *root) {
        //  code here
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node*node=q.front().first;
            int level=q.front().second;
            mpp[level]=node->data;
            q.pop();
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
        
        vector<int>vec;
        for(auto it : mpp){
            vec.push_back(it.second);
        }
        return vec;
        
    }
};