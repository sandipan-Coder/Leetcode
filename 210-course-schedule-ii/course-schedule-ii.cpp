class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        if(q.empty())
            return {};

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int nei: adj[node]) {
                indegree[nei]--;

                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        if(ans.size() == numCourses)
            return ans;
        
        return {};
    }
};