class Solution {
private:
    Node* dfs(Node* curr, unordered_map<Node*, Node*> &mpp)
    {
        vector<Node*> nbr;
        // creating new node and add it to map 
        // In Map --> old node to new node mapping
        Node* clone = new Node(curr->val);
        mpp[curr] = clone;

        // traversing throgh neighbours
        for(auto it : curr->neighbors)
        {
            if(mpp.find(it) != mpp.end()){
                // already cloned and stored in map
                // store the clone node from map to nbr
                nbr.push_back(mpp[it]);
            }
            else{
                Node* temp = dfs(it, mpp);
                nbr.push_back(temp);
            }
        }
        // store the nbr's in neighbors of clone adj list
        clone->neighbors = nbr;
        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mpp;

        if(node == NULL){
            return NULL;
        } 
        
        return dfs(node, mpp);
    }
};
