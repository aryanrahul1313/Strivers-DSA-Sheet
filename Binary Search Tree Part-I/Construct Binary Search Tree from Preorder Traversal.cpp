class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, int &index, int bound)
    {
        if(index == preorder.size() || preorder[index] > bound){
            return NULL;
        }
        // make the node and increment the index value
        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = buildTree(preorder, index, root->val);
        root->right = buildTree(preorder, index, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildTree(preorder, index, INT_MAX);
    }
};
