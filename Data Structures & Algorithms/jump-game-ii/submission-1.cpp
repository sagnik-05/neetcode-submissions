class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1, maxReachEnd = 0, maxJump = 0, jumps = 0;
        for(int i = 0; i<n-1; i++){
            maxJump = max(i+nums[i], maxJump);
            if(i==maxReachEnd){
                jumps++;
                maxReachEnd = maxJump;
            }
        }
        return maxReachEnd>=goal ? jumps : -1;
    }
};
