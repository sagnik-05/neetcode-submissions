class Solution {
public:
    int n;
    int solve(string& s, int l, int r){
        int count = 0;
        while(l>=0 && r<n && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += solve(s, i, i);
            ans += solve(s, i, i+1);
        }
        return ans;
    }
};
