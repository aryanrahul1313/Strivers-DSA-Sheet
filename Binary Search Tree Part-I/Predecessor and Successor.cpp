class Solution
{
    private:
    void successor(Node* root, Node*& suc, int key)
    {
        while(root != NULL){
            // check the root value is smaller if yes, move right
            if(root->key <= key){
                root = root->right;
            }
            else{
                // if u found root value greater than key, store it 
                // and check in left side
                suc = root;
                root = root->left;
            }
        }
    }
    
    void predecessor(Node* root, Node*& pre, int key)
    {
        while(root != NULL){
            if(root->key >= key){
                // check the root value is greater if yes, move left
                root = root->left;
            }
            else{
                // if u found root value smaller than key, store it 
                // and check in right side
                pre = root;
                root = root->right;
            }
        }
    }
    
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        predecessor(root, pre, key);
        successor(root, suc, key);
    }
};
