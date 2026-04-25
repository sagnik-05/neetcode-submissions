class Solution {
public:
    int solve(string&t1, string& t2, vector<vector<int>>& dp, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j]) return dp[i][j] = 1 + solve(t1, t2, dp, i-1, j-1);

        return dp[i][j] = max(solve(t1, t2, dp, i, j-1) , solve(t1, t2, dp, i-1, j));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(t1, t2, dp, n-1, m-1);
    }
};
