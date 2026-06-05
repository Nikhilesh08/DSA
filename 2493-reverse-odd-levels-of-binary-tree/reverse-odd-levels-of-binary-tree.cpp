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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
        int sz=q.size();
        vector<TreeNode*>vec;
        for(int i=0;i<sz;i++){
            TreeNode*node=q.front();
            q.pop();
            if(level%2!=0){
                vec.push_back(node);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        if(level%2!=0){
            int low=0;
            int high=vec.size()-1;
            while(low<high){
                TreeNode*first=vec[low];
                TreeNode*end=vec[high];
                int temp=first->val;
                first->val=end->val;
                end->val=temp;
                low++;
                high--;
            }
        }
        level++;
    }
    return root;
    }
};