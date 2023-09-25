class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        //base case
        if(i == (m-1) && j == (n-1)){ //destination reached
            return 1;
        }  
        if(i >= m || j >= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
        }
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return countPaths(0, 0, m, n, dp);

    }
};
