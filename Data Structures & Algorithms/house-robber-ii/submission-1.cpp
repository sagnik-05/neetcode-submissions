class Solution {
public:
    int solve(vector<int>& nums, int e, int i, vector<int>& dp){
        if(i<e) return 0;
        if(i==e) return nums[i];
        if(dp[i] != -1) return dp[i];

        int skip = solve(nums, e, i-1, dp);
        int pick = nums[i] + solve(nums, e, i-2, dp);

        return dp[i] = max(pick, skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        return max(solve(nums, 0, nums.size()-2, dp1), solve(nums, 1, nums.size()-1, dp2));
    }
};
