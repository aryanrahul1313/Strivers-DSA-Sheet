#include<bits/stdc++.h>
static bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[2] > b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
   //sort the vector acc. to max profit
   sort(jobs.begin(), jobs.end(), cmp);

    //finding the maximum deadline
    int maxi = 0; 
    for(int i = 0; i < jobs.size(); i++){
        maxi = max(maxi, jobs[i][1]);
    }

    // we are using 1 based indexing that's why maxi+1 is done
    vector<int> visited(maxi+1, -1); 

    int count = 0;
    int maxProfit = 0;
    for(int i=0; i<jobs.size(); i++){
        int id = jobs[i][0];
        int deadline = jobs[i][1];
        int profit = jobs[i][2];

        for(int k=deadline; k>0; k--){
            if(visited[k] == -1){
                visited[k] = id;
                maxProfit += profit;
                count++;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);

    return ans;
}
