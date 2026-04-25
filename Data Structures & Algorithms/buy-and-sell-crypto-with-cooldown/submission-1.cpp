class Solution {
public:
    int solve(vector<int>& prices, vector<vector<int>>& dp, int i, int f, int n){
        if(i>=n) return 0;
        if(dp[i][f] != -1) return dp[i][f];

        // buy
        if(f%2 == 0){
            int skip = solve(prices, dp, i+1, 0, n);
            int buy = -prices[i] + solve(prices, dp, i+1, 1, n);
            return dp[i][f] = max(skip, buy);
        }
        // sell 
        int skip = solve(prices, dp, i+1, 1, n);
        int sell = prices[i] + solve(prices, dp, i+2, 0, n);
        return dp[i][f] = max(skip, sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, dp, 0, 0, n);
    }
};
