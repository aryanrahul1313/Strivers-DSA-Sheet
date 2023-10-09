class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL){
            return;
        }
        
        Node* leftnode = node->left;
        Node* rightnode = node->right;
        
        node->right = leftnode;
        node->left = rightnode;
        
        mirror(leftnode);
        mirror(rightnode);
    }
};
