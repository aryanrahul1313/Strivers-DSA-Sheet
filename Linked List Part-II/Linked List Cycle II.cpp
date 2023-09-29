Node *firstNode(Node *head)
{
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next && fast->next->next){  //till not NULL
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            //cycle exists
            slow = head; //start the  slow from start
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    } 
    return NULL;
}
