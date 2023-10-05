class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        //Inside map => vertical, <level, multiset>
        map<int, map<int, multiset<int>>> mpp;

        //Inside queue => node, vertical, level
        queue<pair<TreeNode*, pair<int, int>>> q;

        if(root){
            q.push({root,{0,0}});
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            mpp[vertical][level].insert(node->val);

            if(node->left){
                q.push({node->left, {vertical-1, level+1}});
            }

            if(node->right){
                q.push({node->right, {vertical+1, level+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p : mpp){
            vector<int> temp;
            //p.second --> (level, multiset)
            for(auto it : p.second){
                // I've merged the multiset values directly into the temp vector 
                temp.insert(temp.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
