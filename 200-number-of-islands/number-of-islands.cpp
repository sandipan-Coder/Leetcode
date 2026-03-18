class Solution {
    int n, m;
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
private:

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis){

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()) {

            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            
            for(int i = 0; i < 4; i++) {

                int nRow = r + dir[i][0];
                int nCol = c + dir[i][1];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                    grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                    
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = true;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {

                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};