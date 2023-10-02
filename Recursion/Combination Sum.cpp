class Solution {
private:
    void solve(int index, vector<int>& candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        //base case
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        //pick
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            solve(index, candidates, target-candidates[index], ds, ans);
            ds.pop_back();
        }

        //not pick
        solve(index+1, candidates, target, ds, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, target, ds, ans);
        return ans;
    }
};
