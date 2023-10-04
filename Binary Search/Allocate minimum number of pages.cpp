//User function template in C++

class Solution 
{
    private:
    bool allocationPossible(int barrier, int A[], int N, int M){
        int student = 1;
        int pgsum = 0;
        
        for(int i=0; i<N; i++){
            if(barrier < A[i]){
                return false;
            }
            
            if(pgsum + A[i] <= barrier){
                pgsum += A[i];
            }
            else{
                student++;
                pgsum = A[i];
            }
        }
        
        if(student > M){
            return false;
        }
        
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N){
            return -1;
        }
        
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        
        int low = A[0];
        int high = sum;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(allocationPossible(mid, A, N, M)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        return low;
    }
};
