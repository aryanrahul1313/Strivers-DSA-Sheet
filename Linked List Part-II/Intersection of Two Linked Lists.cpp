class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        if(curr1 == NULL && curr2 == NULL){
            return NULL;
        }

        while(curr1 != curr2){
            if(curr1 == NULL){
                curr1 = headB;
            }
            else{
                curr1 = curr1->next;
            }

            if(curr2 == NULL){
                curr2 = headA;
            }
            else{
                curr2 = curr2->next;
            }
            //important to include else part
        }
        return curr1;
    }
};
