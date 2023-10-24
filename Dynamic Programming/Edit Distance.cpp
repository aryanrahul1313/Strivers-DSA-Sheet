//Approach 1: Recursion + Memoization
#include<bits/stdc++.h>
int solveRecMem(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
{
    //base case
    // who ever gests over, the remaining 'index+1' of opposite is
    // the no. of operations require to make both strings same
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(str1[i] == str2[j]){
        return solveRecMem(str1, str2, i-1, j-1, dp);
    }

    // insert
    int insert = 1 + solveRecMem(str1, str2, i, j-1, dp);
    // delete
    int remove = 1 + solveRecMem(str1, str2, i-1, j, dp);
    // replace
    int replace = 1 + solveRecMem(str1, str2, i-1, j-1, dp);
    
    dp[i][j] = min(insert, min(remove, replace));
    return dp[i][j];
}

int editDistance(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1, vector<int>(len2, -1));

    return solveRecMem(str1, str2, len1-1, len2-1, dp);
}

**************************************************************************
//Approach 2: Tabulation
#include<bits/stdc++.h>
int solveTab(string &str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    // for every j == 0
    for(int i=0; i<=len1; i++){
        dp[i][0] = i;
    }
    // for every i == 0
    for(int j=0; j<=len2; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                // insert
                int insert = 1 + dp[i][j-1];
                // delete
                int remove = 1 + dp[i-1][j];
                // replace
                int replace = 1 + dp[i-1][j-1];

                dp[i][j] = min(insert, min(remove, replace));
            }
        }
    }
    return dp[len1][len2];
}

int editDistance(string str1, string str2)
{
    return solveTab(str1, str2);
}

*************************************************************************
//Approach 3: Space Optimization
#include<bits/stdc++.h>
int solveSpaxeOpt(string &str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<int> prev(len2+1,0);
    vector<int> curr(len2+1,0);
    
    for(int j=0; j<=len2; j++){
        prev[j] = j;
    }

    for(int i=1; i<=len1; i++){
        curr[0] = i;  //doubt (look base case of tabulation)
        for(int j=1; j<=len2; j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                // insert
                int insert = 1 + curr[j-1];
                // delete
                int remove = 1 + prev[j];
                // replace
                int replace = 1 + prev[j-1];

                curr[j] = min(insert, min(remove, replace));
            }
        }
        prev = curr;
    }
    return prev[len2];
}

int editDistance(string str1, string str2)
{
    return solveSpaxeOpt(str1, str2);
}
