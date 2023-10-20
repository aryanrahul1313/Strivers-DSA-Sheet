class Solution
{
    private:
        void dfsFinishingTime(int node, vector<int> &vis, stack<int> &st, 
                                vector<vector<int>>& adj)
        {
            vis[node] = 1;
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfsFinishingTime(it, vis, st, adj);
                }
            }
            st.push(node);
        }
        
        private:
            void dfsForSCC(int node, vector<vector<int>>& adjTranspose, 
                            vector<int> &vis)
            {
                vis[node] = 1;
                
                for(auto it : adjTranspose[node]){
                    if(!vis[it]){
                       dfsForSCC(it, adjTranspose, vis); 
                    }
                }
            }
        
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step 1: Sort according to finishing time
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsFinishingTime(i, vis, st, adj);
            }
        }
        
        // Step 2: transpose the graph
        vector<vector<int>> adjTranspose(V);
        for(int i=0; i<V; i++){
            vis[i] = 0; // we can use vis vector in step 3
            for(auto it : adj[i]){
                // i --> it , before transpose
                // it --> i, after transpose
                adjTranspose[it].push_back(i);
            }
        }
        
        // Step 3: Do the DFS
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfsForSCC(node, adjTranspose, vis);
                scc++;
            }
        }
        return scc;
    }
};
