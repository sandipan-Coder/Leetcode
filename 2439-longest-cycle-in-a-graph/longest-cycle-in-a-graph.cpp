class Solution {

    int ans = -1;

private:

    void DFS(int node, vector<int>& edges, unordered_map<int, int> &dist, vector<int> &vis){

        vis[node] = 1;
        int neighbour = edges[node];

        if(neighbour != -1 && !vis[neighbour]){
            dist[neighbour] = dist[node] + 1;
            DFS(neighbour, edges, dist, vis);
        }
        else if(neighbour != -1 && dist.count(neighbour))
            ans = max(ans, dist[node] - dist[neighbour] + 1);
    }

public:
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){

            if(!vis[i]){
                unordered_map<int, int> dist;
                dist[i] = 1;

                DFS(i, edges, dist, vis);
            }
        }

        return ans;
    }
};