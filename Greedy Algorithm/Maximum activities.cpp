#include<bits/stdc++.h>

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> activity;
    int n = start.size();
    for(int i=0; i<n; i++){
        pair<int, int> p = make_pair(start[i], finish[i]);
        activity.push_back(p);
    }

    sort(activity.begin(), activity.end(), cmp);

    int cnt = 1;
    int last = activity[0].second;

    for(int i=1; i<n; i++){
        if(activity[i].first >= last){
            cnt++;
            last = activity[i].second;
        }
    }
    return cnt;
}
