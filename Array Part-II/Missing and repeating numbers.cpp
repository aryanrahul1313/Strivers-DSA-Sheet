#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	unordered_map<int, bool> visited;
	int repeat = 0;
	for(int i=0;i<n; i++){
		if(visited[arr[i]]){
			repeat = arr[i];
		}
		else{
			visited[arr[i]] = true;
		}
	}

	int miss = 0;
	for(int i=1; i<=n; i++){
		if(visited.find(i) == visited.end()){
			miss = i;
			break;
		}
	}

	pair<int, int> p = make_pair(miss, repeat);
	return p;
}
