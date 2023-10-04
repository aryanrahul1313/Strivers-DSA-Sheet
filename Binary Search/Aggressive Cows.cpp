#include<bits/stdc++.h>

bool canWePlace(vector<int> &stalls, int k, int mid)
{
    int cows = 1;
    int lastPos = stalls[0];

    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - lastPos >= mid){
            cows++;
            lastPos = stalls[i];
        }
    }
    if(cows >= k){
        return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(canWePlace(stalls, k, mid)){
           low = mid + 1; 
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}
