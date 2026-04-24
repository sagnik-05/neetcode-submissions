class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 1;
        for(auto adjNode :adjList[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adjList, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        int comps = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                comps++;
                dfs(i, adjList, vis);
            }
        }
        return comps;
    }
};
