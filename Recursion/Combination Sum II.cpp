#include<bits/stdc++.h>

class Solution {
private:
    void solve(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans)
    {
        //base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, target, ds, ans);
        return ans;
    }
};
