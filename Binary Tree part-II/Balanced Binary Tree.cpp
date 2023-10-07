class Solution {
private:
    int dfsHeight(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left = dfsHeight(root->left);
        if(left == -1) return -1;

        int right = dfsHeight(root->right);
        if(right == -1) return -1;

        // check if balanced or not
        if(abs(right-left) > 1) return -1;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};
