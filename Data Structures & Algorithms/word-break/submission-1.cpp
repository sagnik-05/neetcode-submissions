class Solution {
public:
    bool solve(string& s, unordered_set<string>& dict, vector<int>& dp, int i){
        if(i==s.size()) return true;
        if(dp[i] != -1) return dp[i];

        for(int len = i; len<s.size(); len++){
            string word = s.substr(i, len-i+1);
            if(dict.count(word)){
                if(solve(s, dict, dp, len+1)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, dict, dp, 0);
    }
};
