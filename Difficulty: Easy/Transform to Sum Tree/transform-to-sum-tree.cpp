/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int transform(Node*root){
        if(root==nullptr) return 0;
        int left=transform(root->left);
        int right=transform(root->right);
        
        int temp=root->data;
        root->data=left+right;
        return temp+root->data;
    }
    void toSumTree(Node *root) {
        // code here
        transform(root);
    }
};