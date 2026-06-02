class Solution {
public:
    void solve(TreeNode* root, int sum, vector<int>& ds, vector<vector<int>>& ans) {
        if (!root) return;

        ds.push_back(root->val);
        
        if (!root->left && !root->right && sum == root->val) {
            ans.push_back(ds);
        } else {
            solve(root->left, sum - root->val, ds, ans);
            solve(root->right, sum - root->val, ds, ans);
        }
        ds.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root, targetSum, ds, ans);
        return ans;
    }
};