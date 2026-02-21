class Solution {

    vector<vector<int>> dirct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> que;
        bool vis[41][41][1601];
        memset(vis, false, sizeof(vis));
        int steps = 0;

        que.push({0, 0, k});
        vis[0][0][k] = true;

        while(!que.empty()) {
            
            int size = que.size();

            while(size--) {

                vector<int> temp = que.front();
                que.pop();

                int curr_i = temp[0];
                int curr_j = temp[1];
                int obs    = temp[2];

                if(curr_i == n-1 && curr_j == m-1)
                    return steps;
                
                for(vector<int> &dir: dirct) {

                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                        continue;
                    
                    if(grid[new_i][new_j] == 0 && !vis[new_i][new_j][obs]) {
                        que.push({new_i, new_j, obs});
                        vis[new_i][new_j][obs] = true;
                    }
                    else if(grid[new_i][new_j] == 1 && obs > 0 
                            && !vis[new_i][new_j][obs - 1])  {
                                
                        que.push({new_i, new_j, obs - 1});
                        vis[new_i][new_j][obs - 1] = true;
                    }
                }
            }
            
            steps++;
        }

        return -1;
    }
};