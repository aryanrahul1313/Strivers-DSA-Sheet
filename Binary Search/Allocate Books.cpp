#include <bits/stdc++.h> 
using namespace std;

int daysCount(vector<int> time, long long mid){
	int day = 1;
	long long chapters = 0;

	for(int i=0; i<time.size(); i++){
		
		if(chapters + time[i] <= mid){
			chapters += time[i];
		}
		else{
			day++;
			chapters = time[i];
		}
	}
	return day;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long sum = 0;
	int maxi = INT_MIN;
	
	for(int i=0; i<m; i++){
		sum += time[i];
		maxi = max(maxi, time[i]);
	}

	long long low = maxi;
	long long high = sum;

	// NOTE -- > search Space id from low to high

	while(low <= high){
		long long mid = low + (high-low)/2;
		int day = daysCount(time, mid);

		if(day <= n){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return low;
}
