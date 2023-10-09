class Solution {
private:
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mpp)
    {
        //base case
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        // root node will be the start element of preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        //find root position in inorder through map
        int inRoot = mpp[root->val];
        //numbers in left of root
        int nums = inRoot - inStart;

        // building the left subtree
        root->left = constructTree(preorder, preStart+1, preStart + nums, inorder, inStart, inRoot - 1, mpp);

        // building the right subtree
        root->right = constructTree(preorder, preStart + nums + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);

        // while returning links will created
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        int n = preorder.size();
        int m = inorder.size();

        for(int i=0; i<m; i++){
            mpp[inorder[i]] = i;
        }
        
        TreeNode* root = constructTree(preorder, 0, n-1, inorder, 0, m-1, mpp);
        return root;
    }
};
