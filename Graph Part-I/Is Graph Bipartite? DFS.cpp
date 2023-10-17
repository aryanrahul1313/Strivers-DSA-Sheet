class Solution {
private:
    bool dfsCheck(int node, int col, vector<vector<int>>& graph, vector<int> &colour)
    {
        colour[node] = col;

        for(auto it : graph[node]){
            // if not yet coloured
            if(colour[it] == -1){
                // recursive call get false, return false
                if(dfsCheck(it, !col, graph, colour) == false){
                    return false;
                }
            }
            // adjacent node has same colour
            else if(colour[it] == col){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);

        for(int i=0; i<n; i++){
            if(colour[i] == -1){
                if(dfsCheck(i, 0, graph, colour) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
