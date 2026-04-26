class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, vector<vector<int>>& dp, int i, int j, int idx){
        if(idx == s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        bool takeFromS1 = 0, takeFromS2 = 0;
        if(i<s1.size() && s1[i] == s3[idx]){
            takeFromS1 = solve(s1, s2, s3, dp, i+1, j, idx+1);
        }
        if(j<s2.size() && s2[j] == s3[idx]){
            takeFromS2 = solve(s1, s2, s3, dp, i, j+1, idx+1);
        }
        return dp[i][j] = takeFromS1 || takeFromS2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size()) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, s3, dp, 0, 0, 0);
    }
};
