/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node*first;
    Node*middle;
    Node*prev;
    Node*last;
    void inorder(Node*root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && root->data<prev->data){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void correctBST(Node* root) {
        // add code here.
        first=middle=last=prev=NULL;
        inorder(root);
        if(first && last ) swap(first->data,last->data);
        else if(first && middle) swap(first->data,middle->data);
    }
};