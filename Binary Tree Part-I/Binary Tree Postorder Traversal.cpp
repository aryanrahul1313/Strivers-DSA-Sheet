class Solution {
private:
    void Postorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL){
            return;
        }

        Postorder(root->left, ans);
        Postorder(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        Postorder(root, ans);
        return ans;
    }
};
