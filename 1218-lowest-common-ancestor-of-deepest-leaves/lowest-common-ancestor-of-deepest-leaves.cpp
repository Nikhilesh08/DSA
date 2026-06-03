class Solution {
public:
    int solve(TreeNode* root, TreeNode*& ans, int depth, int& maxdepth) {
        if (root == NULL) {
            return depth;
        }
        int left = solve(root->left, ans, depth + 1, maxdepth);
        int right = solve(root->right, ans, depth + 1, maxdepth);
        
        if (left == right && left >= maxdepth) {
            maxdepth = left;
            ans = root;
        }
        return max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = NULL;
        int maxdepth = 0;
        solve(root, ans, 0, maxdepth);
        return ans;
    }
};