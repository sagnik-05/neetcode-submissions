class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string&s , int l, int r){
        while(l<=r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void solve(string& s, vector<string>& temp, int idx){
        if(idx == s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int len = idx; len<s.size(); len++){
            if(isPal(s, idx, len)){
                temp.push_back(s.substr(idx, len-idx+1));
                solve(s, temp, len+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0);
        return ans;
    }
};
