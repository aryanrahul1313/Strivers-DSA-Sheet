class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1){
            return 0;
        }

        int left = 0;
        int leftMax = 0;
        int right = n-1;
        int rightMax = 0;
        int unit = 0;

        while(left <= right){
            if(height[left] <= height[right]){

                if(height[left] >= leftMax){
                    leftMax = height[left];
                }
                else{
                    unit += leftMax - height[left];
                }
                left++;
            }
            else{ //right value > left value
            
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }
                else{
                    unit += rightMax - height[right];
                }
                right--;
            }
        }
        return unit;
    }
};
