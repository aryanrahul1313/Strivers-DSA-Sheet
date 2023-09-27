class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        
        int carry = 0;

        while(curr1 != NULL || curr2 != NULL || carry !=0){
            //important conditions to check
            int sum = 0;
            if(curr1 != NULL){
                sum += curr1->val;
                curr1 = curr1->next;
            }
           
            if(curr2 != NULL){
                sum += curr2->val;
                curr2 = curr2->next;
            }

            sum += carry;
            carry = sum/10;
            int data = sum%10;
            ListNode* temp = new ListNode(data);
            prev->next = temp;
            prev = prev->next;
        }
        return dummy->next;
    }
};
