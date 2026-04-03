class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);

        for(auto it: flights)
            adj[it[0]].push_back({it[1], it[2]});
        
        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)
                continue;
            
            for(auto nei: adj[node]) {
                int neiNode = nei.first;
                int wt = nei.second;

                if(cost + wt < dist[neiNode] && stops <= k) {
                    dist[neiNode] = cost + wt;
                    q.push({stops + 1, {neiNode, dist[neiNode]}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};