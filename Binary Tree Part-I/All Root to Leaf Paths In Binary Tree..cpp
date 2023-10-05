void leafNode(BinaryTreeNode<int>* root, vector<string> &v, string path)
{
    if(root == NULL){
        return ;
    }
    path += to_string(root->data) + " ";

    // If it's a leaf node, add to vector
    if(root->left == NULL && root->right == NULL){
        v.push_back(path);
        return;
    }

    leafNode(root->left, v, path);
    leafNode(root->right, v, path);
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string> v;
    string path = "";
    
    leafNode(root, v, path);
    return v;
}
