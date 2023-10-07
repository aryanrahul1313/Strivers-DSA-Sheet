bool isLeaf(TreeNode<int> *root){
    return (root->left == NULL && root->right == NULL);
}

void leftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int>* curr = root->left;

    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }

        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void leafNodes(TreeNode<int> *root, vector<int> &ans)
{
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left){
        leafNodes(root->left, ans);
    }

    if(root->right){
        leafNodes(root->right, ans);
    }
}

void rightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int>* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }

        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    if(!isLeaf(root)){
        ans.push_back(root->data);
    }

    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightBoundary(root, ans);
    return ans;
}
