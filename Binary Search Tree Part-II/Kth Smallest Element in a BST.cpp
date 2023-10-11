class Solution {
private:
    void inorder(TreeNode* root, int &k, int &ans)
    {
        if(root == NULL){
            return;
        }

        inorder(root->left, k, ans);
        k--;
        if(k == 0){
            ans = root->val;
        }
        inorder(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // if we do inorder traversal then in kth iteration 
        // we’ll get our ans...
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
