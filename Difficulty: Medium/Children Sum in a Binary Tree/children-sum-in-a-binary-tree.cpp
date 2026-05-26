/*

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
    bool isSumProperty(Node *root) {
        // code here
        if(root==NULL) return true;
        if(root->right ==NULL && root->left==NULL) return true;
        int childSum=0;
        if(root->right) childSum+=root->right->data;
        if(root->left) childSum+=root->left->data;
        return root->data==childSum&&
                isSumProperty(root->left)&&
                isSumProperty(root->right);
    }
};