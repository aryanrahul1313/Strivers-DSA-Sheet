#Approach 1: BFS
class Solution {
private:
    bool BFScheck(int start, vector<vector<int>>& graph, vector<int> &colour)
    {
        colour[start] = 0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                // if adjacent node is not coloured 
                // assign it opposite colour of node
                if(colour[it] == -1){
                    colour[it] = !colour[node];
                    q.push(it);
                }
                // if adjacent node have the same colour
                // it means it was earlier cooured in diff. path
                else if(colour[it] == colour[node]){
                    return false;
                }
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
                if(BFScheck(i, graph, colour) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

*******************************************************************
#Approach 2 : DFS
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
