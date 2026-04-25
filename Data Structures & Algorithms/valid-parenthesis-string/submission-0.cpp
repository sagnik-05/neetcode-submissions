class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), maxi = 0, mini = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                maxi++;
                mini++;
            }
            else if(s[i] == ')'){
                maxi--;
                mini--;
            }
            else if(s[i] == '*'){
                maxi += 1;
                mini -= 1;
            }
            if(maxi<0) return false;
            if(mini<0) mini = 0;

        }
        return maxi==0 || mini==0;
    }
};
