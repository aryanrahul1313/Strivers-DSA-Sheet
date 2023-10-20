class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // create priority queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> visited(V, 0);
        pq.push({0,0});  // {wt, node}
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            // if visited do nothing
            if(visited[node]){
                continue;
            }
            
            visited[node] = 1;
            sum += wt;
            
            for(auto it: adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];
                
                if(!visited[adjNode])
                {
                    pq.push({weight, adjNode});
                }
            }
        }
        return sum;
    }
};
