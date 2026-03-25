class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> horizonSum(n, 0);
        vector<long long> verticalSum(m, 0);

        // Horizontal sum calculation
        for(int i = 0; i < n; i++) {

            long long total_h_sum = 0;

            for(int j = 0; j < m; j++) 
                total_h_sum += grid[i][j];
            
            if(i > 0)
               horizonSum[i] = horizonSum[i - 1];
            
            horizonSum[i] += total_h_sum;
        }

        // Vertical sum calculation
        for(int j = 0; j < m; j++) {

            long long total_v_sum = 0;

            for(int i = 0; i < n; i++) 
                total_v_sum += grid[i][j];
            
            if(j > 0)
               verticalSum[j] = verticalSum[j - 1];
            
            verticalSum[j] += total_v_sum;
        }

        // Check for horizontal cut
        for(int i = 0; i < n-1; i++) {

            long long remaining = horizonSum[n - 1] - horizonSum[i];
            if(horizonSum[i] == remaining)
                return true;
        }

        // Check for vertical cut
        for(int i = 0; i < m-1; i++) {

            long long remaining = verticalSum[m - 1] - verticalSum[i];
            if(verticalSum[i] == remaining)
                return true;
        }

        return false;
    }
};