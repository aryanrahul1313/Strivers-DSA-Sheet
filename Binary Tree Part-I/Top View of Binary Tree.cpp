class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            
            Node* element = p.first;
            int line = p.second;
            
            // element for particular vertical line not found then insert
            // otherwise move ahead and change nothing
            if(mpp.find(line) == mpp.end()){
                mpp[line] = element->data;
            }
            
            if(element->left != NULL){
                q.push({element->left, line-1});
            }
            
            if(element->right != NULL){
                q.push({element->right, line+1});
            }
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

};
