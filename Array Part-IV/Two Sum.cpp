class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> list;

        for (int i = 0; i<n; i++) {
            int temp = target - nums[i];
            if(list.find(temp) != list.end()){
                return {i, list[temp]};
            }
            list[nums[i]] = i;
        }  
        return {-1, -1};
    }
};
