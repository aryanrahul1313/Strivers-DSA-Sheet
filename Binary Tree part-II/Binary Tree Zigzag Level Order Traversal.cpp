class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp; 

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                // Insert the node value into the temp vector
                if (flag) {
                    temp.push_back(node->val);
                } else {
                    temp.insert(temp.begin(), node->val);
                }

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            //after this level
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};
