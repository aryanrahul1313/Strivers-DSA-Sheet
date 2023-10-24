//Approach 1: Recursion + Memoization
#include<bits/stdc++.h>
int solveRecMem(int ind, int W, vector<int> &val, vector<int> &wt, 
					vector<vector<int>> &dp)
{
	//base case...
	//if only 1 item to steal,then just compare its weight t0 W
	if(ind == 0){
		if(wt[0] <= W){
			return val[0];
		}
		else{
			return 0;
		}
	}

	if(dp[ind][W] != -1){
		return dp[ind][W];
	}

	// not take
	int not_take = solveRecMem(ind-1, W, val, wt, dp);
	// take
	int take = INT_MIN;
	if(wt[ind] <= W){
		take = val[ind] + solveRecMem(ind-1, W-wt[ind], val, wt, dp);
	}
	return dp[ind][W] = max(take, not_take);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1,-1));
	return solveRecMem(n-1, w, values, weights, dp);
}

*********************************************************************************
//Approach 2: Tabulation
#include<bits/stdc++.h>

int solveTab(int n, int maxWt, vector<int> &val, vector<int> &wt)
{
	vector<vector<int>> dp(n, vector<int>(maxWt+1,0));
	
	for(int W=wt[0]; W<=maxWt; W++){
		dp[0][W] = val[0];
	}

	for(int ind=1; ind<n; ind++){
		for(int W=0; W<=maxWt; W++){
			// not take
			int not_take = dp[ind-1][W];
			// take
			int take = INT_MIN;
			if(wt[ind] <= W){
				take = val[ind] + dp[ind-1][W-wt[ind]];
			}
			dp[ind][W] = max(take, not_take);
		}
	}
	return dp[n-1][maxWt];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return solveTab(n, w, values, weights);
}

**********************************************************************************
//Approach 3: Space Optimization
#include<bits/stdc++.h>

int solveSpaceOpt(int n, int maxWt, vector<int> &val, vector<int> &wt)
{
	vector<int> prev(maxWt+1,0);
	vector<int> curr(maxWt+1,0);
	
	for(int W=wt[0]; W<=maxWt; W++){
		prev[W] = val[0];
	}

	for(int ind=1; ind<n; ind++){
		for(int W=0; W<=maxWt; W++){
			// not take
			int not_take = prev[W];
			// take
			int take = INT_MIN;
			if(wt[ind] <= W){
				take = val[ind] + prev[W-wt[ind]];
			}
			curr[W] = max(take, not_take);
		}
		prev = curr;
	}
	return prev[maxWt];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return solveSpaceOpt(n, w, values, weights);
}

********************************************************************************
//Approach 3: More Space Optimization
#include<bits/stdc++.h>
int solveMoreSpaceOpt(int n, int maxWt, vector<int> &val, vector<int> &wt)
{
	vector<int> prev(maxWt+1,0);
	
	for(int W=wt[0]; W<=maxWt; W++){
		prev[W] = val[0];
	}

	for(int ind=1; ind<n; ind++){
		for(int W=maxWt; W>=0; W--){
			// not take
			int not_take = prev[W];
			// take
			int take = INT_MIN;
			if(wt[ind] <= W){
				take = val[ind] + prev[W-wt[ind]];
			}
			prev[W] = max(take, not_take);
		}
	}
	return prev[maxWt];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return solveMoreSpaceOpt(n, w, values, weights);
}
