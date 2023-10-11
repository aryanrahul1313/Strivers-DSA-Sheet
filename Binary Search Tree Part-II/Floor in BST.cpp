#include <bits/stdc++.h> 
int floorInBST(TreeNode<int> * root, int X)
{
    int ans;
    while(root != NULL){
        if(root->val > X){
            // since value of root is bigger than X,
            // we never gonna find the ans in right side
            // so move left..
            root = root->left;
        }
        else{
            // since u found value smaller than or equal to X,
            // store it in ans and check is there any other value
            // exists, that is greater than ans and less than X
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}
