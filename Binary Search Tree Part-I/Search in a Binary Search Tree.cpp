#Approach 1: Recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == val){
            return root;
        }
        else if(root->val  > val){
            // val is smaller so find in left
            return searchBST(root->left, val);
        }
        else{
            // val is bigger so find in right
            return searchBST(root->right, val);
        }
    }
};

******************************************************************
#Approach : Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while(root != NULL && root->val != val){
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
