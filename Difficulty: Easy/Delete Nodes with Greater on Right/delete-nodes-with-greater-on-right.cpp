/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node*revList(Node*head){
        Node*prev=NULL;
        Node*curr=head;
        Node*next_ptr=NULL;
        while(curr!=NULL){
            next_ptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_ptr;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        if(head==NULL || head==nullptr){
            return head;
        }
        
        head=revList(head);
        Node*curr=head;
        Node*maxNode=head;
        while(curr->next!=NULL){
            // logic del smaller elements than max till now
            if(curr->next->data < maxNode->data){
                Node*delNode=curr->next;
                curr->next=delNode->next;
                delete delNode;
            }
            else{
                curr=curr->next;
                maxNode=curr;
            }
        }
        return revList(head);
        
    }
};