class Solution {
private:

    void dfs(int node, int &n, vector<vector<int>>& graph, 
            vector<int> &vec, vector<vector<int>> &ans){
        
        if(node == n-1) {
            ans.push_back(vec);
            return;
        }

        for(int nei: graph[node]) {
            vec.push_back(nei);
            dfs(nei, n, graph, vec, ans);
            vec.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> vec;
        vec.push_back(0);

        dfs(0, n, graph, vec, ans);

        return ans;
    }
};