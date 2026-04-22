class Solution {
public:
    vector<string> ans;
    void solve(string& digits, vector<string>& letters, string temp, int idx){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return ;
        }
        int num = digits[idx] - '0';
        string letter = letters[num];

        for(int i = 0; i<letter.size(); i++){
            temp.push_back(letter[i]);
            solve(digits, letters, temp, idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, letters, "", 0);
        return ans;
    }
};
