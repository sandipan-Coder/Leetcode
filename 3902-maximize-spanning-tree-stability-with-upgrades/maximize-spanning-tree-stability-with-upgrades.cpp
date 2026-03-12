class DisjointSet {
    
    public:
        vector<int> rank, parent, size;

        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findUPar(int node){
            
            // Base Case
            if(node == parent[node])
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }

        // ulp_u :- Ultimate Parent of U;
        // ulp_v :- Ultimate Parent of V;
        bool unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
                return false;
            if(rank[ulp_u] < rank[ulp_v])
                parent[ulp_u] = ulp_v;
            else if(rank[ulp_v] < rank[ulp_u])
                parent[ulp_v] = ulp_u;
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }

            return true;
        }
};


class Solution {
private:

    bool isPossible(int n, vector<vector<int>>& edges, int k, int mid) {

        DisjointSet DSU(n);

        // This store the updated stability edges.
        vector<vector<int>> upgradeCandidates;

        for(auto edge: edges) {

            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) {
                
                if(s < mid) // if stability is smaller then mid, this mid is not possible.
                    return false;
                
                DSU.unionByRank(u, v);

            } else {
                
                if(s >= mid) // if stability is already bigger then mid, not required to change the strength of an edge.
                    DSU.unionByRank(u, v);
                else if ((2 * s) >= mid) 
                    upgradeCandidates.push_back({u, v});
            }
        }

        // Try to connect all updated strength edges.
        for(auto &edge: upgradeCandidates) {

            int u = edge[0];
            int v = edge[1];

            if(DSU.findUPar(u) != DSU.findUPar(v)) {

                if(k == 0)
                    return false;
                
                DSU.unionByRank(u, v);
                k--;
            }
        }

        // Now check if all nodes has only one parent or not.
        int root = DSU.findUPar(0);
        for(int node = 1; node < n; node++) {
            if(DSU.findUPar(node) != root)
                return false;
        }

        return true;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        

        DisjointSet DSU(n);
        for(auto edge: edges) {

            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) {

                if(DSU.findUPar(u) == DSU.findUPar(v))  // If it formed cycle.
                    return -1;
                
                DSU.unionByRank(u, v);
            }
        }

        int low = 0; 
        int high = 2 * 1e5;
        // int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(n, edges, k, mid)) {
                low = mid + 1;
                // ans = mid;
            }
            else
                high = mid - 1;
        }

        return high;
    }
};