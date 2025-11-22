class DisjointSet {

public:

    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the Ultimate Parent of a given node.
    int findUPar(int node){

        if(node == parent[node])
            return node;
        
        return parent[node] = findUPar(parent[node]);
    }

    // Union By Size function
    void unionBySize(int u, int v){

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int components = 0;
        int extraEdge = 0;
        DisjointSet ds(n);

        for(auto it: connections){

            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v))
                extraEdge++;
            else
                ds.unionBySize(u, v);
        }

        for(int i = 0; i < n; i++){

            if(ds.parent[i] == i)
                components++;
        }

        return (extraEdge >= (components - 1)) ? (components - 1) : -1;
    }
};