class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int prev){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int skip = solve(nums, dp, i+1, prev);
        int take = (prev==-1 || nums[prev] < nums[i]) ? 1 + solve(nums, dp, i+1, i) : 0;

        return dp[i][prev+1] = max(skip, take);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, 0, -1);
    }
};
