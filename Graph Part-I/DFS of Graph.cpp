class Solution {
  private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        // traverse all its neighbours
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int start = 0;
        vector<int> ans;
        dfs(start, adj, visited, ans);
        return ans;
    }
};
