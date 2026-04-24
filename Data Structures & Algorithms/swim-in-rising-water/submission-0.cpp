class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> efforts(n, vector<int>(n, 1e9));
        using pii = pair<int, pair<int,int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({grid[0][0], {0,0}});
        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        efforts[0][0] = grid[0][0];
        while(!pq.empty()){
            int currEffort = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==n-1) return currEffort;
            for(auto d : dir){
                int nx = x+d.first, ny = y+d.second;
                if(nx<0 || ny<0 || nx==n || ny==n) continue;
                int nextEffort = max(currEffort ,grid[nx][ny]);

                if(nextEffort < efforts[nx][ny]){
                    pq.push({nextEffort, {nx, ny}});
                    efforts[nx][ny] = nextEffort;
                }
            }
        }
        return -1;
                                                                                                                                                                                                                                                                                                                                                                                                                    
    }
};
