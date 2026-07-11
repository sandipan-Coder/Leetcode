class Solution {
private:
    void dfs(int node, int &nodeCnt, int &degreeCnt, vector<int> &vis, vector<vector<int>> &adj){

        vis[node] = 1;
        nodeCnt++;
        degreeCnt += adj[node].size();

        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it, nodeCnt, degreeCnt, vis, adj);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        if(edges.size() == 0)
            return n;
        if(edges.size() == 1)
            return n-1;

        vector<vector<int>> adj(n);

        for(auto it : edges){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            
            int nodeCnt = 0;
            int degreeCnt = 0;
            if(!vis[i]){
                dfs(i, nodeCnt, degreeCnt, vis, adj);
                int calc = nodeCnt * (nodeCnt - 1);

                if(calc == degreeCnt)
                    ans++;
            }
        }

        return ans;
    }
};