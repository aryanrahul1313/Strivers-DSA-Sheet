class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, they are identical
        if (p == NULL && q == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if (p == NULL || q == NULL) {
            return false;
        }
        // Check if values are equal and recursively check left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
