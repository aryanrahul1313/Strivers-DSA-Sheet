class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int prev = INT_MIN;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == prev){
                cnt += 1;
                prev = nums[i];
            }  
            else if(nums[i] != prev){
                cnt = 1;
                prev = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
