class Solution {
public:
    int solve(string& s, int i, vector<int>& dp){
        if(i<0) return 1;
        if(s[i]=='0'){
            if(s[i-1]=='1' || s[i-1]=='2') return solve(s, i-2, dp);
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int take1 = solve(s, i-1, dp);
        int take2 = 0;
        if(i>0){
            int digit = (s[i-1]-'0')*10 + (s[i]-'0');
            if(digit>=10 && digit<=26){
                take2 = solve(s, i-2, dp);
            }
        }
        return dp[i] = take1 + take2;
    }
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, n-1, dp);
    }
};
