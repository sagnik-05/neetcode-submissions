class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int t){
        if(i<0) return t==0;
        if(dp[i][t] != -1) return dp[i][t];

        int skip = solve(nums, dp, i-1, t);
        int pick = nums[i]<=t ? solve(nums, dp, i-1, t-nums[i]) : 0;

        return dp[i][t] = skip + pick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if((target+sum)%2) return 0;
        if(target > sum) return 0;
        int newTarget = (target + sum)/2;
        vector<vector<int>> dp(n, vector<int>(newTarget+1, -1));
        return solve(nums, dp, n-1, newTarget);

    }
};
