class Solution {
public:
    unordered_set<int> diag1, diag2, row;
    vector<vector<string>> ans;
    void solve(vector<string>& board, int c, int n){
        if(c >= n){
            ans.push_back(board);
            return ;
        }

        for(int r = 0; r<n; r++){
            if(row.count(r) || diag1.count(r-c) || diag2.count(r+c)) continue;

            board[r][c] = 'Q';
            row.insert(r);
            diag1.insert(r-c);
            diag2.insert(r+c);

            solve(board, c+1, n);

            board[r][c] = '.';
            row.erase(r);
            diag1.erase(r-c);
            diag2.erase(r+c);

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};