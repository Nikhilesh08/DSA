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
class FindElements {
public:
    unordered_map<int,int>mpp;
    void solve(TreeNode*root,int prev){
        if(root==NULL) return ;
        root->val=prev;
        mpp[root->val]=1;
        solve(root->left,2*(root->val)+1);
        solve(root->right,2*(root->val)+2);
    }

    // bool findHelper(TreeNode*root,int target){
    //     if(root->val==target) return true;
    //     bool left=findHelper(root->left,target);
    //     if(left==true) return true;
    //     bool right=findHelper(root->right,target);
    //     if(right==true) return true;
    //     return false;
        
    // }
    FindElements(TreeNode* root) {
        solve(root,0);
    }
    
    bool find(int target) {
        if(mpp.find(target)==mpp.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */