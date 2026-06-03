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
    TreeNode*solve(TreeNode*root,int val,int depth,int currdepth){
        if(root==NULL) return NULL;
        if(depth==1){
            TreeNode*node=new TreeNode(val);
            node->left=root;
            return node;
        }

        if(currdepth==depth-1){
            TreeNode*leftNode=root->left;
            TreeNode*rightNode=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=leftNode;
            root->right->right=rightNode;
            return root;
        }
        solve(root->left,val,depth,currdepth+1);
        solve(root->right,val,depth,currdepth+1);
        return root;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root,val,depth,1);
    }
};