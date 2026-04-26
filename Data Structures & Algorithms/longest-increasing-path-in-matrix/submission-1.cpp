class Solution {
public:
    int n, m;
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        int path = 1;
        for(auto d : dir){
            int ni = d.first + i, nj = d.second + j;
            if(ni<0 || nj<0 || ni>=n || nj>=m || matrix[ni][nj] <= matrix[i][j]) continue;
            path = max(path, 1 + dfs(matrix, ni, nj, dp));
        }
        return dp[i][j] = path;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxPath = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int pathLen = dfs(matrix, i, j, dp);
                maxPath = max(maxPath, pathLen);
            }
        }
        return maxPath;
    }
};
