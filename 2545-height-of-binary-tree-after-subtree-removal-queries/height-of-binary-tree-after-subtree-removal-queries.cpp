/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int max_depth;
    int ans[100005]; 
    void dfs_ltr(TreeNode* node, int depth) {
        if (!node) return;
        ans[node->val] = max_depth;
        max_depth = max(max_depth, depth);
        dfs_ltr(node->left, depth + 1);
        dfs_ltr(node->right, depth + 1);
    }
    void dfs_rtl(TreeNode* node, int depth) {
        if (!node) return;
        ans[node->val] = max(ans[node->val], max_depth);
        max_depth = max(max_depth, depth);
        dfs_rtl(node->right, depth + 1);
        dfs_rtl(node->left, depth + 1);
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        max_depth = 0;
        dfs_ltr(root, 0);
        max_depth = 0;
        dfs_rtl(root, 0);
        vector<int> result;
        result.reserve(queries.size());
        for (int q : queries) {
            result.push_back(ans[q]);
        }
        
        return result;
    }
};