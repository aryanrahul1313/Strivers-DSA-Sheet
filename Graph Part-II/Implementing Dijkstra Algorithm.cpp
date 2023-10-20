#Approach 1: Using Priority Queue
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // make the min heap (priority queue)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> distance(V);
        for(int i=0; i<V; i++){
            distance[i] = 1e9;
        }
        
        distance[S] = 0;
        pq.push({0, S});  // {dist, node}
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dist + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};

***************************************************************************
#Approach 2 : Using Set
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // make the set
        set<pair<int, int>> st;
        vector<int> distance(V, 1e9);
        
        
        distance[S] = 0;
        st.insert({0, S});  // {dist, node}
        
        while(!st.empty()){
            auto it = *(st.begin()); // points the first iterator
            int dist = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dist + edgeWeight < distance[adjNode]){
                    // erase if already existed
                    if(distance[adjNode] != 1e9){
                        st.erase({distance[adjNode], adjNode});
                    }
                    
                    distance[adjNode] = dist + edgeWeight;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};
