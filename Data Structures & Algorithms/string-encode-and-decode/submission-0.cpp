class Solution {
public:
    unordered_map<string, vector<string>> mp;
    int id = 0;
    string encode(vector<string>& strs) {
        id++;
        string key = to_string(id);
        mp[key] = strs;
        return key;
    }

    vector<string> decode(string s) {
        return mp[s];
    }
};
