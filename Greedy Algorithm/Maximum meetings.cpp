#include<bits/stdc++.h>

//custom comparator
static bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> meetPair;

    for(int i=0; i<n; i++){
        pair<int, int> p = make_pair(start[i], end[i]);
        meetPair.push_back(p);
    }
    //cmp is used to sort vector acc. to particular condition
    sort(meetPair.begin(), meetPair.end(), cmp);

    int endTime = meetPair[0].second;
    int meeting = 1;

    for(int i=1; i<meetPair.size(); i++){
        if(meetPair[i].first > endTime){
            meeting++;
            endTime = meetPair[i].second;
        }
    }
    return meeting;
}
