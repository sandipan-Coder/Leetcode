class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);

        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2*it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {

            int distance = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(node == n-1)
                return distance;
            
            if(distance > dist[node])
                continue;
            
            for(auto it: adj[node]) {

                int adjNode = it.first;
                int weight = it.second;

                if(distance + weight < dist[adjNode]) {
                    dist[adjNode] = distance + weight;
                    pq.push({(distance + weight), adjNode});
                }
            }
        }

        return -1;
    }
};