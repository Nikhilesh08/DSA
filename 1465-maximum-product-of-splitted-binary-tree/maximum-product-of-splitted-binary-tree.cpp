class Solution {
public:
    long long find(TreeNode* root) {
        if (root == NULL) return 0;
        return (long long)root->val + find(root->left) + find(root->right);
    }

    long long solve(TreeNode* root, long long &maxi, long long tot) {
        if (root == NULL) return 0;

        long long left = solve(root->left, maxi, tot);
        long long right = solve(root->right, maxi, tot);

        long long subTreeSum = root->val + left + right;
        maxi = max(maxi, subTreeSum * (tot - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        long long maxi = 0;
        long long tot = find(root);
        solve(root, maxi, tot);
        int MOD = 1e9 + 7; 
        return maxi % MOD; 
    }
};