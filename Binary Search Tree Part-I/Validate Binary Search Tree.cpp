class Solution {
private:
    bool validate(TreeNode* root, long long lower, long long upper)
    {
        if(root == NULL){
            return true;
        }

        if(root->val <=lower || root->val >= upper){
            return false;
        }
        
        return validate(root->left, lower, root->val) 
                && validate(root->right, root->val, upper);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long lower = LLONG_MIN;
        long long upper = LLONG_MAX;
        return validate(root, lower, upper);
    }
};
