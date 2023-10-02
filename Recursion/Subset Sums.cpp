class Solution
{
public:
    void solve(int index, int sum, vector<int>& arr, int N, vector<int>& subSets)
    {
        //base case
        if(index == N){
            subSets.push_back(sum);
            return;
        }
        
        //pick the element
        solve(index+1, sum + arr[index], arr, N, subSets);
        
        //not pick the element
        solve(index+1, sum, arr, N, subSets);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subSets;
        solve(0, 0, arr, N, subSets);
        
        //sort the vector
        sort(subSets.begin(), subSets.end());
        
        return subSets;
    }
};
