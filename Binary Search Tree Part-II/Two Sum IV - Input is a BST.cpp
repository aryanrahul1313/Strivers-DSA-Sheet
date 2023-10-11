class BSTIterator {
    stack<TreeNode*> myStack;
    // reverse ->true ---> before() ki bt ho rhi
    // reverse ->false ---> next() ki bt ho rhi
    bool reverse = true;

private:
    void pushAll(TreeNode* node){
        // iterating over the tree
        while(node != NULL){
            myStack.push(node);
            if(reverse == true){
                // we are considering for "before()"
                node = node->right; 
            }
            else{
                // we are considering for "next()"
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    // return the next smallest number
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        if(!reverse){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }
    // return whether we have nexet smallest number or not
    bool hasNext() {
        return !myStack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        // l is left mtlb next ke liye
        BSTIterator l(root, false);
        // r is right mtlb before ke liye
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i+j == k){
                return true;
            }
            else if(i+j < k) {
                // increment left side
                i = l.next();
            }
            else{
                // increment right side
                j = r.next();
            }
        }
        return false;
    }
};
