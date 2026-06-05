class Solution {
public:
    void traverseAndSwap(TreeNode* leftNode, TreeNode* rightNode, int level) {
        if (leftNode == nullptr || rightNode == nullptr) {
            return;
        }
        if (level % 2 != 0) {
            swap(leftNode->val, rightNode->val);
        }
        traverseAndSwap(leftNode->left, rightNode->right, level + 1);
        traverseAndSwap(leftNode->right, rightNode->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        traverseAndSwap(root->left, root->right, 1);
        return root;
    }
};