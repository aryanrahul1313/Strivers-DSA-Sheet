class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long it = n;
        if(n < 0){
            it = -1 * it;
        }

        while(it){
            if(it & 1){
                ans = ans * x;
                it--;
            }
            else{
                x = x * x;
                it = it/2;
            }
        }
        if(n<0){
            return (double)(1.0)/(double)(ans);
        }
        return ans;
    }
};
