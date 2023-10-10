class Solution {
public:
    Node* connect(Node* root) {
        // traverse prev in left pointers only
        // traverse curr in next pointers only

        Node* prev = root;
        while(prev != NULL){
            Node* curr = prev;
            while(curr != NULL && curr->left != NULL){
                // connect left subtree to right subtree in same level
                curr->left->next = curr->right;

                //connect rightmost node to leftmost node "next" neighbour on same level
                if(curr->next != NULL){
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};
