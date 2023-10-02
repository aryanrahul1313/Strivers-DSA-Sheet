class Solution {
private:
    bool isPalindrome(string str, int s, int e){
        while(s <= e){
            if(str[s++] != str[e--]){
                return false;
            }
        }
        return true;
    }

    void solve(int index, string s, vector<string>& ds, vector<vector<string>>& ans)
    {
        //base case
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                solve(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, s, ds, ans);
        return ans;
    }
};
