class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2){
        ListNode* prev = list1;
        ListNode* curr = prev->next;
        ListNode* element = list2;
        ListNode* temp = NULL;

        while(curr != NULL && element != NULL){
            if(element->val >= prev->val && element->val <= curr->val){
                //node addition acc. to condition
                prev->next = element;
                temp = element->next;
                element->next = curr; 
                //node updation
                prev = element;
                element = temp;
            }
            else{
                prev = curr;
                curr = curr->next;
                //important point
                if(curr == NULL){
                    prev->next = element;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){ 
            return list1;
        }
        if(list1->next == NULL && list1->val <= list2->val){
            list1->next = list2;
            return list1;
        }
        if(list2->next == NULL && list2->val <= list1->val){
            list2->next = list1;
            return list2;
        }

        //to check that which list has start node value lesser
        //that will be our main list and other one, will get inserted
        if(list1->val < list2->val){
            return solve(list1, list2);  
        }
        else{
            return solve(list2, list1);
        }
    }
};
