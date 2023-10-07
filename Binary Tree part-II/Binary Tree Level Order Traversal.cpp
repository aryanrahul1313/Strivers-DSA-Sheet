class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> temp; 
            int n = q.size();

            for(int i=1; i<=n; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
