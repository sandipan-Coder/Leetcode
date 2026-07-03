class Solution {
private:

    bool dijkstra(long long &mid, int src, int target, long long &k, vector<vector<pair<int,int>>> &adj) {

        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        // min heap: distance, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()){

            // pop from priority queue
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) 
                continue;

            if(node == target)  
                return true;
    
            for(auto& [v, w]: adj[node]){  

                if(w < mid) 
                    continue;           

                int new_dist_v = d + w;

                if(new_dist_v > k) 
                    continue;    
                if(new_dist_v < dist[v]){       
                    dist[v] = d + w;            
                    pq.push({dist[v], v});      
                }
            }
        }
        
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int max_dist = 0;

        for(auto it: edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(online[u] && online[v]) {
                adj[u].push_back({v, wt});
                max_dist = max(max_dist, wt);
            }
        }

        long long low = 0;
        long long high = max_dist;

        while(low <= high){

            long long mid = low + (high - low) / 2;

            if(dijkstra(mid, 0, n-1, k, adj))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};