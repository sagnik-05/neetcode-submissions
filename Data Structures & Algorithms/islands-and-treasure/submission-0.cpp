class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int INF = INT_MAX;
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();

                for(auto d : dir){
                    int nx = d.first + x, ny = d.second + y;
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] != INF) continue;
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
