class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        int ans = INT_MAX;

        for(auto it: roads){

            int u = it[0];
            int v = it[1];
            int dis = it[2];

            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }

        queue<int> q;
        vector<bool> vis(n+1, false);

        q.push(1);
        vis[1] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto it: adj[node]) {

                int aNode = it.first;
                int dist = it.second;
                ans = min(ans, dist);

                if(!vis[aNode]){
                    q.push(aNode);
                    vis[aNode] = true;
                }
            }
        }

        return ans;
    }
};