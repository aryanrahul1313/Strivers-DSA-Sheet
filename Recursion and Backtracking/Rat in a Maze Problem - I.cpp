class Solution{
    private:
        void solve(int i, int j, vector<vector<int>> &m, int n, string path,
                    vector<vector<int>> &visited, vector<string> &ans)
        {
            //base case
            if(i == n-1 && j == n-1){
                ans.push_back(path);
                return;
            }
            // i for row and j for column
            
            //down
            if(i+1 < n && !visited[i+1][j] && m[i+1][j] == 1){
                visited[i][j] = 1;
                solve(i+1, j, m, n, path + 'D', visited, ans);
                visited[i][j] = 0; // backtracking
            }
            
            //left
            if(j-1 >= 0 && !visited[i][j-1] && m[i][j-1] == 1){
                visited[i][j] = 1;
                solve(i, j-1, m, n, path + 'L', visited, ans);
                visited[i][j] = 0; // backtracking
            }
            
            //Right
            if(j+1 < n && !visited[i][j+1] && m[i][j+1] == 1){
                visited[i][j] = 1;
                solve(i, j+1, m, n, path + 'R', visited, ans);
                visited[i][j] = 0; // backtracking
            }
            
            //Up
            if(i-1 >= 0 && !visited[i-1][j] && m[i-1][j] == 1){
                visited[i][j] = 1;
                solve(i-1, j, m, n, path + 'U', visited, ans);
                visited[i][j] = 0; // backtracking
            }
        }
    
    public:
        vector<string> findPath(vector<vector<int>> &m, int n) {
            vector<string> ans;
            vector<vector<int>> visited(n, vector<int> (n,0));
            if(m[0][0] == 1){
                solve(0, 0, m, n, "", visited, ans);
            }
            return ans;
        }
};
