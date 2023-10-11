class Solution
{
    private:
    void reverseInorder(Node *root, int &K, int &ans)
    {
        if(!root) return ;
        
        // apply reverse inorder
        reverseInorder(root->right, K, ans);
        K--;
        if(K == 0){
            ans = root->data;
        }
        reverseInorder(root->left, K, ans);
    }
    
    public:
    int kthLargest(Node *root, int K)
    {
        int ans = 0;
        reverseInorder(root, K, ans);
        return ans;
    }
};
