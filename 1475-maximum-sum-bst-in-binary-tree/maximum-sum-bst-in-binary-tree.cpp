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
 class NodeValue{
    public:
    int maxNode,minNode,val;
    NodeValue(int minNode,int maxNode,int val){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->val=val;
    }
};
class Solution {
public:
     NodeValue helper(TreeNode*root,int &maxi){
        //post order
        if(root==NULL){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto left=helper(root->left,maxi);
        auto right=helper(root->right,maxi);
        if(left.maxNode<root->val && root->val<right.minNode){
            maxi=max(maxi,root->val+left.val+right.val);
            return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),
            root->val+left.val+right.val);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.val,right.val));
        
    }
    int maxSumBST(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};