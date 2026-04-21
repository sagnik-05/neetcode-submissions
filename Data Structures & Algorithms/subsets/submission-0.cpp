class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> temp, int idx, int n){
        if(idx == n){
            ans.push_back(temp);
            return ;
        }
        solve(nums, temp, idx+1, n);
        temp.push_back(nums[idx]);
        solve(nums, temp, idx+1, n);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0, nums.size());
        return ans;
    }
};
