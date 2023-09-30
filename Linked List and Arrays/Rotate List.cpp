class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* curr = head;
        //calculate the length of list
        int len = 1;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }

        //now make circular LL
        curr->next = head;

        // Adjust 'k' to avoid unnecessary rotations.
        //reduce K as every multiples of len gives the same LL
        k = k % len;
        k = len - k; //to reach the last node of final LL

        while(k--){
            curr = curr->next;
        }

        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};
