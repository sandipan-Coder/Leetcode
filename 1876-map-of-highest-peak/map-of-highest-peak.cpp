class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> height(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(isWater[i][j]) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            height[row][col] = dist;

            for(int i = 0; i < 4; i++) {

                int nRow = row + dir[i][0];
                int nCol = col + dir[i][1];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]) {

                    q.push({{nRow, nCol}, dist + 1});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return height;
    }
};