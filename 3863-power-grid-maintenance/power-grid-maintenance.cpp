class Solution {
private:

    void dfs(int id, int node, vector<vector<int>> &adj, vector<int> &vis, map<int, set<int>> &mp, map<int, int> &mpp){

        vis[node] = 1;
        mpp[node] = id;
        mp[id].insert(node);

        for(auto it: adj[node]){
            if(!vis[it])
                dfs(id, it, adj, vis, mp, mpp);
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<vector<int>> adj(c);
        vector<int> vis(c, 0);
        vector<int> online(c, 1);
        map<int, set<int>> mp;
        map<int, int> mpp;
        vector<int> ans;

        for(auto it: connections){
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }

        int id = 0;
        for(int i = 0; i < c; i++){
            if(!vis[i])
                dfs(id, i, adj, vis, mp, mpp);
            id++;
        }

        for(auto &q: queries){

            int type = q[0];
            int station = q[1] - 1;
            int powerId = mpp[station];

            if(type == 2){
                mp[powerId].erase(station);
                online[station] = 0;
            }
            else{
                if(online[station])
                    ans.push_back(station + 1);
                else if(mp[powerId].size() > 0)
                    ans.push_back(*mp[powerId].begin() + 1);
                else
                    ans.push_back(-1);
            }
        }

        return ans;
    }
};