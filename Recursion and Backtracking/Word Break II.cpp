#include <bits/stdc++.h> 

void helper(int index, string word, string &s, vector<string> &ans, 
                unordered_map<string, int> mpp)
{
    //base case
    if(index == s.size()){
        ans.push_back(word);
        return;
    }

    for(int i=index; i<s.size(); i++){
        string temp = s.substr(index, i-index+1);
        if(mpp[temp] >= 1){
            int n = word.size();
            word += temp + " ";
            helper(i+1, word, s, ans, mpp);
            word.erase(n);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    unordered_map<string, int> mpp;

    for(int i=0; i<dictionary.size(); i++){
        mpp[dictionary[i]]++;
    }

    helper(0, "", s, ans, mpp);
    return ans;
}
