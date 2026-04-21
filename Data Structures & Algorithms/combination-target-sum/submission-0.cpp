class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> temp, int idx, int target){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        if(target < 0 || idx == nums.size()) return ;

        solve(nums, temp, idx+1, target);
        temp.push_back(nums[idx]);
        solve(nums, temp, idx, target-nums[idx]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(nums, temp, 0, target);
        return ans;
    }
};
