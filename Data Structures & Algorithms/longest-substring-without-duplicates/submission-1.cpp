class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, n = s.size();
        for(int i = 0; i<n; i++){
            unordered_set<char> set;
            for(int j = i; j<n; j++){
                if(set.count(s[j])){
                    maxLen = max(j-i, maxLen);
                    break;
                }
                else{
                    set.insert(s[j]);
                }
            }
            maxLen = max(maxLen, (int)set.size());
        }
        return maxLen;
    }
};
