class BSTIterator {
private: stack<TreeNode*> myStack;

    void pushAll(TreeNode* node){
        for(; node != NULL; node = node->left){
            myStack.push(node);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // return the next smallest number
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    // return whether we have nexet smallest number or not
    bool hasNext() {
        return !myStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
