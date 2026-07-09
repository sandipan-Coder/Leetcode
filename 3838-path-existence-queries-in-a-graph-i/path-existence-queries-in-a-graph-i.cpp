class DisjointSet {
    
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++){
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

        // Union By Size
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
                return;
            if(size[ulp_u] < size[ulp_v]){
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int> component(n, 0);
        int compNo = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff)
                compNo++;
            
            component[i] = compNo;
        }
        
        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(component[it[0]] == component[it[1]]);
        }

        return sol;
    }
};