class Solution {

    int n, m;
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
private:

    int bfs(vector<vector<int>> &mat, queue<pair<int, int>> &q) {

        int time = 0;

        while(!q.empty()) {

            int size = q.size();
            time++;

            for(int i = 0; i < size; i++) {

                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                for(int j = 0; j < 4; j++) {

                    int nRow = row + dir[j][0];
                    int nCol = col + dir[j][1];

                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                        mat[nRow][nCol] == 1) {
                        
                        q.push({nRow, nCol});
                        mat[nRow][nCol] = 2;
                    }
                }
            }
        }

        return (time -1);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> mat = grid;
        queue<pair<int, int>> q;
        bool isOne = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2)
                    q.push({i, j});
                
                if(!isOne && grid[i][j] == 1)
                    isOne = true;
            }
        }

        if(q.empty())
            return (isOne) ? -1 : 0;
        
        int timer = bfs(mat, q);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 1)
                    return -1;
            }
        }

        return timer;
    }
};