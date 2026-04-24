class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto e : times){
            int u = e[0]-1, v = e[1]-1, w = e[2];
            adjList[u].push_back({v, w});
        }
        using pii = pair<int,int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k-1});
        vector<int> dist(n, 1e9);
        dist[k-1] = 0;
        while(!pq.empty()){
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adjNode : adjList[node]){
                int nextDist = currDist + adjNode.second, nextNode = adjNode.first;
                if(nextDist < dist[nextNode]){
                    dist[nextNode] = nextDist;
                    pq.push({nextDist, nextNode});
                }
            }
        }
        int maxTime = 0;
        for(auto i : dist){
            if(i==1e9) return -1;
            cout<<i<<"  ";
            maxTime = max(maxTime, i);
        }
        return maxTime;
    }
};
