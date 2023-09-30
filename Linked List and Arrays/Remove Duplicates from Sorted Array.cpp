class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            // No duplicates to remove for an array of size 0 or 1
            return n; 
        }
        
        int index = 0;
        for(int j=1; j<n; j++){
            if(nums[index] != nums[j]){
                nums[index+1] = nums[j];
                index++;
            }
        }
        return (index+1);
    }
};
