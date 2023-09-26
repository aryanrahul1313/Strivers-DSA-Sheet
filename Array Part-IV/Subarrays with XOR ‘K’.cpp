#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b)
{
    int n = a.size();
    int xr = 0;
    unordered_map<int, int> mpp;
    int cnt = 0;
    mpp[xr]++;  //{0,1} is inserted in map
    for(int i=0; i<n ;i++){
        xr = xr ^ a[i];
        //for k
        int x = xr ^ b;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
