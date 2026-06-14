/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*revList(ListNode*head){
        ListNode*prev=NULL;
        ListNode*next_ptr=head;
        ListNode*curr=head;
        while(next_ptr!=NULL){
            next_ptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_ptr;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head2=revList(slow->next);
        ListNode*curr1=head;
        ListNode*curr2=head2;
        int maxi=0;
        while(curr1 && curr2){
            maxi=max(maxi,curr1->val+curr2->val);
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return maxi;
    }
};