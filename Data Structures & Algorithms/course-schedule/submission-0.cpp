class Solution {
public:
    bool dfs(int node, vector<vector<int>> adjList, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto adjNode : adjList[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adjList, vis, pathVis)) return true;
            }
            else if(vis[adjNode] && pathVis[adjNode]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adjList(n);
        for(auto e : pre){
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0), pathVis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis, pathVis)) return false;
            }
        }
        return true;
    }
};
