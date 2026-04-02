class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1)
            return -1;
        if(n == 1)
            return 1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        while(!pq.empty()) {

            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1)
                return dist[n-1][n-1];
            
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    
                    int nRow = row + i;
                    int nCol = col + j;

                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && 
                        grid[nRow][nCol] == 0 &&
                        cost + 1 < dist[nRow][nCol]) {
                        
                        dist[nRow][nCol] = cost + 1;
                        pq.push({dist[nRow][nCol], {nRow, nCol}});
                    }
                }
            }
        }

        return -1;
    }
};