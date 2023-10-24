class Solution {
private:
    int solve(int index, int prev_index,vector<int>& nums, vector<vector<int>> &dp)
    {
        if(index == nums.size()){
            return 0;
        }

        if(dp[index][prev_index+1] != -1){
            return dp[index][prev_index+1];
        }

        //not pick
        int len = 0 + solve(index+1, prev_index, nums, dp);

        if(prev_index == -1 || nums[index] > nums[prev_index])
        {
            //pick
            len = max(len, 1 + solve(index+1, index, nums, dp));
        }

        return dp[index][prev_index+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};
