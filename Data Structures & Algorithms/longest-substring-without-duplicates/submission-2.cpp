class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, n = s.size(), l = 0;
        unordered_set<char> set;
        for(int r = 0; r<n; r++){
            while(set.count(s[r])){
                set.erase(s[l++]);
            }
            set.insert(s[r]);
            maxLen = max(r-l+1, maxLen);
        }
        return maxLen;
    }
};
