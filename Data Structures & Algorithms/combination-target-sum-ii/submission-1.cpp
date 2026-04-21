class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> temp, int idx, int target){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        if(target < 0 || idx == nums.size()) return ;

        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i+1, target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, temp, 0, target);
        return ans;
    }
};
