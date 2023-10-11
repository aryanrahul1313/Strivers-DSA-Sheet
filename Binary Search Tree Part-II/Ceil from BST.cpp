#include <bits/stdc++.h> 
int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = -1;
    while(node != NULL){
        if(node->data < x){
            // since value of node is smaller than X,
            // we never gonna find the ans in left side
            // so move right..
            node = node->right;
        }
        else{
            // since u found value greater than or equal to X,
            // store it in ans and check is there any other value
            // exists, that is smaller than ans and greater than X
            // so move left...
            ans = node->data;
            node = node->left;
        }
    }
    return ans;
}
