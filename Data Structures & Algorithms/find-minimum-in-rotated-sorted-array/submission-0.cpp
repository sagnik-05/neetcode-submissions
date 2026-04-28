class Solution {
public:
    int getPivot(vector<int> &nums){
        int s = 0, e = nums.size()-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e]) s = mid+1;
            else e = mid;
        }
        return e;
    }
    int findMin(vector<int> &nums) {
        int pivot = getPivot(nums);
        cout<<pivot<<endl;
        return min(nums[0], nums[pivot]);
    }
};
