class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 1;
        for(auto adjNode : adjList[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, node, adjList, vis)) return true;
            }
            else if(vis[adjNode] && parent != adjNode) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        if(dfs(0, -1, adjList, vis)) return false;
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
