vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    vector<int> preorder, inorder, postorder;
    
    if(root == NULL){
        return ans;
    }

    while(!st.empty()){
        pair<TreeNode*, int> p = st.top();
        st.pop();

        // for preorder
        if(p.second == 1){
            preorder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if(p.first->left != NULL){
                st.push({p.first->left, 1});
            }
        }

        //  for inorder
        else if(p.second == 2){
            inorder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if(p.first->right != NULL){
                st.push({p.first->right, 1});
            }
        }

        // for postorder
        else{
            postorder.push_back(p.first->data);
        }
    }
        
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
