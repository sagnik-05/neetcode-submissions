class Solution {
public:
    int n, m;
    bool solve(vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int i, int j, int idx){
        if(idx == word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || idx>=word.size() || board[i][j]!=word[idx]) return false;

        vis[i][j] = 1;
        bool check = solve(board, vis, word, i+1, j, idx+1) || solve(board, vis, word, i-1, j, idx+1)
                     || solve(board, vis, word, i, j+1, idx+1) || solve(board, vis, word, i, j-1, idx+1);
        vis[i][j] = 0;
        
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(solve(board, vis, word, i, j, 0)) return true;
                }
            }
        }
        return false;
        
    }
};
