class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        long long ans = 0;
        // make queue and inset node and its index
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            long long size = q.size();
            // assign the left most index of node as minimum index
            long long min_ind = q.front().second;
            long long leftMost, rightMost;

            for(int i=0; i<size; i++){
                // modify the index of present node using below line
                long long curr_ind = q.front().second - min_ind;
                TreeNode* node = q.front().first;
                q.pop();
                // assign leftmost as start index of that level
                if(i == 0) leftMost = curr_ind;

                // assign rightmost as end index of that level
                if(i == size-1) rightMost = curr_ind;

                if(node->left){
                    // assign node's children index using formula wriiten below
                    //for left side
                    q.push({node->left, curr_ind*2 + 1});
                }

                if(node->right){
                    // assign node's children index using formula wriiten below
                    // for right side
                    q.push({node->right, curr_ind*2 + 2});
                }
            }
            ans = max(ans, rightMost-leftMost+1);
        }
        return ans;
    }
};
