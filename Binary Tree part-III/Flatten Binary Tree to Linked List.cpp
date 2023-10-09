#Approach 1: Recursive
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);
        // connect right to prev
        root->right = prev;
        // and make left null
        root->left = NULL;
        //update prev
        prev = root;
    }
};

***************************************************

#Approach 2: Morris Traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                //go to the right most node
                while(prev->right){
                    prev = prev->right;
                }
                // link this node to startnode of right subtree
                prev->right = curr->right;
                // Replace the right subtree with the left subtree
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
