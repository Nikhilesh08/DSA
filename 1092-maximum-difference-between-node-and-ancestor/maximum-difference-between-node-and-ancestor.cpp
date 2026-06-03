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
    void solve(TreeNode*root,vector<int>&ans,int &maxi){
        if(root==NULL) return ;
        if(ans.size()>0){
            for(int i=0;i<ans.size();i++){
                maxi=max(maxi,abs(ans[i]-root->val));
            }
        }
        ans.push_back(root->val);
        solve(root->left,ans,maxi);
        solve(root->right,ans,maxi);
        ans.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN;
        vector<int>ans;
        solve(root,ans,maxi);
        return maxi;
    }
};