class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        //find the middle of linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // now reverse half linked list
        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //final check
        ListNode* dummy = head;
        while(prev != NULL){
            if(prev->val != dummy->val){
                return false;
            }
            prev = prev->next;
            dummy = dummy->next;
        }
        return true;
    }
};
