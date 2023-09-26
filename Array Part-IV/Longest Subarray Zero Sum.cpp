#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr)
{
  int n = arr.size();
  int len = 0;
  
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
      sum += arr[j];
      if(sum == 0){
        len = max(len, j-i+1);
      }
    }
  }
  return len;
}
