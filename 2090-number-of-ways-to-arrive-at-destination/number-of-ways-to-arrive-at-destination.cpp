class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, 
                vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int MOD = 1e9 + 7;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {

            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto nei: adj[node]) {

                int neiNode = nei.first;
                long long wt = nei.second;

                if(cost + wt < dist[neiNode]) {
                    dist[neiNode] = cost + wt;
                    pq.push({dist[neiNode], neiNode});
                    ways[neiNode] = ways[node];
                }
                else if(cost + wt == dist[neiNode]) 
                    ways[neiNode] = (ways[neiNode] + ways[node]) % MOD;
            }
        }

        return (ways[n - 1] % MOD);
    }
};