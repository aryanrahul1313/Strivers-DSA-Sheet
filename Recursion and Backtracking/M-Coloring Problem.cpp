class Solution{
private:
    bool isSafe(int node, int colour[], bool graph[101][101], int col, int n)
    {
        for(int i=0; i<n; i++){
            //graph[i][node] == 1 it means adjacent node having edge or not
            if(i != node && graph[i][node] == 1 && colour[i] == col){
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int colour[], bool graph[101][101], int m, int n)
    {
        //base case
        if(node == n){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(isSafe(node, colour, graph, i, n)){
                colour[node] = i;
                
                if(solve(node+1, colour, graph, m, n)){
                    return true;
                }
                else{
                    //backtrack
                    colour[node] = 0;
                }
            }
        }
        return false;
    }
    
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        int colour[n] = {0};
        if(solve(0, colour, graph, m, n)){
            return true;
        }
        else{
            return false;
        }
    }
};
