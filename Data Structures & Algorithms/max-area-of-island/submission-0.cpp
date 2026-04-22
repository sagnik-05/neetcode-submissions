class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid, int i, int j, int& area){
        if(i<0 || j<0 || i>=n || j>=m || !grid[i][j]) return ;
        area++;
        grid[i][j] = 0;
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
