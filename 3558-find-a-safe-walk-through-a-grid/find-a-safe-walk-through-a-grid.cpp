class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        if(grid[0][0] == 1 && health == 1)
            return false;

        int n = grid.size();
        int m = grid[0].size();

        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> Best(n, vector<int>(m, 0));

        int newHealth = health - grid[0][0];
        q.push({newHealth, {0, 0}});
        Best[0][0] = newHealth;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int energy = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1 && energy > 0)
                return true;
            
            for(auto d: dir) {

                int nRow = row + d[0];
                int nCol = col + d[1];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){

                    int ne = energy - grid[nRow][nCol];
                    
                    if(ne <= 0) 
                        continue;
                    else if(ne > 0 && ne > Best[nRow][nCol]) {
                        Best[nRow][nCol] = ne;
                        q.push({ne, {nRow, nCol}});
                    }
                }
            }
        }

        return false;
    }
};