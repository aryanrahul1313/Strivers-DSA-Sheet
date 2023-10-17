class Solution
{
    private:
    void dfsTopo(int node, vector<int> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        // traversing thorugh neighbors
        for(auto it : adj[node]){
            if(!vis[it]){
                dfsTopo(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    
	    for(int i=0;i<V; i++){
	        if(!vis[i]){
	            dfsTopo(i, adj, vis, st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        int temp = st.top();
	        st.pop();
	        ans.push_back(temp);
	    }
	    return ans;
	}
};
