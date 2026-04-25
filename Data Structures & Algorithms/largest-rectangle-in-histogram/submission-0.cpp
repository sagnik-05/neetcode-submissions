class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        for(int i = 0; i<n; i++){
            int h = heights[i];

            int right = i+1;
            int left = i;

            while(right<n && heights[right] >= h){
                right++;
            }
            while(left>=0 && heights[left] >= h){
                left--;
            }

            right--;
            left++;

            maxArea = max(maxArea, h * (right-left+1));
        }
        return maxArea;
    }
};
