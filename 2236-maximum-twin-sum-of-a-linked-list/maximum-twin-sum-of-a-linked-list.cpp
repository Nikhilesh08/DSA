class Solution {
public:
    ListNode* revList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_ptr;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = revList(slow); 
        ListNode* reversedHalfHead = head2; 

        ListNode* curr1 = head;
        ListNode* curr2 = head2;
        int maxi = 0;
        while (curr2 != nullptr) {
            maxi = max(maxi, curr1->val + curr2->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        revList(reversedHalfHead);

        return maxi;
    }
};