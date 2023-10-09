class Solution {
private:
    TreeNode* constructTree(vector<int>& inorder, int inStart, int inEnd, 
                vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> &mpp)
    {
        //base case
        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }
        // root node will be the start element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        //find root position in inorder through map
        int inRoot = mpp[root->val];
        //numbers in left of root
        int nums = inRoot - inStart;

        // building the left subtree
        root->left = constructTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + nums - 1, mpp);

        // building the right subtree
        root->right = constructTree(inorder, inRoot + 1, inEnd, postorder, postStart + nums, postEnd - 1, mpp);

        // while returning links will created
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n = postorder.size();
        int m = inorder.size();

        for(int i=0; i<m; i++){
            mpp[inorder[i]] = i;
        }
        
        TreeNode* root = constructTree(inorder, 0, m-1, postorder, 0, n-1, mpp);
        return root;
    }
};
