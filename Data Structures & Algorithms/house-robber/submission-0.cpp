class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        int prePrev = nums[0] , prev = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++){
            int skip = prev;
            int pick = prePrev + nums[i];

            int curr = max(pick, skip);
            prePrev = prev;
            prev = curr;
        }
        return prev;
    }
};
