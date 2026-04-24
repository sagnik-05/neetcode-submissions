class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& vis, int parent){
        vis[node] = 1;
        for(auto adjNode : adjList[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adjList, vis, node)) return true;
            }
            else if(vis[adjNode] && adjNode!=parent) return true;
        }

        return false;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            int u = e[0]-1, v = e[1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            vector<int> vis(n, 0);
            if(dfs(u, adjList, vis, -1)) return {e[0], e[1]};

        }
        return {-1,-1};
    }
};
