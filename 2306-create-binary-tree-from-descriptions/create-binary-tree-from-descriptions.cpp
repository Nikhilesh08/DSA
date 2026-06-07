/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_map<int,int>parent;
        int n=descriptions.size();
        for(int i=0;i<n;i++){
            int root_val=descriptions[i][0];
            int child_val=descriptions[i][1];
            bool isLeft=descriptions[i][2];
            if(mpp.find(root_val)==mpp.end()){
                TreeNode*node=new TreeNode(root_val);
                mpp[root_val]=node;
            }
            if(mpp.find(child_val)==mpp.end()){
                    TreeNode*node=new TreeNode(child_val);
                    mpp[child_val]=node;
            }
            if(isLeft)mpp[root_val]->left=mpp[child_val];
            else mpp[root_val]->right=mpp[child_val];
            parent[child_val]=root_val;
            
        }
        // finding the ultimate parent
        int child_val=descriptions[0][1];
        while(parent.find(child_val)!=parent.end()){
            child_val=parent[child_val];
        }
        return mpp[child_val];
    }
};