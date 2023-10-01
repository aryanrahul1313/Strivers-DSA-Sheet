vector<int> MinimumCoins(int n)
{
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;

    for(int i=8; i>=0; i--){
        int num = arr[i];
        if(num <= n){
            int q = n/num;
            n = n - q*num;
            while(q--){
                ans.push_back(num);
            }
        }
    }
    return ans;
}
