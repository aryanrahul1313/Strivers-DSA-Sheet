//Approach 1: Recursion + Memoization
#include<bits/stdc++.h>  
int solveRecMem(int i, int j, string s, string t, vector<vector<int>> &dp)
{
	if(i < 0 || j < 0){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	// both index matches
	if(s[i] == t[j]){
		return 1 + solveRecMem(i-1, j-1, s, t, dp);
	}

	dp[i][j] = max(solveRecMem(i-1, j, s, t, dp), solveRecMem(i, j-1, s, t, dp));
	return dp[i][j];
}

int lcs(string s, string t)
{
	int n1 = s.length();
	int n2 = t.length();

	vector<vector<int>> dp(n1, vector<int>(n2, -1));
	return solveRecMem(n1-1, n2-1, s, t, dp);

}

**********************************************************************
//Approach 2: Tabulation
#include<bits/stdc++.h>
// this is actual tabulation
int lcs(string s, string t)
{
	int n1 = s.length();
	int n2 = t.length();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
	for(int i=0; i<=n1; i++) dp[i][0] = 0;
	for(int j=0; j<=n2; j++) dp[0][j] = 0;

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n1][n2];
}

*********************************************************************
//Approach 3: Space Optimization
#include<bits/stdc++.h>
// this is Space Optimization
int lcs(string s, string t)
{
	int n1 = s.length();
	int n2 = t.length();

	vector<int> prev(n2+1, 0);
	vector<int> curr(n2+1, 0);

	for(int j=0; j<=n2; j++) prev[j] = 0;

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s[i-1] == t[j-1]){
				curr[j] = 1 + prev[j-1];
			}
			else{
				curr[j] = max(prev[j], curr[j-1]);
			}
		}
		prev = curr;
	}
	return prev[n2];
}
