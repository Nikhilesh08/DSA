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
    string solve(TreeNode*root,unordered_map<string,int>&mpp,vector<TreeNode*>&ans){
        if(root==NULL) return "N";
        string s=to_string(root->val)+","+solve(root->left,mpp,ans)+","+solve(root->right,mpp,ans);
        if(mpp[s]==1){
            ans.push_back(root);
        }
        mpp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>mpp;
        solve(root,mpp,ans);
        return ans;
    }
};