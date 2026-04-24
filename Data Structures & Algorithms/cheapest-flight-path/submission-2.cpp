class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto e : flights){
            adjList[e[0]].push_back({e[1], e[2]});
        }

        // {cost, {stops, node}}
        using pii = pair<int, pair<int,int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, {0, src}});

        // Instead of dist[node][stops], we track best (minimum) stops used to reach node
        vector<int> bestStops(n, 1e9);

        while(!pq.empty()){
            int currCost = pq.top().first;
            int stops = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(node == dst) return currCost;

            if(stops > k) continue;

            // pruning: if we've already reached this node with fewer stops, skip
            if(stops > bestStops[node]) continue;
            bestStops[node] = stops;

            for(auto it : adjList[node]){
                int nextNode = it.first;
                int nextCost = currCost + it.second;

                pq.push({nextCost, {stops+1, nextNode}});
            }
        }
        return -1;
    }
};