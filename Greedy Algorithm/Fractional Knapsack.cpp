#include <bits/stdc++.h> 

static bool cmp(pair<double, pair<int,int>> a, pair<double, pair<int,int>> b)
{
    return a.first > b.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    //sorting the items acc. to (val/weight).
    vector<pair<double, pair<int, int>>> arr;
    for(int i=0; i<n; i++){
        double perUnit = (1.0)*(items[i].second)/(items[i].first);
        int w = items[i].first;
        int v = items[i].second;
        pair<int, int> p1 = make_pair(w,v);
        pair<double, pair<int,int>> p2 = make_pair(perUnit, p1);
        arr.push_back(p2);
    }
    sort(arr.begin(), arr.end(), cmp);
    
    double knapsack = 0;
    for(int i=0; i<n; i++){
        if(arr[i].second.first > w){
            //fraction weight le skta hu
            knapsack += w * arr[i].first;
            w = 0;
        }
        else{
            //pura weight le skta hu
            knapsack += arr[i].second.second;
            w = w - arr[i].second.first;
        }
    }
    return knapsack;
}
