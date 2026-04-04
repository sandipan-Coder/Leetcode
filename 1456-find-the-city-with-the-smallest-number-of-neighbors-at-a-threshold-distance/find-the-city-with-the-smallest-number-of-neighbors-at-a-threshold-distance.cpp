class Solution {
private:

    int dijkstra_algo(int src, vector<pair<int, int>> adj[], int &n, 
            int &distanceThreshold) {

        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int node = it.second;

            for(auto nei: adj[node]) {
                int neiNode = nei.first;
                int wt = nei.second;

                if(cost + wt < dist[neiNode]) {
                    dist[neiNode] = cost + wt;
                    pq.push({dist[neiNode], neiNode});
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {

            if(i == src)
                continue;

            if(dist[i] <= distanceThreshold)
                count++;
        }

        return count;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<pair<int, int>> adj[n];
        for(auto it: edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int countCity = n+1;
        int city = -1;

        for(int i = 0; i < n; i++) {
            
            int count = dijkstra_algo(i, adj, n, distanceThreshold);

            if(count <= countCity) {
                countCity = count;
                city = i;
            }
        }

        return city;
    }
};