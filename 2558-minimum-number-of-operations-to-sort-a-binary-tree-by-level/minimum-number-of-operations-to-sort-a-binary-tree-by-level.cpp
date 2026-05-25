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
    int findSwaps(vector<int>&vec){
        vector<int>target=vec;
        sort(target.begin(),target.end());
        unordered_map<int,int>mpp;
        int swaps=0;
        for(int i=0;i<vec.size();i++){
            mpp[vec[i]]=i;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]==target[i]) continue;
            int currInd=mpp[target[i]];
             mpp[vec[i]]=currInd;
            mpp[vec[currInd]]=i;
            swap(vec[i],vec[currInd]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int swaps=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>vec;
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                vec.push_back(node->val);
            }
            swaps+=findSwaps(vec);
        }
        return swaps;
    }
};