class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            if(grid[i][m - 1] >= 0) 
                continue;
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] < 0){
                    count += (m - j);
                    break;
                }
            }
        }

        return count;
    }
};