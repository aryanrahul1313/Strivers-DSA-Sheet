bool isParentSum(Node *root){
    if(root == NULL){
        return true;
    }
    // Leaf nodes always satisfy the condition.    
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    int leftValue = root->left ? root->left->data : 0;
    int rightValue = root->right ? root->right->data : 0;

    if(root->data != leftValue + rightValue){
        return false;
    }
    
    // Recursively check the left and right subtrees.
    return isParentSum(root->left) && isParentSum(root->right);
      
}
