class Solution {
public:
    int solve(vector<int>& nums, int s, int e){
        int n = e-s+1;
        vector<int> dp(n);
        dp[0] = nums[s];
        if(n>1) dp[1] = max(nums[s], nums[s+1]);
        for(int i = 2; i<n; i++){
            int skip = dp[i-1];
            int pick = nums[s+i] + dp[i-2];

            dp[i] = max(skip, pick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, nums.size()-2), solve(nums, 1, nums.size()-1));
    }
};
