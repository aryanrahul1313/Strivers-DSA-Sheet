class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;
        //finding break point
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        //find greater than index value but minimum
        for(int i=n-1; i>index && index!=-1; i--){  //index!=-1 edge case
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        reverse(nums.begin() + index + 1, nums.end()); 
    }
};
