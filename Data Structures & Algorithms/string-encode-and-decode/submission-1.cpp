class Solution {
public:
    unordered_map<string, vector<string>> mp;
    string getRandomString(){
        string nums = "0123456789";
        string chars = "abcdefghijklmnopqrstuvwxyz";
        string res = "";
        for(int i = 0; i<2; i++){
            int idx = rand() % 10;
            res += nums[idx];
        }
        for(int i = 0; i<4; i++){
            int idx = rand() % 26;
            res += chars[idx];
        }
        random_shuffle(res.begin(), res.end());
        return res;
    }
    string encode(vector<string>& strs) {
        string id = getRandomString();
        mp[id] = strs;
        return id;
    }

    vector<string> decode(string s) {
        return mp[s];
    }
};
