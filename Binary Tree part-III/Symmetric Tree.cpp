class Solution {
private:
    bool isMirror(TreeNode* leftnode, TreeNode* rightnode)
    {
        if(leftnode == NULL || rightnode == NULL){
            return leftnode == rightnode;
        }

        if(leftnode->val != rightnode->val){
            return false;
        }

        return isMirror(leftnode->left, rightnode->right) 
        && isMirror(leftnode->right, rightnode->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftnode = root->left;
        TreeNode* rightnode = root->right;

        return (root == NULL) || isMirror(leftnode, rightnode);
    }
};
