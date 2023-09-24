#include<bits/stdc++.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> visited;

        for(int i=0; i<n+1; i++){
            if(visited[nums[i]]){
                return nums[i];
            }
            else{
                visited[nums[i]] = true;
            }
        }
        return -1;
    }
};
