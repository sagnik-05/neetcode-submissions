class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, prefixSum = 0;
        for(int i = 0; i<nums.size(); i++){
            prefixSum = max(nums[i]+prefixSum, nums[i]);
            maxSum = max(maxSum, prefixSum);
        }
        return maxSum;
    }
};
