class Solution {
public:
    int solve(vector<int>& nums, int s, int e){
        int prev = 0, prePrev = 0;
        for(int i = s; i<=e; i++){
            int skip = prev;
            int pick = nums[i] + prePrev;

            int curr = max(skip, pick);
            prePrev = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, nums.size()-2), solve(nums, 1, nums.size()-1));
    }
};
