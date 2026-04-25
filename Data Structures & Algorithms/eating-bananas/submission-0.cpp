class Solution {
public:
    bool canEat(vector<int>& piles, int h, int rate){
        int ans = 0;
        for(int i= 0; i<piles.size(); i++){
            ans += ceil((double)piles[i]/(double)rate);
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l = 1, h = *max_element(piles.begin(), piles.end()), ans = -1;
        while( l <= h){
            int mid = (l+h)/2;
            if(canEat(piles, hr, mid)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
