#include <bits/stdc++.h> 
vector<int> getPreOrderTraversal(TreeNode *root)
{
    //Using Morris Traversal
    vector<int> preorder;
    TreeNode *curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{ //left is not NULL 
            TreeNode *predecessor = curr->left;
            //go the the rightmost node
            while(predecessor->right && predecessor->right != curr){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                //create threded link(temporary)
                predecessor->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                //threaded link already exists, so remove
                predecessor->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
