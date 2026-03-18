class Solution {
private:

    void bfs(int node, vector<int> adj[], vector<bool> &vis) {

        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()) {

            int Node = q.front();
            q.pop();

            for(auto it: adj[Node]) {

                if(!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n];
        vector<bool> vis(n, false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i == j)
                    continue;
                
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {
                bfs(i, adj, vis);
                count++;
            }
        }
        
        return count;
    }
};