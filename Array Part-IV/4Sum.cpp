class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){   // to avoid duplicates 
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j != i+1 && nums[j] == nums[j-1]){  // to avoid duplicates
                    continue;
                }

                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++, l--;
                        // to avoid duplicates
                        while(k<l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k<l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
