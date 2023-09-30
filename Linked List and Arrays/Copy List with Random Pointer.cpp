#Approach 1:
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        //clone of main list using next pointer
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;

        Node* cloneHead = NULL;
        Node* clone = new Node(head->val);
        mpp[temp] = clone;
        cloneHead = clone;

        temp = temp->next;

        while(temp != NULL){
            Node* curr = new Node(temp->val);
            mpp[temp] = curr;
            clone->next = curr;
            clone = clone->next;
            temp = temp->next;
        }

        //placing the random pointers in clone list
        Node* curr1 = head;
        Node* curr2 = cloneHead;
        while(curr2 != NULL){
            curr2->random = mpp[curr1->random];
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return cloneHead;
    }
};
*****************************************************************
#Approach 2:
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        //insert clone nodes in between original nodes
        Node* curr = head;
        while(curr != NULL){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        //replicate the random pointers in clone nodes
        Node* dummy = head;
        while(dummy != NULL){
            if(dummy->random != NULL){
                dummy->next->random = dummy->random->next;
            }
            dummy = dummy->next->next;
        }

        //revert all the pointers to make separate original and clone list
        Node* original = head;
        Node* cloneHead = head->next;
        Node* clone = cloneHead;

        while(original != NULL && clone != NULL){
            original->next = clone->next;
            original = original->next;
            if(original != NULL){
                clone->next = original->next;
            }
            clone = clone->next;
        }
        return cloneHead;
    }     
};
