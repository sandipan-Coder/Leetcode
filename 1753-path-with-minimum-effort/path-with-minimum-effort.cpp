class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> pq;
            
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1)
                return dis;
            
            for(int i = 0; i < 4; i++) {

                int nRow = row + dir[i][0];
                int nCol = col + dir[i][1];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {

                    int nDis = max(abs(heights[nRow][nCol] - heights[row][col]), dis);

                    if(nDis < dist[nRow][nCol]) {
                        dist[nRow][nCol] = nDis;
                        pq.push({nDis, {nRow, nCol}});
                    }
                }
            }
        }
        
        return 0;
    }
};