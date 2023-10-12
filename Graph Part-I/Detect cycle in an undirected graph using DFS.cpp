class Solution {
  private:
  bool detectDFS(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
      
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detectDFS(it, node, adj, vis) == true){
                    //if got true return true always dont go further
                    return true;
                }
            }
            else if(it != parent){
                // cycle is found
                return true;
            }
        }
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectDFS(i, -1, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
