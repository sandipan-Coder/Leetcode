class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        int ans = INT_MAX;

        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < n; i++){

            vector<int> parent(n, -1);
            vector<int> dist(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(int neighbour: adj[node]){

                    if(dist[neighbour] == -1){
                        dist[neighbour] = dist[node] + 1;
                        parent[neighbour] = node;
                        q.push(neighbour);
                    }
                    else if(parent[node] != neighbour)
                        ans = min(ans, dist[node] + dist[neighbour] + 1);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};