/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,vector<int>>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        // node ver
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node*node=it.first;
            int ver=it.second;
            mpp[ver].push_back(node->data);
            if(node->left){
                q.push({node->left,ver-1});
            }
            if(node->right){
                q.push({node->right,ver+1});
            }
        }
        
        int tot=0;
        vector<int>ans;
        for(auto it : mpp){
            tot=0;
            for(int num : it.second){
                tot+=num;
            }
            ans.push_back(tot);
        }
        return ans;
        
    }
};